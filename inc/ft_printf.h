/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 00:46:08 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/12 04:41:28 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "lib.h"
# include <locale.h>
# include <stdio.h>
# include <wchar.h>

# define BUFF_SIZE 4096

typedef	struct		s_param
{
	int				width;
	int				precision;
	unsigned int	err:1;
	unsigned int	null:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	hash:1;
	unsigned int	zero:1;
	unsigned int	ll:1;
	unsigned int	hh:1;
	unsigned int	l:1;
	unsigned int	h:1;
	unsigned int	j:1;
	unsigned int	z:1;
	char			f;
}					t_param;

char				g_buff[BUFF_SIZE];
int					g_i;
int					g_ret;

void				init_arg(t_param *arg);
void				buff_init(char *f, int pos);
void				parse_flags(char *f, t_param *arg);
void				copy_arg_str(char *s, char *dst, int *i);
char				*convert_b(char *f, t_param *arg, va_list ap, char *base);
char				*trim_arg2(t_param *arg, char *s, char c, int len);
char				*handle_plus_space(t_param *arg, char *s, int len);
char				*handle_precision(t_param *arg, char *s, int len);
char				*convert_uint(char *f, t_param *arg, va_list ap);
char				*convert_arg(char *f, va_list ap, t_param *arg);
char				*convert_int(char *f, t_param *arg, va_list ap);
char				*handle_width(t_param *arg, char *s, int len);
char				*handle_hash(t_param *arg, char *s, int len);
char				*trim_arg(char *s, t_param *arg, int len);
char				*new_fspec(t_param *arg, char f);
char				get_sign(t_param *arg);
char				get_fill(t_param *arg);
char				*get_prefix(char c);
char				*get_base(char c);
char				*get_base(char f);
int					is_fspec(char f);
int					is_flag(char f);
int					count_ac(char *f);
int					get_next_spec(char *f);
int					direct_print(char *f, int *i);
int					ft_printf(const char *format, ...);
int					buff_cpy(char *f, int pos, va_list ap);
int					handler(char *f, va_list ap, char *cut);
int					is_negative(t_param *arg, char **s, int *len);

#endif
