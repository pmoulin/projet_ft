/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:58:56 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 17:09:05 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <sys/types.h>
# include "libft.h"
# include <locale.h>

# define BASEA "0123456789abcdef"
# define BASEB "0123456789ABCDEF"

typedef struct	s_env
{
	long long	convertion;
	int			i;
	int			f;
	int			s;
	int			c;
	int			n;
	int			p;
	int			x;
	char		type_convert[3];
	int			l;
	int			u;
	int			point;
	int			zero;
	int			fs;
	int			o;
	int			modulo;
	char		*line;
	int			nega;
	int			t;
	int			norme;
	char		tv[2];
	int			t2;
	int			size_line;
	int			pos;
	char		*tmp;
	char		carac;
	int			h_tag;
	char		type;
	int			plus;
}				t_env;

void			lenght_for_p(t_env *e, char *param, int v);
void			preci_for_p(t_env *e, char *param, int v);
void			lenght_for_oxdu(t_env *e, char *param, int v);
void			precision_for_oxdu(t_env *e, char *param, int v);
void			alloc_tmp(char **tmp, int i);
void			check_space_to_line(t_env *e, char *param);
void			precision_and_lenght_for_oxdu(t_env *e, char *param, int i);
void			choice_preci_and_lenght(t_env *e, char *param);
void			preci_and_lenght_for_oxdu_4(t_env *e, char *param, char *tmp,
int x);
int				parse_preci_and_lenght(t_env *e,
const char *restrict format, int i, char *tmp);
int				parse_point_h_tag(t_env *e, const char *restrict format, int i);
int				parse_param_conv(t_env *e, va_list *ap,
const char *restrict format, int i);
int				check_convert(t_env *e, const char *restrict format, int i,
int i1);
int				parse_string(const char *restrict format, va_list *ap, t_env *e,
int i);
int				check_param_valid(t_env *e, const char *restrict format, int i);
int				remp_tab_convert(t_env *e, char *type);
void			lenght_and_preci_for_p_1(t_env *e, char *param, int v);
void			choice_preci_and_lenght_for_p(t_env *e, char *param);
void			choice_preci_and_lenght_for_oxdu(t_env *e, char *param);
void			lenght_and_preci_pointer_choice(t_env *e, char *param);
void			choice_precision_and_lenght_for_s(t_env *e, char *param);
void			precision_for_s(t_env *e, char *param, int v);
void			precision_and_lenght_for_s(t_env *e, char *param, int i);
void			lenght_for_s(t_env *e, char *param);
int				ft_printf(const char *restrict format, ...);
int				ft_putstr_like(t_env *e, int x);
int				flag_d_i(int i1, long long int nb, t_env *e, int v);

int				flag_f(double d, int i, t_env *e);
int				flag_x(unsigned long long int nb, int i, t_env *e, char type);

int				nb_zero_or_one(t_env *e, int i, unsigned long long int nb);
char			*conv_nb_to_letter(int *i2, char type);
int				search_param(int i, const char *restrict format, t_env *e);
int				check_pos(const char *restrict format, int i, int x);
int				check_type(int i, const char *restrict format, t_env *e);
int				choice_flag(int i, t_env *e, va_list *ap,
const char *restrict s);
int				check_param_valid(t_env *e, const char *restrict format, int i);
int				choice_flag_unsi(t_env *e, const char *restrict format, int i,
intmax_t nbr);
int				choice_param_unsigned(va_list *ap, t_env *e,
const char *restrict s, int i);
uintmax_t		choice_param_unsigned_d_i(va_list *ap, t_env *e,
const char *restrict s, int i);
void			join(char *tmp, t_env *e, char *tmp2);
int				s_nul(t_env *e, char **s, int choice, int i);
void			init_param3(t_env *e);
void			ft_error(char *type, char *func);
char			*ft_getwchar(wchar_t c);
int				flag_uni_s(wchar_t *s, t_env *e, int i);
int				flag_unsi_c(wchar_t c, t_env *e, int i);
char			*ft_ftoa(double nb);
char			*ft_dtoa(double nb);
char			*ft_uitoa(unsigned int n);
char			*ft_ullitoa(unsigned long long int n);
int				flag_s(char *s, int i1, t_env *e);
int				flag_c(char c, int i, t_env *e);
int				printf_faill_param(t_env *e, const char *restrict format, int i,
int i1);
int				flag_p(void *p, int i, t_env *e);
int				flag_u(unsigned long long int nb, int i, t_env *e, int x2);
int				h_tag(t_env *e, char **tmp1, char type);
int				flag_o(unsigned long long int nb, int i, t_env *e, char type);
int				flag_modu(int i, t_env *e);
void			precision_char(t_env *e, char param);
void			precision_string(t_env *e, char *param);
void			free_tab(char **tmp, int x);

#endif
