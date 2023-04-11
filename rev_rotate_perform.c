/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_perform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:12:06 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/11 10:14:37 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*rev_rotate_ra(t_array *array)
{
	int	i;
	int	tmp;

	i = array->len - 1;
	if (array->len - array->flag_ab < 2)
		return (array);
	else
	{
		tmp = array->array[array->len - 1];
		while (i >= array->flag_ab)
		{
			array->array[i + 1] = array->array[i];
			i--;
		}
		array->array[array->flag_ab] = tmp;
		write (1, "rra\n", 4);
	}
	return (array);
}

void	*rev_rotate_rb(t_array *array)
{
	int	i;
	int	tmp;

	i = 0;
	if (array->flag_ab < 1)
		return (array);
	else
	{
		tmp = array->array[0];
		while (i < array->flag_ab - 1)
		{
			array->array[i] = array->array[i + 1];
			i++;
		}
		array->array[i] = tmp;
		write(1, "rrb\n", 4);
	}
	return (array);
}

void	*rev_rotate_rrr(t_array *array)
{
	rev_rotate_ra(array);
	rev_rotate_rb(array);
	return (array);
}
