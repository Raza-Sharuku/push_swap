/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:49:54 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/12 12:00:45 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_sorted(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	two_stack(t_array *array)
{
	if (array->array[0] > array->array[1])
		swap_a(array);
	if (array->array[0] < array->array[1])
		return (0);
	else
		return (-1);
}

int	sort_three(t_array *array)
{
	int	res;

	res = 0;
	if (array->array[0] == 1)
	{
		rotate_a(array);
		rotate_a(array);
		res = two_stack(array);
	}
	else if (array->array[0] == 2)
	{
		rotate_a(array);
		if (array->array[0] == 3)
			res = sort_three(array);
		else if (array->array[0] == 1)
			res = sort_three(array);
	}
	else if (array->array[0] == 3)
	{
		rotate_a(array);
		res = two_stack(array);
	}
	return (res);
}

int	three_stack(t_array *array)
{
	int	res;

	res = 0;
	if (array->len == 2)
		res = two_stack(array);
	if (array->len == 3)
		res = sort_three(array);
	if (is_sorted(array) == 0)
		return (res);
	return (-1);
}

/*ここのソートの考え方としてはソートする関数で問題なくできていれば0をかえる。ダメな時は-1を返す*/

int	stack_control(t_array *array)
{
	int	result;

	result = 0;
	if (is_sorted(array) == 0)
		return (0);
	if (array->len <= 3)
		result = three_stack(array);
	if (result == -1)
		return (-1);
	return (0);
}

	// if (array->len > 3 && array->len <= 6)
	// 	result == six_stack(array);
