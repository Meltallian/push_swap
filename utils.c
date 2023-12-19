/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:41:29 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/19 16:38:26 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	count;
	size_t	j;

	count = 0;
	while (s1[count] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[count] == s2[j])
				return (count);
			j++;
		}
		j = 0;
		count++;
	}
	return (count);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/**
 * @brief check whether stack a is fully sorted (1).
 * also checks whether it is full. return -1 if not full
 * and 0 if not sorted.
 * @param data
 * @return int
 */
int	is_stack_a_sorted(t_data *data)
{
	int	i;

	i = 0;
	if (data->y_a != data->length_tot)
		return (-1);
	while (i < data->length_tot - 1)
	{
		if (data->stacks[A][i].value > data->stacks[A][i + 1].value)
			return (0);
		i++;
	}
	return (1);
}