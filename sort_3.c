/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:59:15 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/14 13:02:17 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	push_alternate(t_array *s, t_algo *a, int p, int k)
{
	while ((k < 2 * a->div) && s->flg < s->len && (a->rot <= s->len))
	{
		while (s->array[s->flg] > a->div * p && s->array[s->flg]
			<= a->div * (p + 1) && s->flg < s->len)
		{
			push_b(s);
			k++;
		}
		while (s->array[s->flg] > (a->div * (p + 1)) && s->array[s->flg]
			<= (a->div * (p + 2)) && s->flg < s->len)
		{
			push_b(s);
			rotate_b(s);
			k++;
		}
		if (s->array[s->flg] > (a->div + a->div * (p + 1)) && (k < 2 * a->div))
		{
			rotate_a(s);
			a->rot++;
		}
	}
	a->rot = 0;
	return (p + 2);
}

int	max_sort(t_array *s)
{
	int		res;
	t_algo	*a;
	int		p;

	p = 0;
	a = malloc(sizeof (t_algo));
	if (s->len <= 10)
		a->div = 2;
	if (s->len > 10 && s->len <= 50)
		a->div = 5;
	if (s->len > 50 && s->len <= 100)
		a->div = 10;
	if (s->len > 100 && s->len <= 500)
		a->div = 50;
	if (s->len > 500 && s->len <= 1000)
		a->div = 100;
	if (s->len > 1000)
		a->div = 500;
	printf("a -> div = %i \n", a->div);
	while (p < 5 || (s->flg < s->len))
	{
		p = push_alternate(s, a, p, 0);
		res = check_array(s);
	}
	return (res);
}
