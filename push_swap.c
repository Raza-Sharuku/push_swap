/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/06 21:27:55 by sraza            ###   ########.fr       */
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

char	**ft_makelist(int argc, char *argv[])
{
	char	**list;
	int		i;

	i = 0;
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	
	if (argc > 2)
	{
		list = malloc(sizeof(char *) * (argc));
		while (i < argc - 1)
		{
			list[i] = argv[i + 1];
			i++;
		}
		list[i] = NULL;
	}
	return (list);
}

int main (int argc, char *argv[])
{
	int	i;
	char **list;

	if (ft_error_check(argc, argv) < 0)
	{
		printf("Error\n");
		return (1);
	}
	list = ft_makelist(argc, argv);
	i = 1;
	while (list[i])
	{
		printf("%s\n",list[i]);
		i++;
	}
	// system("leaks push_swap");
	return (0);
}

/*

*/