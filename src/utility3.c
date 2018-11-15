/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:58:19 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/15 21:54:17 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/handle.h"

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

char		*skip_flags(char *f)
{
	while (*f && is_flag(*f))
		f++;
	return (f);
}
