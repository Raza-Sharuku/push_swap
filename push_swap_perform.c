/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_perform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:27:17 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/10 19:02:21 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*push_a(t_array *array)
{
	if (array->flag_ab == 0)
		return (array);
	else
		array->flag_ab = array->flag_ab - 1;
	return (array);
}

void	*push_b(t_array *array)
{
	if (array->flag_ab >= array->len)
		return (array);
	else
		array->flag_ab = array->flag_ab + 1;
	return (array);
}

void	*swap_a(t_array *array)
{
	int	tmp;

	tmp = 0;
	if (array->len - array->flag_ab < 2)
		return (array);
	else 
	{
		tmp = array->array[array->flag_ab];
		array->array[array->flag_ab] = array->array[array->flag_ab + 1];
		array->array[array->flag_ab + 1] = tmp;
	}
	return (array);
}

void	*swap_b(t_array *array)
{
	int	tmp;

	tmp = 0;
	if (array->flag_ab < 2)
		array->array = array->array;
	else 
	{
		tmp = array->array[array->flag_ab - 1];
		array->array[array->flag_ab - 1] = array->array[array->flag_ab - 2];
		array->array[array->flag_ab - 2] = tmp;
	}
	return (array);
}

void	*swap_ab(t_array *array)
{
	swap_a(array);
	swap_b(array);
	return (array);
}
