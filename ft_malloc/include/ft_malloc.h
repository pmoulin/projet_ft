/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:16:35 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/16 11:16:38 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <unistd.h>

# define H_BLOC_SM sizeof(t_bloc)
# define H_BLOC_L sizeof(t_zone)
# define ZONE_HEADER sizeof(t_zone)

# define SZ_TINY 2048
# define SZ_SMALL 10240

typedef struct		s_bloc
{
	size_t			size;
	struct s_bloc	*next;
	struct s_bloc	*prev;
	int				status;
}					t_bloc;

typedef struct		s_zone
{
	struct s_bloc	*bloc;
	struct s_zone	*next;
	size_t			size;
	struct s_zone	*prev;
}					t_zone;

typedef struct		s_env_m
{
	t_zone			*z_tiny;
	t_zone			*z_large;
	t_zone			*z_small;
}					t_env_m;

t_env_m				g_env_m;

/*
** **************************************************************************
** ******************************* function malloc **************************
** **************************************************************************
*/

/*
** malloc.c
*/

extern void			*malloc(size_t size);
void				*large(size_t size_zone);
void				*tiny(size_t size);
void				*small(size_t size);

/*
** tiny.c
*/

void				*search_place_tiny(size_t size);
int					new_zone_tiny(size_t size_zone);

/*
** small.c
*/

void				*search_place_small(size_t size);
int					new_zone_small(size_t size_zone);

/*
** **************************************************************************
** ******************************* function free ****************************
** **************************************************************************
*/

/*
** free.c
*/

extern void			free(void *ptr);
t_bloc				*join_bloc(t_bloc *bloc1, t_bloc *bloc2);

/*
** **************************************************************************
** ******************************* function realloc *************************
** **************************************************************************
*/

/*
** realloc.c
*/

extern void			*realloc(void *ptr, size_t size);

/*
** same_type.c
*/

void				*same_type(void *ptr, size_t size, int type);

/*
** convert_type.c
*/

void				*convert_type(void *ptr, size_t size,
									int type_ptr, int new_type);

/*
** copy_old_ptr.c
*/

char				*cpy(char *src, char *dest, size_t size);

/*
** **************************************************************************
** ******************************* function show_alloc_mem*******************
** **************************************************************************
*/

/*
** show_alloc_mem.c
*/

extern void			show_alloc_mem(void);

/*
** print_addr.c
*/

void				print_addr(void *p);

/*
** print_size.c
*/

void				print_size(size_t number);

/*
** print_text.c
*/

void				malloc_putstr(char *str);
void				malloc_putchar(char c);

/*
** **************************************************************************
** ******************************* function utils ***************************
** **************************************************************************
*/

t_zone				*move_ptr_global(t_zone *zone, t_zone *zone_g);

void				go_first_elem_small(void);
void				go_first_elem_tiny(void);

void				*go_first_maillon(t_bloc *bloc, t_zone *zone);
void				*go_last_maillon(t_bloc *bloc, t_zone *zone);

void				print_list(t_zone *zone);

#endif
