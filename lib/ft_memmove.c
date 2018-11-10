/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 04:00:59 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/07 23:55:02 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)ft_memalloc(n);
	if (temp == NULL)
		return (dst);
	ft_memcpy(temp, src, n);
	ft_memcpy(dst, temp, n);
	free(temp);
	return (dst);
}
