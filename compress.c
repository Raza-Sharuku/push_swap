/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:39:43 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/08 18:07:03 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	int	*change_array_position(t_stack *stack, int *position)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		j = 0;
		while (j < stack->len)
		{
			if (stack->stack[i] == position[j])
				stack->stack[i] = j + 1;
			j++;
		}
		i++;
	}
	return (stack->stack);
}

static	int	*change_positoin(t_stack *stack, int *position)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->len)
	{
		j = 1;
		while (i + j < stack->len)
		{
			if (position[i] > position[i + j])
			{
				tmp = position[i];
				position[i] = position[i + j];
				position[i + j] = tmp;
			}
			j++;
		}
		i++;
	}
	printf("\n------------- change the position -----------------\n\n");
	i = -1;
	while (++i < stack->len)
		ft_printf("%i , ",position[i]);
	return (position);
}

int	compress_array(t_stack *stack)
{
	int	i;
	int	*position;

	i = -1;
	position = (int *)malloc(sizeof(int) * (stack->len));
	while (++i < stack->len)
		position[i] = stack->stack[i];
	position = change_positoin(stack, position);
	printf("\n------------- after compress -----------------\n\n");
	stack->stack = change_array_position(stack, position);
	free(position);
	return (0);
}
