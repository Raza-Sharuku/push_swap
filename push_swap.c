/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:46:59 by sraza             #+#    #+#             */
/*   Updated: 2023/04/02 16:37:44 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main (int argc, char *argv[])
{
	int	i;
	
	i = 0;
	if (ft_error_check(argc, argv) < 0)
	{
		printf("Error");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		printf("%s\n",argv[i]);
		i++;
	}
	return (0);
}