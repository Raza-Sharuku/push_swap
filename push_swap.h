/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:26:29 by sraza             #+#    #+#             */
/*   Updated: 2023/04/17 09:25:50 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include"./libs/ft_printf/ft_printf.h"
# include"./libs/libft/libft.h"

typedef struct s_array
{
	int	*array;
	int	len;
	int	flg;
}				t_array;
typedef struct s_algo
{
	int	div;
	int	rot;
	int	rev;
	int	push;
	int	max;
}				t_algo;
// push_swap.c
int				main(int argc, char *argv[]);
int				check_array(t_array *array);
// ft_error.c
int				ft_error_check(int argc, char *argv[], t_array *stack);
// ft_atoi_4_swap.c
long			ft_atoi_swap(const char *str);
void			*ft_free_swap(char **result);
// compress.c
int				*compress_array(t_array *stack);
// push_swap_perform.c
void			*swap_a(t_array *array);
void			*swap_b(t_array *array);
void			*swap_ss(t_array *array);
void			*push_a(t_array *array);
void			*push_b(t_array *array);
// rotate_perform.c
void			*rotate_a(t_array *array);
void			*rotate_b(t_array *array);
void			*rotate_rr(t_array *array);
// rev_rotate_perform.c
void			*rev_rotate_ra(t_array *array);
void			*rev_rotate_rb(t_array *array);
void			*rev_rotate_rrr(t_array *array);
// sort_1.c
int				stack_control(t_array *array);
int				three_stack(t_array *array);
int				sort_three(t_array *s, int max, int mid, int min);
int				two_stack(t_array *array);
int				is_sorted(t_array *stack);
// sort_2.c
int				six_sort(t_array *s, int i);
int				four_five_stack(t_array *s);
int				sort_three_desend(t_array *s, int min, int mid, int max);
int				two_stack_desend(t_array *s);
int				six_stack(t_array *s, int res);
// sort_3.c
int				max_sort(t_array *s);
int				push_alternate(t_array *s, t_algo *a, int p, int k);
int				patterns(t_array *s, t_algo *a);
// sort_4.c
void			p_positive_push(t_array *s, t_algo *a);
void			p_rev_rot(t_array *s, t_algo *a);
int				push_rotate_a(t_array *s, t_algo *a, int p, int mod);
int				set_max_val(t_array *s, t_algo *a, int p, int mod);
// sort_5.c
int				rev_push_a(t_array *s, t_algo *a, int p, int mod);
void			p_negative_push(t_array *s, t_algo *a);

#endif
