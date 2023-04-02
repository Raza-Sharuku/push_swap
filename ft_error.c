/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:27:53 by sraza             #+#    #+#             */
/*   Updated: 2023/04/02 21:01:41 by sraza            ###   ########.fr       */
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
			if (ft_atoi(list[i]) == ft_atoi(list[i + j]) && list[i] != '\0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

static	int	ft_malloc(char const *argv)
{
	int		i;
	char	**list;

	i = 0;
	list = ft_split(argv, ' ');
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

static	int	ft_arg_check(int argc, char *argv[], int counter)
{
	int	i;

	i = 0;
	if (counter == 1 && ft_malloc(argv[1]) < 0)
		return (-1);
	else if (argc > 2 && is_same_num(argv))
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
