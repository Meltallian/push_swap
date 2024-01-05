/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:48:38 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/05 16:55:55 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief checks whether biggest int of stack B is at its top.
 * yes is 1, no is 0.
 * @param data
 * @return int
 */
int	if_big_b_top(t_data *data)
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
	if (temp == data->stacks[B][0].value)
		return (1);
	return (0);
}

/**
 * @brief This function checks if the int from stack A is
 * higher than all int from stack B (returns 1) or lower than all int
 * from stack B (returns 2).
 * @param data
 * @param index
 * @return int
 */

int	is_max_or_min(t_data *data, int index)
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
	if (count == i)
		return (1);
	if (count == 0)
		return (2);
	return (0);
}

/**
 * @brief checks if index 0 stack b is max or min of stack a.
 * highest is 1. lowest is 2. 0 if none of those.
 *
 * @param data
 * @return int
 */
int	is_max_or_min_back(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->y_a)
	{
		if (data->stacks[B][0].value > data->stacks[A][i].value)
			count++;
		i++;
	}
	if (count == i)
		return (1);
	if (count == 0)
		return (2);
	return (0);
}

/**
 * @brief Returns index of max int in stack b
 *
 * @param data
 * @return int
 */
int	index_max_b(t_data *data)
{
	int	i;
	int	temp;
	int	index;

	i = 0;
	index = 0;
	temp = data->stacks[B][i].value;
	while (i < data->y_b)
	{
		if (data->stacks[B][i].value > temp)
		{
			temp = data->stacks[B][i].value;
			index = i;
		}
		i++;
	}
	if (temp == data->stacks[B][0].value)
		return (0);
	return (index);
}

int	index_min_a(t_data *data)
{
	int	i;
	int	temp;
	int	index;

	i = 0;
	index = 0;
	temp = data->stacks[A][i].value;
	while (i < data->y_a)
	{
		if (data->stacks[A][i].value < temp)
		{
			temp = data->stacks[A][i].value;
			index = i;
		}
		i++;
	}
	if (temp == data->stacks[A][0].value)
		return (0);
	return (index);
}
