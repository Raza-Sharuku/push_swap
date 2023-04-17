/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/17 10:15:34 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_array(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->len)
	{
		if (i == array->flg)
			printf(" | ");
		printf(" %i , ", array->array[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_array		array;
	// int i;

	if (ft_error_check(argc, argv, &array) < 0)
		ft_error();
	array.array = compress_array(&array);
	// printf("\n---------  after compress --------\n");
	// i = check_array(&array);
	if (is_sorted(&array) == 0 || stack_control(&array) == 0)
	{
		// i = check_array(&array);
		free(array.array);
		return (0);
	}
	if (is_sorted(&array) == -1 || stack_control(&array) == -1)
		ft_error();
	return (0);
}

// __attribute__((destructor))
// void    destructor(void)
// {
// 	system("leaks -q push_swap");

// }
