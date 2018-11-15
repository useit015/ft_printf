/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:39:11 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/15 21:58:44 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (ft_memset(str, 0, size + 1));
}
