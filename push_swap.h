/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:26:29 by sraza             #+#    #+#             */
/*   Updated: 2023/04/06 21:28:01 by sraza            ###   ########.fr       */
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
#include"./libs/ft_printf/ft_printf.h"
#include"./libs/libft/libft.h"


int 			main(int argc, char *argv[]);
int				ft_error_check(int argc, char *argv[]);
long	        ft_atoi_swap(const char *str);
void	        *ft_free_swap(char **result);
char 	        **ft_makelist(int argc, char *argv[]);

#endif
