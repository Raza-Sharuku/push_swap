/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/12 12:16:25 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

__attribute__((destructor))
void    destructor(void)
{
	system("leaks -q push_swap");

}

int check_array(t_array *array)
{
	int i;

	i = 0;
	while (i < array->len)
	{
		if (i == array->flag_ab)
			printf(" | ");
		printf(" %i , ", array->array[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_array		array;

	if (ft_error_check(argc, argv, &array) < 0)
		ft_error();
	i = 0;
	array.array = compress_array(&array);
	printf("\n\n------------- after compress -----------------\n");
	while (i < array.len)
	{
		ft_printf("%i , ", array.array[i]);
		i++;
	}
	printf("\n");
	if (is_sorted(&array) == 0 || stack_control(&array) == 0)
	{
		printf("\n------------- last form of array -----------------\n");
		i = check_array(&array);
		free(array.array);
		return (0);
	}
	if (is_sorted(&array) == -1 || stack_control(&array) == -1)
		ft_error();
	return (0);
}


	// printf("\n\n------------- after push -----------------\n");
	// array.flag_ab = 0;
	// i = check_array(&array);
	// push_b(&array);
	// i = check_array(&array);
	// push_b(&array);
	// i = check_array(&array);
	// push_b(&array);
	// i = check_array(&array);
	// swap_ss(&array);
	// i = check_array(&array);
	// printf("\n\n------------- its  rotate_a -----------------\n");
	// rotate_a(&array);
	// i = check_array(&array);
	// printf("\n\n------------- its  rotate_b -----------------\n");
	// rotate_b(&array);
	// i = check_array(&array);
	// printf("\n\n------------- its  rotate_ab -----------------\n");
	// rotate_rr(&array);
	// i = check_array(&array);
	// printf("\n\n------------- its  rev_rotate_a -----------------\n");
	// rev_rotate_ra(&array);
	// i = check_array(&array);
	// printf("\n\n------------- its  rev_rotate_b -----------------\n");
	// rev_rotate_rb(&array);
	// i = check_array(&array);
	// printf("\n\n------------- its  rev_rotate_rrr -----------------\n");
	// rev_rotate_rrr(&array);
	// i = check_array(&array);