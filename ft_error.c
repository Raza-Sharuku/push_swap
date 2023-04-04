/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:27:53 by sraza             #+#    #+#             */
/*   Updated: 2023/04/04 11:08:23 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
			printf("i = %d : j = %d\n", ft_atoi(list[i]), ft_atoi(list[i + j]));
			if (ft_atoi(list[i]) == ft_atoi(list[i + j]) && list[i] != 0)
				return (-1);
			j++;
		}
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
		if (str[i] == ' ')
			counter++;
		else if (str[i] >= '0' && str[i] <= '9')
			w_counter++;
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			i++;
		else if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
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
	int	counter;

	i = 1;
	counter = 0;
	while (argv[i] && i < argc)
	{
		if (argv[i][0] == 0)
			return (-1);
		if (check_str(argv[i]) < 0)
			return (-1);
		if (check_str(argv[i]) == 1)
			counter++;
		if (counter == 1 && argv[i + 1])
			return (-1);
		i++;
	}
	if (ft_arg_check(argc, argv, counter) < 0)
		return (-1);
	return (0);
}
