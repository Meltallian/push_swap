/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/14 16:33:30 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief This function checks if the int from stack A is
 * higher than all int from stack B or lower than all int
 * from stack B. if it is, it returns 1.
 * @param data
 * @param index
 * @return int
 */

int	a_big_small(t_data *data, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->y_b)
	{
		if (data->stacks[A][index].value > data->stacks[B][i].value)
			count++;
		i++;
	}
	if (count == i || count == 0)
		return (1);
	return (0);
}
/**
 * @brief This function finds the index of the highest int
 * in stack B and returns it.
 * @param data
 * @return int
 */
int	find_big_b(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stacks[B][i].value;
	while (i < data->y_b)
	{
		if (data->stacks[B][i].value > temp)
			temp = data->stacks[B][i].value;
		i++;
	}
	i = 0;
	while (i < data->y_b)
	{
		if (temp == data->stacks[B][i].value)
			return (i);
		i++;
	}
	return (0);
}

void	calcul(t_data *data)
{
	int	i;
	int	*count[data->y_a];
	int	temp;

	i = 0;
	while (i < data->y_a)
	{
		if (a_big_small(data, data->stacks[B][i].value) == 1)
		{

		}
		temp = a_higher_than_b(data, i);
		count[i] = temp;
		i++;
	}
}