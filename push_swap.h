/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:26:29 by sraza             #+#    #+#             */
/*   Updated: 2023/04/12 14:30:37 by razasharuku      ###   ########.fr       */
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
	int flg;
}				t_array;
// typedef struct s_S_list
// {
// 	int				value;
// 	struct s_S_list	*next;
// }				t_S_list;

int				main(int argc, char *argv[]);
int				ft_error_check(int argc, char *argv[], t_array *stack);
long			ft_atoi_swap(const char *str);
void			*ft_free_swap(char **result);
int				*ft_makelist_argc2(char *argv[]);
int				*ft_makelist_argc3(int argc, char *argv[]);
int				*compress_array(t_array *stack);
void			*swap_a(t_array *array);
void			*swap_b(t_array *array);
void			*swap_ss(t_array *array);
void			*push_a(t_array *array);
void			*push_b(t_array *array);
int				check_array(t_array *array);
void			*rotate_a(t_array *array);
void			*rotate_b(t_array *array);
void			*rotate_rr(t_array *array);
void			*rev_rotate_ra(t_array *array);
void			*rev_rotate_rb(t_array *array);
void			*rev_rotate_rrr(t_array *array);
int				stack_control(t_array *array);
int				three_stack(t_array *array);
int				sort_three(t_array *array);
int				two_stack(t_array *array);
int				is_sorted(t_array *stack);
int				six_sort(t_array *s);
int				four_five_stack(t_array *s);

// t_S_list		*ft_makelist(t_array *stack);
// t_S_list		*ft_newlst(int value);

#endif
