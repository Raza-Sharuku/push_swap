/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_perform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:09:37 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/12 13:43:16 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*rotate_a(t_array *array)
{
	int	i;
	int	tmp;

	i = array->flg;
	if (array->len - array->flg < 2)
		return (array);
	else
	{
		tmp = array->array[array->flg];
		while (i < array->len - 1)
		{
			array->array[i] = array->array[i + 1];
			i++;
		}
		array->array[array->len - 1] = tmp;
		write(1, "ra\n", 3);
	}
	return (array);
}

void	*rotate_b(t_array *array)
{
	int	i;
	int	tmp;

	i = array->flg - 2;
	if (array->flg < 1)
		return (array);
	else
	{
		tmp = array->array[array->flg - 1];
		while (i >= 0)
		{
			array->array[i + 1] = array->array[i];
			i--;
		}
		array->array[0] = tmp;
		write(1, "rb\n", 3);
	}
	return (array);
}

void	*rotate_rr(t_array *array)
{
	rotate_a(array);
	rotate_b(array);
	return (array);
}
