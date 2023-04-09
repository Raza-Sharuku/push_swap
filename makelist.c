/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:20:32 by sraza             #+#    #+#             */
/*   Updated: 2023/04/09 15:11:57 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_S_list	*ft_newlst(int value)
{
	t_S_list	*new;

	new = malloc(sizeof(t_S_list));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_S_list	*ft_makelist(t_array *array)
{
	t_S_list	*top;
	t_S_list	*node;
	t_S_list	*new;
	int			i;

	top = ft_newlst(array->array[0]);
	node = ft_newlst(array->array[1]);
	top->next = node;
	i = 2;
	while (i < array->len)
	{
		new = ft_newlst(array->array[i]);
		node->next = new;
		node = new;
		i++;
	}
	return (top);
}
