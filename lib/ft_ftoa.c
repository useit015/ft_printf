/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:32:01 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/13 06:33:56 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"
#include <stdio.h>

static intmax_t	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_pow(nb, power - 1));
}

static int		long_len(long n)
{
	int		i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

static char		*ft_fftoa(double f, int p)
{
	long double		tmp;
	long int		dec;
	char			*s;
	char			*fs;

	fs = ft_strcat(ft_ltoa(f), ".");
	dec = f;
	f = f - dec;
	tmp = f * ft_pow(10, p);
	dec = tmp;
	if (tmp < 0.0)
		tmp = -tmp;
	s = ft_ltoa(tmp);
	return (ft_strjoin(fs, s));
}

char			*ft_ftoa(double f, int p)
{
	size_t	l;
	double	tmp;
	int		next;
	char	*s;
	char	*fs;

	if (p < 0)
		p = 6;
	else if (!p)
		return (ft_lltoa(f));
	tmp = f * ft_pow(10, p);
	next = (tmp - (long)tmp) * 10;
	if (next < -5 && next >= -10)
		tmp--;
	else if (next < 10 && next >= 5)
		tmp++;
	if (long_len(tmp) > 15)
		return (ft_fftoa(f, p));
	s = ft_lltoa(tmp);
	l = ft_strlen(s);
	fs = ft_strcat(ft_strncpy(ft_strnew(l + 2), s, l - p), ".");
	if (*fs == '.')
		fs = ft_strjoin("0", fs);
	return (ft_strcat(fs, s + l - p));
}
