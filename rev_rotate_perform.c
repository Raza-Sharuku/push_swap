/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_perform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:12:06 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/16 16:34:13 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*rev_rotate_ra(t_array *s)
{
	int	i;
	int	tmp;

	i = s->len - 1;
	if (s->len - s->flg < 2)
		return (s);
	else
	{
		tmp = s->array[s->len - 1];
		while (i >= s->flg)
		{
			s->array[i + 1] = s->array[i];
			i--;
		}
		s->array[s->flg] = tmp;
		write (1, "rra\n", 4);
	}
	return (s);
}

void	*rev_rotate_rb(t_array *array)
{
	int	i;
	int	tmp;

	i = 0;
	if (array->flg < 1)
		return (array);
	else
	{
		tmp = array->array[0];
		while (i < array->flg - 1)
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
