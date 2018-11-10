/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:45:06 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/10 06:01:15 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_atoi(const char *str);
char		*ft_unitoa(wchar_t c);
char		*ft_unistrtoa(wchar_t *c);
char		*ft_itoa(int n);
char		*ft_ltoa(long int n);
char		*ft_jtoa(intmax_t n);
char		*ft_htoa(short n);
char		*ft_lltoa(long long int n);
char		*ft_hhtoa(signed char n);
char		*ft_utoa(unsigned int n);
char		*ft_ultoa(unsigned long int n);
char		*ft_ujtoa(uintmax_t n);
char		*ft_ztoa(size_t n);
char		*ft_uhtoa(unsigned short n);
char		*ft_ulltoa(unsigned long long int n);
char		*ft_strnew(size_t size);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *s, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
char		*ft_convert_base(unsigned long long nbr, char *base_to);

#endif
