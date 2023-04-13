/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:59:15 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/13 22:02:17 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int	push_alternate(t_array *s, t_algo *a)
{
	int	p;
	int	k;

	p = 0;
	k = check_array(s);
	printf("\n----------- checking max_sort ---------------\n");
	while (k < 15)
	{
		printf("s->array[s->flg] = %i , (1 + a->div * p) = %i \n", s->array[s->flg], 1 + a->div * p);
		if (s->array[s->flg] >= (1 + a->div * p) && s->array[s->flg] <= (a->div + a->div * p))
		{
			push_b(s);
		}
		if (s->array[s->flg] >= (1 + a->div * p) && s->array[s->flg] <= (a->div + a->div * p))
		{
			push_b(s);
			rotate_b(s);
		}
		else 
			rotate_a(s);
		k++;
	}
	k = check_array(s);
	k = 0;
	return (k);
}

int	max_sort(t_array *s)
{
	int		res;
	t_algo	*a;

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
	printf("%i \n", a->div);
	res = push_alternate(s, a);
	return (res);
}
