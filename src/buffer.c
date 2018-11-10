/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:48:28 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/09 01:08:36 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	buff_init(char *f, int pos)
{
	g_i = 0;
	ft_memset(g_buff, 0, BUFF_SIZE);
	while (g_i < pos)
	{
		g_buff[g_i] = f[g_i];
		g_i++;
	}
}

void	buff_cpy(char *f, int pos, va_list ap)
{
	int		i;

	i = -1;
	while (++i < pos)
		g_buff[g_i++] = f[i];
	if (*(f + i + 1) && f[i] == '%')
		handler(f + i + 1, ap);
}
