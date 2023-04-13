/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:49:54 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/13 10:38:38 by razasharuku      ###   ########.fr       */
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

int	two_stack(t_array *s)
{
	if (s->array[s->flg] > s->array[s->flg + 1])
		swap_a(s);
	if (s->array[s->flg] < s->array[s->flg + 1])
		return (0);
	else
		return (-1);
}

int	sort_three(t_array *s, int max, int mid, int min)
{
	int	res;

	res = 0;
	if (s->array[s->flg] == min)
	{
		if (s->array[s->flg + 1] == mid)
			return (res);
		rev_rotate_ra(s);
		res = two_stack(s);
	}
	else if (s->array[s->flg] == mid)
	{
		if (s->array[s->flg + 1] == min)
			swap_a(s);
		else if (s->array[s->flg + 1] == max)
			rev_rotate_ra(s);
	}
	else if (s->array[s->flg] == max)
	{
		rotate_a(s);
		res = two_stack(s);
	}
	return (res);
}

int	three_stack(t_array *s)
{
	int	res;

	res = 0;
	if (s->len - s->flg == 2)
		res = two_stack(s);
	if (s->len - s->flg == 3)
		res = sort_three(s, 3, 2, 1);
	return (res);
}

/*ここのソートの考え方としてはソートする関数で問題なくできていれば0をかえる。ダメな時は-1を返す*/

int	stack_control(t_array *s)
{
	int	result;

	result = 0;
	if (is_sorted(s) == 0)
		return (0);
	if (s->len - s->flg <= 3)
		result = three_stack(s);
	if (s->len - s->flg > 3 && s->len - s->flg <= 6)
		result = six_sort(s);
	if (result == -1)
		return (-1);
	return (0);
}
