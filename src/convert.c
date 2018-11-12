/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:43:39 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/12 01:39:38 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*convert_int(char *f, t_param *arg, va_list ap)
{
	long int	i;

	if (arg->ll)
		return (ft_lltoa(va_arg(ap, long long int)));
	else if (arg->l || *f == 'D')
		return (ft_ltoa(va_arg(ap, long int)));
	else if (arg->j)
		return (ft_jtoa(va_arg(ap, intmax_t)));
	else if (arg->z)
	{
		i = va_arg(ap, long int);
		if (i < 0)
			return (ft_ltoa(i));
		else
			return (ft_ztoa(i));
	}
	else if (arg->h)
		return (ft_htoa((short)va_arg(ap, int)));
	else if (arg->hh)
		return (ft_hhtoa((signed char)va_arg(ap, int)));
	else
		return (ft_itoa(va_arg(ap, int)));
}

char		*convert_uint(char *f, t_param *arg, va_list ap)
{
	if (arg->ll)
		return (ft_ulltoa(va_arg(ap, unsigned long long int)));
	else if (arg->l || *f == 'U')
		return (ft_ulltoa(va_arg(ap, unsigned long int)));
	else if (arg->j)
		return (ft_ujtoa(va_arg(ap, uintmax_t)));
	else if (arg->z)
		return (ft_ztoa(va_arg(ap, size_t)));
	if (arg->hh)
		return (ft_utoa((unsigned char)va_arg(ap, unsigned int)));
	else if (arg->h)
		return (ft_uhtoa((unsigned short)va_arg(ap, int)));
	else
		return (ft_utoa(va_arg(ap, unsigned int)));
}

char		*convert_b(char *f, t_param *arg, va_list ap, char *base)
{
	if (arg->ll)
		return (ft_convert_base(va_arg(ap, unsigned long long int), base));
	else if (arg->l || *f == 'O')
		return (ft_convert_base(va_arg(ap, unsigned long int), base));
	else if (arg->j)
		return (ft_convert_base(va_arg(ap, uintmax_t), base));
	else if (arg->z)
		return (ft_convert_base(va_arg(ap, size_t), base));
	if (arg->hh)
		return (ft_convert_base((unsigned char)va_arg(ap, unsigned int), base));
	else if (arg->h)
		return (ft_convert_base((unsigned short)va_arg(ap, int), base));
	else
		return (ft_convert_base(va_arg(ap, unsigned int), base));
}

char		*convert_char(t_param *arg, va_list ap)
{
	char	*s;
	char	c;

	s = (char*)ft_strnew(3);
	c = va_arg(ap, int);
	if (!c)
	{
		arg->null = 1;
		c = '|';
	}
	*s = c;
	return (s);
}

char		*convert_wchar(t_param *arg, va_list ap)
{
	wchar_t		uni;
	char		*s;

	uni = va_arg(ap, wchar_t);
	if (uni < 0 || (uni >= 0xd800 && uni < 0xe000 ) ||
		uni > 0x10ffff || (uni >= 256 && MB_CUR_MAX == 1))
		arg->err = 1;
	s = ft_unitoa(uni);
	if (!*s)
	{
		arg->null = 1;
		*s = '|';
	}
	return (s);
}

char		*convert_arg(char *f, va_list ap, t_param *arg)
{
	int			i;
	char		*s;
	char		*base;
	wchar_t		*uni;

	i = 0;
	base = get_base(*f);
	if (*f == 'p')
	{
		arg->hash = 1;
		s = ft_convert_base(va_arg(ap, unsigned long), get_base('x'));
	}
	else if (*f == 'd' || *f == 'i' || *f == 'D')
		s = convert_int(f, arg, ap);
	else if (*f == 'S' || (*f == 's' && arg->l))
	{
		uni = va_arg(ap, wchar_t *);
		while (uni[i])
		{
			if (uni[i] < 0 || (uni[i] >= 0xd800 && uni[i] < 0xe000 ) ||
				uni[i] > 0x10ffff || (uni[i] >= 256 && MB_CUR_MAX == 1))
				arg->err = 1;
			i++;
		}
		s = ft_unistrtoa(uni, arg->precision);
	}
	else if (*f == 's')
		s = va_arg(ap, char *);
	else if (*f == 'C' || (*f == 'c' && arg->l))
		s = convert_wchar(arg, ap);
	else if (*f == 'c')
		s = convert_char(arg, ap);
	else if (*f == '%')
		s = "%";
	else if (*f == 'u' || *f == 'U')
		s = convert_uint(f, arg, ap);
	else
		s = convert_b(f, arg, ap, base);
	if (!s)
		s = "(null)";
	return (s);
}
