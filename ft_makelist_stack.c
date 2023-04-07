/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:45:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/07 12:39:11 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/* In this file, first ft_makelist check numbers of arguments. Then, if 
arguments are 2, it will pass the whole argument to  *ft_makelist_argc2 and 
split the argv[1]. and change the form of list one by one from char to int.
otherwise, arguments are more then three, it will pass the whole argument to 
*ft_makelist_argc3 which convert each argument to form of int and stored it 
in int_list.
*/

void	*ft_makelist_argc2(char *argv[], t_stack *stack)
{
	char	**list;
	int		i;
	int		lst_len;

	i = 0;
	list = ft_split(argv[1], ' ');
	ft_printf("--------------------------split------------------------\n\n");
	while (list[i])
		i++;
	lst_len = i;
	stack->len = lst_len;
	ft_printf("--------------------------stack.len-----------------------\n\n");
	stack->stack = (int *)malloc(sizeof(int) * (lst_len + 1));
	i = 0;
	while (i < lst_len)
	{
		stack->stack[i] = ft_atoi_swap(list[i]);
		i++;
	}
	return (0);
}

void	*ft_makelist_argc3(int argc, char *argv[], t_stack *stack)
{
	int		i;

	i = 0;
	stack->stack = (int *)malloc(sizeof(int) * (argc));
	while (i < argc - 1)
	{
		stack->stack[i] = ft_atoi_swap(argv[i + 1]);
		i++;
	}
	stack->len = argc - 1;
	return (0);
}

void	*ft_makelist(int argc, char *argv[], t_stack *stack)
{
	if (argc == 2)
		stack->stack = ft_makelist_argc2(argv, stack);
	else if (argc > 2)
		stack->stack = ft_makelist_argc3(argc, argv, stack);
	else
		stack->stack = NULL;
	return (0);
}
