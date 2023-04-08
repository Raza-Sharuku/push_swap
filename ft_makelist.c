/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:45:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/07 12:40:08 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/* In this file, first ft_makelist check numbers of arguments. Then, if 
arguments are 2, it will pass the whole argument to  *ft_makelist_argc2 and 
split the argv[1]. and change the form of list one by one from char to int.
otherwise, arguments are more then three, it will pass the whole argument to 
*ft_makelist_argc3 which convert each argument to form of int and stored it 
in int_list.
*/

int	*ft_makelist_argc2(char *argv[])
{
	char	**list;
	int		*int_list;
	int		i;
	int		lst_len;

	i = 0;
	list = ft_split(argv[1], ' ');
	while (list[i])
		i++;
	lst_len = i;
	int_list = (int *)malloc(sizeof(int) * (lst_len + 1));
	i = 0;
	while (i < lst_len)
	{
		int_list[i] = ft_atoi_swap(list[i]);
		i++;
	}
	return (int_list);
}

int	*ft_makelist_argc3(int argc, char *argv[])
{
	int		*int_list;
	int		i;

	i = 0;
	int_list = (int *)malloc(sizeof(int) * (argc));
	while (i < argc - 1)
	{
		int_list[i] = ft_atoi_swap(argv[i + 1]);
		i++;
	}
	return (int_list);
}

int	*ft_makelist(int argc, char *argv[])
{
	int		*int_list;

	if (argc == 2)
		int_list = ft_makelist_argc2(argv);
	else if (argc > 2)
		int_list = ft_makelist_argc3(argc, argv);
	else
		int_list = NULL;
	return (int_list);
}
