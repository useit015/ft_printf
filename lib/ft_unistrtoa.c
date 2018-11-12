/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistrtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 05:54:53 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/12 01:31:35 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"

char	*ft_unistrtoa(wchar_t *c, int max)
{
	size_t	len;
	char	*s;
	char	*uni;
	char	*tmp;

	if (!c)
		return (NULL);
	s = ft_strnew(1);
	while (*c)
	{
		uni = ft_unitoa(*c);
		len = ft_strlen(uni);
		if (len <= (size_t)max)
		{
			max -= len;
			tmp = s;
			s = ft_strjoin(s, uni);
			free(tmp);
			c++;
		}
		else
			break ;
	}
	return (s);
}
