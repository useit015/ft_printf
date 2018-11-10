/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:50:31 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/10 22:17:42 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			is_fspec(char f)
{
	if (ft_strchr("%cCsSdDiuUxXoOp", f))
		return (1);
	return (0);
}

int			is_flag(char f)
{
	if (ft_strchr(" +-.#lhjz", f) || ft_isdigit(f))
		return (1);
	return (0);
}

void		parse_flags(char *f, t_param *arg)
{
	while (is_flag(*f))
	{
		if (*f != 48 && ft_isdigit(*f))
		{
			arg->width = ft_atoi(f);
			while (ft_isdigit(*f))
				f++;
		}
		if (*f == '#')
			arg->hash = 1;
		else if (*f == '-')
			arg->minus = 1;
		else if (*f == '+')
			arg->plus = 1;
		else if (*f == '0')
			arg->zero = 1;
		else if (*f == ' ')
			arg->space = 1;
		else if (*f == '.' && arg->precision == -1)
		{
			while (*f == '.')
				f++;
			arg->precision = ft_atoi(f);
			while (ft_isdigit(*f))
				f++;
		}
		if (*f == 'l' && *(f + 1) == 'l')
		{
			f++;
			arg->ll = 1;
		}
		else if (*f == 'h' && *(f + 1) == 'h')
		{
			f++;
			arg->hh = 1;
		}
		else if (*f == 'l')
			arg->l = 1;
		else if (*f == 'h')
			arg->h = 1;
		else if (*f == 'z')
			arg->z = 1;
		else if (*f == 'j')
			arg->j = 1;
		if (is_fspec(*f))
			break ;
		f++;
	}
	if (is_fspec(*f))
		arg->f = *f;
}

int			get_next_spec(char *f)
{
	int		i;

	i = -1;
	while (f[++i])
	{
		if (f[i] == '%')
			return (i);
	}
	return (i);
}
