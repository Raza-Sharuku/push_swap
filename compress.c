/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:39:43 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/13 14:11:14 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	int	*change_array_position(t_array *array, int *position)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->len)
	{
		j = 0;
		while (j < array->len)
		{
			if (array->array[i] == position[j])
			{
				array->array[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (array->array);
}

static	int	*change_positoin(t_array *array, int *position)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < array->len)
	{
		j = 1;
		while (i + j < array->len)
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
	return (position);
}

int	*compress_array(t_array *array)
{
	int	i;
	int	*position;

	i = -1;
	position = (int *)malloc(sizeof(int) * (array->len));
	if (position == NULL)
		free(position);
	while (++i < array->len)
		position[i] = array->array[i];
	position = change_positoin(array, position);
	array->array = change_array_position(array, position);
	free(position);
	return (array->array);
}
