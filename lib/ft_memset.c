/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 03:39:16 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/07 23:55:02 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char *dst;

	dst = (unsigned char *)s;
	while (len)
	{
		*dst = (unsigned char)c;
		dst++;
		len--;
	}
	return (s);
}
