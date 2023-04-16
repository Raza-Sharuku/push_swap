/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:37:09 by sraza             #+#    #+#             */
/*   Updated: 2023/04/16 20:52:31 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	set_max_val(t_array *s, t_algo *a, int p, int mod)
{
	int	i;

	mod = a->div;
	if (s->flg % a->div > 0)
		mod = s->flg % a->div;
	i = 0;
	a->push = 0;
	a->rot = 0;
	a->rev = 0;
	a->max = 0;
	while (p % 2 == 0 && i < mod)
	{
		if (s->flg >= i + 1 && s->array[s->flg - 1 - i] > a->max)
			a->max = s->array[s->flg - 1 - i];
		// printf("a->max = %i\n", a->max);
		i++;
	}
	while (p % 2 == 1 && i < mod)
	{
		if (s->array[i] > a->max)
			a->max = s->array[i];
		i++;
	}
	return (mod);
}

void	p_positive_push(t_array *s, t_algo *a)
{
	push_a(s);
	a->push++;
	if (a->push % 2 == 0)
	{
		if (s->array[s->flg] > s->array[s->flg + 1])
			swap_a(s);
		a->max = a->max - 2;
	}
}

void	p_rev_rot(t_array *s, t_algo *a)
{
	while (s->flg > 0 && a->rot > 0
		&& (s->array[s->flg - 1] != a->max
			&& s->array[s->flg - 1] != a->max - 1))
	{
		rev_rotate_rb(s);
		a->rot--;
	}
}

// void	last_push(t_array *s, t_algo *a, int p, int mod)
// {
// 	while (s->flg > 0 && a->push < mod && s->array[s->flg - 1] >= a->div * p)
// 	{
// 		while (s->flg > 0 && (s->array[s->flg - 1] == a->max || s->array[s->flg - 1] == a->max - 1))
// 			p_positive_push(s, a);
// 		if (s->flg > 0 && s->array[s->flg - 1] >= a->div * p && (s->array[s->flg - 1] != a->max && s->array[s->flg - 1] != a->max - 1))
// 		{
// 			rotate_b(s);
// 			a->rot++;
// 		}
// 		if (a->push + a->rot >= mod)
// 			p_rev_rot(s, a);
// 	}
// }

int	push_rotate_a(t_array *s, t_algo *a, int p, int mod)
{
	// int i;

	mod = set_max_val(s, a, p, mod);
	while (s->flg > 0 && a->push < mod && s->array[s->flg - 1] >= a->div * p)
	{
		// if (p < 1)
		// {
		// 	last_push(s, a, p, mod);
		// 	break ;
		// }
		while (a->push < mod && (s->array[s->flg - 1] == a->max || s->array[s->flg - 1] == a->max - 1))
			p_positive_push(s, a);
		if (s->flg > 0 && s->array[s->flg - 1] >= a->div * p && (s->array[s->flg - 1] != a->max && s->array[s->flg - 1] != a->max - 1))
		{
			rotate_b(s);
			a->rot++;
		}
		if (a->push + a->rot >= mod)
			p_rev_rot(s, a);
	}
	// printf("\n---------  after p positive --------\n");
	// i = check_array(s);
	return (p - 1);
}
