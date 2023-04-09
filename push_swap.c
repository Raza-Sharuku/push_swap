/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/09 14:49:47 by razasharuku      ###   ########.fr       */
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

int	ft_error(int i)
{
	if (i == 1)
		write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stack		stack;
	t_S_list	*head;

	if (ft_error_check(argc, argv, &stack) < 0)
		return (ft_error(1));
	i = 0;
	printf("\n----- start value of stack -> stack -----\n\n");
	while (i < stack.len)
	{
		ft_printf("%i , ", stack.stack[i]);
		i++;
	}
	i = 0;
	stack.stack = compress_array(&stack);
	while (i < stack.len)
	{
		ft_printf("%i , ", stack.stack[i]);
		i++;
	}
	head = ft_makelist(&stack);
	i = 0;
	printf("\n------- checking list -------\n\n");
	while (i < stack.len)
	{
		printf("head_point[%i] = %p\n", i, head);
		printf("head->value[%i] = %i\n", i, head->value);
		printf("head.next[%i] = %p\n", i, head->next);
		printf("\n----- next list ---------\n\n");
		head = head->next;
		i++;
	}
	system("leaks push_swap");
	return (0);
}
