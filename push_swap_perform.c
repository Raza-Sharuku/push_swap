/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_perform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:27:17 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/11 09:40:32 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*push_a(t_array *array)
{
	if (array->flag_ab == 0)
		return (array);
	else
	{
		array->flag_ab = array->flag_ab - 1;
		write(1,"pa\n",3);
	}
	return (array);
}

void	*push_b(t_array *array)
{
	if (array->flag_ab >= array->len)
		return (array);
	else
	{
		array->flag_ab = array->flag_ab + 1;
		write(1,"pb\n",3);
	}
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
		write(1,"sa\n",3);
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
		write(1,"sb\n",3);
	}
	return (array);
}

void	*swap_ss(t_array *array)
{
	swap_a(array);
	swap_b(array);
	// write(1,"ss\n",3);
	return (array);
}
