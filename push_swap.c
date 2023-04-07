/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/07 12:43:54 by razasharuku      ###   ########.fr       */
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

int main (int argc, char *argv[])
{
	int		i;
	int	*stack;

	stack = NULL;
	if (ft_error_check(argc, argv) < 0)
		return (0);
	stack = ft_makelist(argc, argv);
	ft_printf("----------------------------------------------------------\n\n");
	i = 0;
	while (i < 5)
	{
		ft_printf("%i\n",stack[i]);
		i++;
	}
	// system("leaks push_swap");
	return (0);
}
