/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:27:53 by sraza             #+#    #+#             */
/*   Updated: 2023/04/04 21:24:21 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/* printf("i = %ld : j = %ld\n", ft_atoi_swap(list[i]), 
ft_atoi_swap(list[i + j]));
*/
static int	is_same_num(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 1;
		while (list[i + j])
		{
			if (ft_atoi_swap(list[i]) == ft_atoi_swap(list[i + j])
				&& list[i] != 0)
				return (-1);
			j++;
		}
		if (ft_atoi_swap(list[i]) > (long)INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

/*ここでは送られてきた配列のそれぞれに対して中身のエラーがないかを判定する。
判定内容
1 空白、＋ーがあった場合は飛ばす
２　

　*/
static int	check_str(char *str)
{
	int	i;
	int	counter;
	int	w_counter;

	i = 0;
	counter = 0;
	w_counter = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			w_counter++;
		if (str[i] == ' ')
			counter++;
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' '
				&& str[i] != '-' && str[i] != '+'))
			return (-1);
		i++;
	}
	if (w_counter == 0)
		return (-1);
	if (counter != 0)
		return (1);
	return (0);
}

/*ここでは１つ文字列にたくさんの数字が入っているものをMallocしてそれぞれの数に分ける。
そして２次元配列になったものを次に判定式に渡してエラー値を返す　*/

static	int	ft_malloc(char const *argv)
{
	int		i;
	char	**list;

	i = 0;
	list = ft_split(argv, ' ');
	if (list[0] == NULL)
		return (-1);
	if (is_same_num(list) < 0)
		return (-1);
	while (list[i])
	{
		printf("%s\n", list[i]);
		i++;
	}
	printf("finished the split !!\n");
	return (0);
}

/*ここでは１つ文字列にたくさんの数字が貼っているものなの中でスペースだけのものを弾く
複数の引数として貰えているのかを判定する。
それぞれの関数に渡して返り値に応じてエラーの反応を返す　*/

static	int	ft_arg_check(int argc, char *argv[], int counter)
{
	if (counter == 1 && ft_malloc(argv[1]) < 0)
		return (-1);
	if (argc > 2 && is_same_num(argv))
		return (-1);
	return (0);
}

/* この段階では、””のものがないこと、引数が二つ以上あって、最初のスペースを除く
スペースが二回以上あったらエラーを出す。→引数の中に複数の数字があるものはエラー
また、複数の値を持つ引数１と次に引数が””だった場合はエラー
*/
int	ft_error_check(int argc, char *argv[])
{
	int	i;
	int	s_counter;

	i = 1;
	s_counter = 0;
	while (argv[i] && i < argc)
	{
		if (argv[i][0] == 0)
			return (-1);
		if (check_str(argv[i]) < 0)
			return (-1);
		if (check_str(argv[i]) == 1)
			s_counter++;
		if (s_counter == 1 && argv[i + 1])
			return (-1);
		i++;
	}
	printf("before arg check\n");
	if (ft_arg_check(argc, argv, s_counter) < 0)
		return (-1);
	return (0);
}
