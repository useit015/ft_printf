/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 05:37:49 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/10 06:32:18 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_arg(t_param *arg)
{
	arg->precision = -1;
	arg->null = 0;
	arg->minus = 0;
	arg->plus = 0;
	arg->hash = 0;
	arg->zero = 0;
	arg->space = 0;
	arg->width = 0;
	arg->f = 0;
	arg->ll = 0;
	arg->l = 0;
	arg->hh = 0;
	arg->h = 0;
	arg->j = 0;
	arg->z = 0;
}

char	*get_prefix(char c)
{
	if (c == 'x' || c == 'p')
		return ("0x");
	if (c == 'X')
		return ("0X");
	else
		return ("0");
}

char	*get_base(char c)
{
	if (c == 'x')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	else if (c == 'o' || c == 'O')
		return ("01234567");
	else
		return ("");
}

char	get_sign(t_param *arg)
{
	if (arg->plus)
		return ('+');
	else
		return (' ');
}

char	get_fill(t_param *arg)
{
	if (arg->zero && !arg->minus)
		return ('0');
	else
		return (' ');
}
