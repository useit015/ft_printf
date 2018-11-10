/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:22:59 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/10 07:10:10 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	handle_null(char *s)
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

void	handle_flag(char *s, t_param *arg)
{
	int		len;

	len = (int)ft_strlen(s);
	s = handle_precision(arg, s, len);
	len = (int)ft_strlen(s);
	s = handle_width(arg, s, len);
	s = handle_plus_space(arg, s, len);
	if (!(*s == '0' && !*(s + 1)) || arg->f == 'p')
		s = handle_hash(arg, s, len);
	if (arg->null)
		handle_null(s);
	else
		ft_strcat(g_buff, s);
}

void	handler(char *f, va_list ap)
{
	int		i;
	char	*s;
	t_param	arg;

	i = g_i;
	init_arg(&arg);
	parse_flags(f, &arg);
	while (*f && is_flag(*f))
		f++;
	while (*f && (!is_fspec(*f) || g_i != i) && *f != '%')
	{
		g_buff[g_i++] = *f;
		f++;
	}
	if (*f == '%' && g_i != i)
		return (handler(++f, ap));
	if (*f && is_fspec(*f))
	{
		s = convert_arg(f, ap, &arg);
		handle_flag(s, &arg);
		while (g_buff[g_i])
			g_i++;
		i = get_next_spec(++f);
		buff_cpy(f, i, ap);
	}
}

int		ft_printf(const char *format, ...)
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
	handler(f + i + 1, ap);
	va_end(ap);
	res = ft_strlen(g_buff);
	write(1, g_buff, res);
	g_ret += res;
	return (g_ret);
}
