/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/08 14:35:56 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/* if arguments clear error_check, it means arguments can use for this program and then my next step is divide in two case. 
1 How to recieve numbers when argc is 2 and argument contains multipule numbers.
-> This can be solve by whether argc is 2 or not.
2 How to receive numbers when argc is more than 3 and all of them are single-shot numbers.
->This can be determined by whether argc is more than 3 or not.
Then, pass the each case to a function to handle.
*/

int ft_error(int i)
{
	if (i == 1)
		write(2, "Error\n", 6);
	return (1);
}

int main (int argc, char *argv[])
{
	int		i;
	t_stack	stack;

	if (ft_error_check(argc, argv, &stack) < 0)
		return (ft_error(1));
	ft_printf("\n----------------------------------------------------------\n\n");
	i = 0;
	while (i <= stack.len)
	{
		ft_printf("%i\n",stack.stack[i]);
		i++;
	}
	// system("leaks push_swap");
	return (0);
}
