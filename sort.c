/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:49:54 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/10 15:08:16 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int is_sorted(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1 && stack->flag_ab == stack->len - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			break ;
		i++;
		if (i == stack->len - 1)
			return (0);
	}
	return (-1);
}

void	*three_stack(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	if (array->array[0] < array->array[1] && array->array[1] < array->array[2])
		return ;
}

int	stack_control(t_array *array)
{
	three_stack(array);
	if (is_sorted == 0)
		return (0);
	
}