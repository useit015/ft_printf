/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:48:28 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/12 01:12:10 by onahiz           ###   ########.fr       */
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

int		buff_cpy(char *f, int pos, va_list ap)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	s = ft_strnew(pos + 1);
	while (++i < pos)
		s[i] = f[i];
	if (*(f + i + 1) && f[i] == '%')
	{
		if ((j = handler(f + i + 1, ap, s)))
			return (1);
	}
	if (*s && j)
	{
		ft_strcat(g_buff, s);
		while (g_buff[g_i])
			g_i++;
		return (1);
	} 
	if (!f[i])
		return (1);
	return (0);
}