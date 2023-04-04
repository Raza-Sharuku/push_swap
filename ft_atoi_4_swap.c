/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_4_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:54:47 by sraza             #+#    #+#             */
/*   Updated: 2023/04/04 21:15:03 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	char	*ft_isspace_swap(const char *str)
{
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\t' || *str == '\v' || *str == '\r')
		str++;
	return ((char *)str);
}

static	long	ft_max_swap(const char *str)
{
	long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (num > ((LONG_MAX - (*str - '0')) / 10))
		{
			num = LONG_MAX;
			break ;
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

static	long	ft_min_swap(const char *str)
{
	long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (num < ((LONG_MIN + (*str - '0')) / 10))
		{
			num = LONG_MIN;
			break ;
		}
		num = num * 10 - (*str - '0');
		str++;
	}
	return (num);
}

long	ft_atoi_swap(const char *str)
{
	long	num;
	int		sign;

	str = ft_isspace_swap(str);
	sign = 1;
	num = 0;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if ((*str == '+' || *str == '-')
			&& (*(str + 1) == '+' || *(str + 1) == '-'))
			return (0);
		else if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	if (sign == 1)
		num = ft_max_swap((char *)str);
	if (sign == -1)
		num = ft_min_swap((char *)str);
	if (num > INT_MAX || num < INT_MIN)
		return ((long)INT_MAX + 1);
	return (num);
}
