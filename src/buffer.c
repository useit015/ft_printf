/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:48:28 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/16 04:25:57 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/handle.h"

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

char	*new_fspec(t_param *arg, char f)
{
	char	*s;

	s = ft_strnew(2);
	*s = f;
	arg->f = 'c';
	return (s);
}

int		is_fspec(char f)
{
	if (ft_strchr("%cCsSdDiuUxXoOpbfF", f))
		return (1);
	return (0);
}

int		is_flag(char f)
{
	if (ft_strchr(" +-.#lhjzL$'*", f) || ft_isdigit(f))
		return (1);
	return (0);
}
