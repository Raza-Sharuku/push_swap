/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:27:53 by sraza             #+#    #+#             */
/*   Updated: 2023/04/17 12:13:55 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/* printf("i = %ld : j = %ld\n", ft_atoi_swap(list[i]), 
ft_atoi_swap(list[i + j]));
*/
static int	is_same_num(char **list, t_array *array)
{
	int	i;
	int	j;

	i = 0;
	array->array = (int *)malloc((sizeof (int)) * (array->len));
	if (array->array == NULL)
		return (-1);
	while (list[i] && i < array->len)
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
		array->array[i] = ft_atoi_swap(list[i]);
		i++;
	}
	return (0);
}

/*ここでは送られてきた配列のそれぞれに対して中身のエラーがないかを判定する。
判定内容
1 空白、＋ー数字以外があった場合はエラー
2 二次元リストを作成して、配列が空白のみのときエラー
3 配列の中身が２つ以上の時、1を返す（受け取り側で引数がさらにある時はエラー）　
　*/
static int	check_str(char *str)
{
	int		i;
	char	**list;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' '
				&& str[i] != '-' && str[i] != '+'))
			return (-1);
		i++;
	}
	if (ft_atoi_swap(str) > (long)INT_MAX)
		return (-1);
	list = ft_split(str, ' ');
	if (list[0] == NULL)
		return (-1);
	i = 0;
	while (list[i])
		i++;
	if ((i - 1) >= 1)
		return (1);
	ft_free_swap(list);
	return (0);
}

/*ここでは１つ文字列にたくさんの数字が入っているものをMallocしてそれぞれの数に分ける。
そして２次元配列になったものを次に判定式に渡してエラー値を返す　*/

static	int	ft_malloc(char const *argv, t_array *array)
{
	int		i;
	char	**list;

	i = 0;
	list = ft_split(argv, ' ');
	if (list[0] == NULL)
		return (-1);
	while (list[i])
		i++;
	array->len = i;
	if (is_same_num(list, array) < 0)
	{
		ft_free_swap(list);
		return (-1);
	}
	ft_free_swap(list);
	return (0);
}

/*ここでは１つ文字列にたくさんの数字が貼っているものなの中でスペースだけのものを弾く
複数の引数として貰えているのかを判定する。
それぞれの関数に渡して返り値に応じてエラーの反応を返す　*/

static	int	ft_arg_check(int argc, char *argv[], int counter, t_array *array)
{
	array->len = argc - 1;
	if (counter == 1 && ft_malloc(argv[1], array) < 0)
		return (-1);
	if (argc > 2 && is_same_num(&argv[1], array))
		return (-1);
	return (0);
}

/* この段階では、””のものがないこと、引数が二つ以上あって、最初のスペースを除く
スペースが二回以上あったらエラーを出す。→引数の中に複数の数字があるものはエラー
また、複数の値を持つ引数１と次に引数が””だった場合はエラー
*/
int	ft_error_check(int argc, char *argv[], t_array *array)
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
	if (ft_arg_check(argc, argv, s_counter, array) < 0)
		return (-1);
	return (0);
}
