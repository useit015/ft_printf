/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:48:28 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/14 02:34:48 by onahiz           ###   ########.fr       */
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
	if (ft_strchr("%cCsSdDiuUxXoOpb", f))
		return (1);
	return (0);
}

int		is_flag(char f)
{
	if (ft_strchr(" +-.#lhjzL$*'", f) || ft_isdigit(f))
		return (1);
	return (0);
}
