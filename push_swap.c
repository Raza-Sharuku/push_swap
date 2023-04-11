/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/11 09:40:24 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/* if arguments clear error_check, it means arguments 
can use for this program and then my next step is divide 
in two case. 
1 How to recieve numbers when argc is 2 and argument contains 
multipule numbers.
-> This can be solve by whether argc is 2 or not.
2 How to receive numbers when argc is more than 3 and all of 
them are single-shot 
numbers.
->This can be determined by whether argc is more than 3 or not.
Then, pass the each case to a function to handle.
*/

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// __attribute__((destructor))
// void    destructor(void)
// {
// 	system("leaks -q push_swap");

// }

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
	printf("\n----- start value of array -> array -----\n\n");
	while (i < array.len)
	{
		ft_printf("%i , ", array.array[i]);
		i++;
	}
	i = 0;
	array.array = compress_array(&array);
	printf("\n\n------------- after compress -----------------\n");
	while (i < array.len)
	{
		ft_printf("%i , ", array.array[i]);
		i++;
	}
	printf("\n\n------------- after push -----------------\n");
	array.flag_ab = 0;
	i = check_array(&array);
	push_b(&array);
	i = check_array(&array);
	push_b(&array);
	i = check_array(&array);
	swap_ss(&array);
	i = check_array(&array);
	printf("\n\n------------- its  rotate_a -----------------\n");
	rotate_a(&array);
	i = check_array(&array);
	printf("\n\n------------- its  rotate_b -----------------\n");
	rotate_b(&array);
	i = check_array(&array);
	printf("\n\n------------- its  rotate_ab -----------------\n");
	rotate_rr(&array);
	i = check_array(&array);
	printf("\n\n------------- after rotate -----------------\n");
	return (0);
}

	// head = ft_makelist(&array);
	
	// i = 0;
	// printf("\n------- checking list -------\n\n");
	// while (i < array.len)
	// {
	// 	printf("head_point[%i] = %p\n", i, head);
	// 	printf("head->value[%i] = %i\n", i, head->value);
	// 	printf("head.next[%i] = %p\n", i, head->next);
	// 	printf("\n----- next list ---------\n\n");
	// 	head = head->next;
	// 	i++;
	// }