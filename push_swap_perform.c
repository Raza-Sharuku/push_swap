/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_perform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:27:17 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/12 13:42:20 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*push_a(t_array *array)
{
	if (array->flg == 0)
		return (array);
	else
	{
		array->flg = array->flg - 1;
		write(1, "pa\n", 3);
	}
	return (array);
}

void	*push_b(t_array *array)
{
	if (array->flg >= array->len)
		return (array);
	else
	{
		array->flg = array->flg + 1;
		write(1, "pb\n", 3);
	}
	return (array);
}

void	*swap_a(t_array *array)
{
	int	tmp;

	tmp = 0;
	if (array->len - array->flg < 2)
		return (array);
	else
	{
		tmp = array->array[array->flg];
		array->array[array->flg] = array->array[array->flg + 1];
		array->array[array->flg + 1] = tmp;
		write(1, "sa\n", 3);
	}
	return (array);
}

void	*swap_b(t_array *array)
{
	int	tmp;

	tmp = 0;
	if (array->flg < 2)
		array->array = array->array;
	else
	{
		tmp = array->array[array->flg - 1];
		array->array[array->flg - 1] = array->array[array->flg - 2];
		array->array[array->flg - 2] = tmp;
		write(1, "sb\n", 3);
	}
	return (array);
}

void	*swap_ss(t_array *array)
{
	swap_a(array);
	swap_b(array);
	return (array);
}
