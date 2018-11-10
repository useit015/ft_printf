/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistrtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 05:54:53 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/10 06:05:48 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"

char	*ft_unistrtoa(wchar_t *c)
{
	char	*s;
	char	*tmp;

	if (!c)
		return (NULL);
	s = ft_strnew(1);
	while (*c)
	{
		tmp = s;
		s = ft_strjoin(s, ft_unitoa(*c));
		free(tmp);
		c++;
	}
	return (s);
}
