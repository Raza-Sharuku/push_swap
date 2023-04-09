/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:26:29 by sraza             #+#    #+#             */
/*   Updated: 2023/04/09 14:45:35 by razasharuku      ###   ########.fr       */
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

typedef struct s_stack
{
	int	*stack;
	int	len;
}				t_stack;
typedef struct s_S_list
{
	int				value;
	struct s_S_list	*next;
}				t_S_list;
int				main(int argc, char *argv[]);
int				ft_error_check(int argc, char *argv[], t_stack *stack);
long			ft_atoi_swap(const char *str);
void			*ft_free_swap(char **result);
int				*ft_makelist_argc2(char *argv[]);
int				*ft_makelist_argc3(int argc, char *argv[]);
int				*compress_array(t_stack *stack);
t_S_list		*ft_makelist(t_stack *stack);
t_S_list		*ft_newlst(int value);

#endif
