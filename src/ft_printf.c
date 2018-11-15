/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:22:59 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/15 21:52:55 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/handle.h"

void		handle_null(char *s, int nu, char *cut)
{
	int		i;
	int		len;

	i = -1;
	write(1, g_buff, g_i);
	g_ret += g_i;
	g_i = 0;
	len = ft_strlen(s);
	if (nu)
	{
		while (s[++i] != '|' && i < len)
			;
		s[i] = 0;
	}
	else
	{
		s = ft_strjoin(cut, s);
		len = ft_strlen(s);
	}
	write(1, s, len);
	g_ret += len;
	ft_memset(g_buff, 0, BUFF_SIZE);
}

int			buff_is_null(char *s)
{
	while (*s)
	{
		if (*s != 48 && *s != ' ')
			return (0);
		s++;
	}
	return (1);
}

static void	handle_flag(char *s, t_param *arg, char *cut)
{
	int		len;

	len = (int)ft_strlen(s);
	s = handle_precision(arg, s, len);
	len = (int)ft_strlen(s);
	s = handle_width(arg, s, len);
	s = handle_plus_space(arg, s, len);
	if (!buff_is_null(s) || arg->f == 'p')
		s = handle_hash(arg, s, len);
	handle_null(s, arg->null, cut);
}

int			handler(char *f, va_list ap, char *cut)
{
	int		i;
	char	*s;
	t_param	arg;

	init_arg(&arg);
	parse_flags(f, &arg, ap);
	f = skip_flags(f);
	if (*f)
	{
		if (is_fspec(*f))
			s = convert_arg(f, ap, &arg, get_base(*f));
		else
			s = new_fspec(&arg, *f);
		if (arg.err)
			return (0);
		handle_flag(s, &arg, cut);
		if ((i = get_next_spec(++f)) > BUFF_SIZE - g_i)
		{
			write(1, f, i);
			return (handler(f + i + 1, ap, ""));
		}
		if (buff_cpy(f, i, ap) == 0)
			return (0);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	char	*f;
	va_list	ap;

	g_ret = 0;
	if (!format || !*format)
		return (0);
	f = (char *)format;
	va_start(ap, format);
	if ((j = direct_print(f, &i)))
		return (j);
	buff_init(f, i);
	if (!handler(f + i + 1, ap, ""))
	{
		write(1, g_buff, g_i);
		return (-1);
	}
	va_end(ap);
	write(1, g_buff, g_i);
	g_ret += g_i;
	return (g_ret);
}
