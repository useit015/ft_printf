/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:22:59 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/12 01:08:25 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		handle_null(char *s)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(g_buff);
	g_i = 0;
	write(1, g_buff, len);
	g_ret += len;
	len = ft_strlen(s);
	while (s[++i] != '|' && i < len)
		;
	s[i] = 0;
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
	if (arg->null)
		handle_null(s);
	else
	{
		s = ft_strjoin(cut, s);
		ft_strcat(g_buff, s);
		free(s);
	}
}

int			handler(char *f, va_list ap, char *cut)
{
	int		i;
	char	*s;
	t_param	arg;

	init_arg(&arg);
	parse_flags(f, &arg);
	while (*f && is_flag(*f))
		f++;
	if (*f)
	{
		if (is_fspec(*f))
			s = convert_arg(f, ap, &arg);
		else
		{
			s = ft_strnew(2);
			*s = *f;
			arg.f = 'c';
		}
		if (arg.err)
			return (0);
		handle_flag(s, &arg, cut);
		while (g_buff[g_i])
			g_i++;
		i = get_next_spec(++f);
		if (buff_cpy(f, i, ap) == 0)
			return (0);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		res;
	char	*f;
	va_list	ap;

	g_ret = 0;
	if (!format || !*format)
		return (0);
	f = (char *)format;
	j = ft_strlen(f);
	va_start(ap, format);
	if ((i = get_next_spec(f)) == j)
	{
		write(1, f, j);
		return (j);
	}
	buff_init(f, i);
	if (!handler(f + i + 1, ap, ""))
	{
		write(1, g_buff, g_i);
		return (-1);
	}
	va_end(ap);
	res = g_i;
	write(1, g_buff, res);
	g_ret += res;
	return (g_ret);
}
