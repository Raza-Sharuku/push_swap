/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:59:15 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/17 11:55:11 by razasharuku      ###   ########.fr       */
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
	a->rot = 0;
	while (s->flg < s->len && (k < 2 * a->div) && (a->rot <= s->len))
	{
		while (s->flg < s->len && s->array[s->flg]
			> a->div * p && s->array[s->flg] <= a->div * (p + 1))
		{
			push_b(s);
			k++;
		}
		while (s->flg < s->len && s->array[s->flg]
			> (a->div * (p + 1)) && s->array[s->flg] <= (a->div * (p + 2)))
		{
			push_b(s);
			rotate_b(s);
			k++;
		}
		if (s->flg < s->len && (k < 2 * a->div)
			&& s->array[s->flg] > a->div * (p + 2))
		{
			rotate_a(s);
			a->rot++;
		}
	}
	return (p + 2);
}

int	patterns(t_array *s, t_algo *a)
{
	if (s->len <= 10)
		a->div = 2;
	if (s->len > 10 && s->len <= 50)
		a->div = 10;
	if (s->len > 50 && s->len <= 100)
		a->div = 12;
	if (s->len > 100 && s->len <= 500)
		a->div = 22;
	if (s->len > 500)
		a->div = 50;
	return (a->div);
}

int	max_sort(t_array *s)
{
	t_algo	*a;
	int		p;

	p = 0;
	a = malloc(sizeof (t_algo));
	a->div = patterns(s, a);
	while ((s->flg < s->len))
	{
		p = push_alternate(s, a, p, 0);
	}
	if (s->len % a->div == 0)
		p = s->len / a->div - 1;
	if (s->len % a->div > 0)
		p = s->len / a->div;
	while (p >= 0)
	{
		if (p % 2 == 1)
			p = rev_push_a(s, a, p, 0);
		if (p % 2 == 0)
			p = push_rotate_a(s, a, p, 0);
	}
	free(a);
	return (0);
}
