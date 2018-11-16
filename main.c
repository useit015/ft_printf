/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 05:08:43 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/16 05:44:33 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
# include <stdio.h>

int		main()
{
	char	*str = "lorem ipsum dolor sit amet";
	printf("return is --> |%d|\n", printf("printf___ |>->------------<!%200p!>-----------<-<|\n", str));
	printf("return is --> |%d|\n", ft_printf("ft_printf |>->------------<!%200p!>-----------<-<|\n", str));
	
	return (0);
}