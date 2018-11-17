/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:22:59 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/16 23:40:06 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/handle.h"

int			ft_putbuff(t_buff *b, int ret)
{
	write(1, b->buff, b->i);
	free(b->buff);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	char	*f;
	va_list	ap;
	t_buff	b;

	b.ret = 0;
	if (!format || !*format)
		return (0);
	f = (char *)format;
	va_start(ap, format);
	if ((j = direct_print(f, &i)))
		return (j);
	buff_init(f, i, &b);
	if (!handler(f + i + 1, ap, "", &b))
		return (ft_putbuff(&b, -1));
	va_end(ap);
	return (ft_putbuff(&b, b.ret + b.i));
}
