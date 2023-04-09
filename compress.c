/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:39:43 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/09 20:10:44 by sraza            ###   ########.fr       */
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
	printf("\n------------- change the position -----------------\n\n");
	i = -1;
	while (++i < array->len)
		ft_printf("%i , ", position[i]);
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
	printf("\n\n------------- after compress -----------------\n");
	array->array = change_array_position(array, position);
	free(position);
	return (array->array);
}
