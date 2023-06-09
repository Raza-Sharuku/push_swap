/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:02:01 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/17 11:49:44 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	four_five_stack(t_array *s)
{
	int	i;
	int	res;

	i = 0;
	while (i < s->len)
	{
		if (s->array[s->flg] == 4 || s->array[s->flg] == 5)
			push_b(s);
		else
			rotate_a(s);
		if ((s->len == 4 && s->flg == 1) || (s->len == 5 && s->flg == 2))
			break ;
		i++;
	}
	if (s->flg == 2 && s->array[0] < s->array[1])
		swap_b(s);
	res = three_stack(s);
	return (res);
}

int	six_stack(t_array *s, int res)
{
	while (res < s->len)
	{
		if (s->array[s->flg] == 1 || s->array[s->flg] == 2
			|| s->array[s->flg] == 3)
			push_b(s);
		else
			rotate_a(s);
		if ((s->len == 4 && s->flg == 1) || (s->len == 5 && s->flg == 2)
			|| (s->len == 6 && s->flg == 3))
			break ;
		res++;
	}
	res = sort_three(s, 6, 5, 4);
	res = sort_three_desend(s, 1, 2, 3);
	while (s->flg != 0)
		push_a(s);
	return (res);
}

int	two_stack_desend(t_array *s)
{
	if (s->array[s->flg - 1] < s->array[s->flg - 2])
		swap_b(s);
	if (s->array[s->flg - 1] > s->array[s->flg - 2])
		return (0);
	else
		return (-1);
}

int	sort_three_desend(t_array *s, int min, int mid, int max)
{
	int	res;

	res = 0;
	if (s->array[s->flg - 1] == max)
	{
		if (s->array[s->flg - 2] == mid)
			return (res);
		rev_rotate_rb(s);
		res = two_stack_desend(s);
	}
	else if (s->array[s->flg -1] == mid)
	{
		if (s->array[s->flg - 2] == max)
			swap_b(s);
		else if (s->array[s->flg - 2] == min)
			rev_rotate_rb(s);
	}
	else if (s->array[s->flg - 1] == min)
	{
		rotate_b(s);
		res = two_stack_desend(s);
	}
	return (res);
}

/*ここではBスタックに１２３をAスタックに４５６が来るようにする*/
int	six_sort(t_array *s, int res)
{
	if (s->len == 4 || s->len == 5)
	{
		res = four_five_stack(s);
		while (s->flg != 0)
		{
			push_a(s);
			rotate_a(s);
		}
	}
	else if (s->len == 6)
		res = six_stack(s, 0);
	res = is_sorted(s);
	return (res);
}
