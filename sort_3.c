/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:59:15 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/16 13:42:41 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*　push_alternateについて
div = 3 の時をイメージして考えてみる
［1, 2, 3, 4, 5 , 6, 7, 8 ,9 , 10, 11, 12］
最初に送りたい数は1-3 つまり　1 + (div * p) 以上のところ -> div * pを超えるに変換できる。
かつ　div * (p + 1)以下まで　while 文なので終わりを示すためにflgとlenの大小で終了
次に4-6の数は送って反対側に持ってきたい
->さっきのdiv * (p + 1)を超える値からdiv * (p + 2)以下までの範囲を取り入れる
こちらもwhileなので終わりを決めてあげる
次にどっちにも入っていない場合かつｋは上記の二つの処理分の個数まで処理させたいので、
k < 2 * a->divの状態ならrotateしていいということにする。
これはつまり、もう必要回数分pushが終わっているという合図なので、処理を終了してpの値を増やす。
*/
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
	// k = check_array(s);
	a->rot = 0;
	return (p + 2);
}

int	patterns(t_array *s, t_algo *a)
{
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
		a->div = 200;
	return (a->div);
}

int	max_sort(t_array *s)
{
	int		res;
	t_algo	*a;
	int		p;

	res = 0;
	p = 0;
	a = malloc(sizeof (t_algo));
	a->div = patterns(s, a);
	// printf("a -> div = %i \n", a->div);
	while ((s->flg < s->len))
		p = push_alternate(s, a, p, 0);
	// p = check_array(s);
	// printf("p = %i \n", p);
	if (s->len % a->div == 0)
		p = s->len / a->div - 1;
	if (s->len % a->div > 0)
		p = s->len / a->div;
	// printf("p = %i \n", p);
	// printf("\n------------------ can i push_a correctly? ----------------\n");
	while (res < 5)
	{
		// if (p % 2 == 1)
		// 	p =  rev_push_a(s, a, p, 0);
		if (p % 2 == 0)
			p = push_rotate_a(s, a, p, 0);
		if (p < 0)
			return (-1);
		res++;
	}
	// printf("\n------------------ can i push_a correctly? ----------------\n");
	return (0);
}

// int	rev_push_a(t_array *s, t_algo *a, int p, int i)
// {



// 	return (p - 1);
// }