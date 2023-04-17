/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/17 20:11:12 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_error(t_array *s)
{
	free(s->array);
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

	if (argc == 1 || ft_error_check(argc, argv, &array) < 0)
		ft_error(&array);
	if (array.len == 1)
		return (0);
	array.array = compress_array(&array);
	if (is_sorted(&array) == 0 || stack_control(&array) == 0)
	{
		free(array.array);
		return (0);
	}
	if (is_sorted(&array) == -1 || stack_control(&array) == -1)
		ft_error(&array);
	return (0);
}

__attribute__((destructor))
void    destructor(void)
{
	system("leaks -q push_swap");

}
