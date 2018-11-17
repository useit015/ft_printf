/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:48:28 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/17 03:35:37 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/handle.h"

int		ft_putbuff(t_buff *b, int ret)
{
	write(1, b->buff, b->i);
	free(b->buff);
	return (ret);
}

void	buff_init(char *f, int pos, t_buff *b)
{
	b->i = 0;
	b->buff = ft_strnew(BUFF_SIZE);
	while (b->i < pos)
	{
		b->buff[b->i] = f[b->i];
		b->i++;
	}
}

int		buff_cpy(char *f, int pos, va_list ap, t_buff *b)
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
		if ((j = handler(f + i + 1, ap, s, b)))
			return (1);
	}
	if (*s && j)
	{
		ft_strcat(b->buff, s);
		free(s);
		while (b->buff[b->i])
			b->i++;
		return (1);
	}
	if (!f[i] || (f[i] == '%' && !f[i + 1]))
		return (1);
	return (0);
}
