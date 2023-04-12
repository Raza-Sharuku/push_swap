/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:02:01 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/12 17:25:58 by razasharuku      ###   ########.fr       */
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
		res = check_array(s);
		if (s->array[s->flg] == 4 || s->array[s->flg] == 5)
			push_b(s);
		else
			rotate_a(s);
		i++;
	}
	res = check_array(s);
	if (s->array[0] < s->array[1])
		swap_b(s);
	res = stack_control(s);
	push_a(s);
	rotate_a(s);
	push_a(s);
	rotate_a(s);
	return (res);
}

/*ここではBスタックに１２３をAスタックに４５６が来るようにする*/
int	six_sort(t_array *s)
{
	int	res;

	res = 0;
	if (s->len == 4 || s->len == 5)
		res = four_five_stack(s);
	// else if (s->len == 6)
	// 	res = six_stack(s);
	res = is_sorted(s);
	return (res);
}
