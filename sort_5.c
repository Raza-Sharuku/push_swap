/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:13 by sraza             #+#    #+#             */
/*   Updated: 2023/04/17 10:47:53 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	p_negative_push(t_array *s, t_algo *a)
{
	rev_rotate_rb(s);
	push_a(s);
	a->push++;
	if (a->push % 2 == 0)
	{
		if (s->array[s->flg] > s->array[s->flg + 1])
			swap_a(s);
		a->max = a->max - 2;
	}
}

int	rev_push_a(t_array *s, t_algo *a, int p, int mod)
{
	// int i;

	// printf("\n --------- start of push back to A (rev_push_a)  ---------\n");
	mod = set_max_val(s, a, p, mod);
	while (a->push < mod && s->array[0] > a->div * p)
	{
		while (a->push < mod && (s->array[0] == a->max || s->array[0] == a->max - 1))
			p_negative_push(s, a);
		// printf("a->max = %i\n", a->max);
		// printf("a->push = %i\n", a->push);
		if (s->flg > 0 && s->array[0] >= a->div * p && (s->array[0] != a->max && s->array[0] != a->max - 1))
		{
			rev_rotate_rb(s);
			a->rev++;
			// printf("a->rev = %i\n", a->rev);
		}
		if (a->push + a->rev >= mod)
		{
			while (a->rev > 0 && (s->array[0] != a->max && s->array[0] != a->max - 1))
			{
				rotate_b(s);
				a->rev--;
			}
		}
		// printf("p = %i\n", p);
		// i = check_array(s);
	}
	return (p - 1);
}
