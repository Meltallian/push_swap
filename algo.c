/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/14 18:49:16 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief This function checks if the int from stack A is
 * higher than all int from stack B (returns 1) or lower than all int
 * from stack B (returns 2).
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
	if (count == i)
		return (1);
	if (count == 0)
		return (2);
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

int	calcul(t_data *data, int i)
{
/* 	int	j;

	j = 0; */
	if (a_big_small(data, i) == 1)
		return (1);
	if (a_big_small(data, i) == 2)
		return (2);
	return (0);
}
/**
 * @brief This function stores and returns potential operation amounts
 * in a array of int for each int in stack A.
 * The results of the calculus is the number of operations needed for the int
 * from stack A to be moved correctly on top of stack B.
 * @param data
 */
void	calculus_array(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	while (i < data->y_a)
	{
		temp = calcul(data, i);
		data->cal[i] = temp;
		i++;
	}
}
/**
 * @brief This function actually does the moving based on the calculus.
 *
 * @param data
 */
void master(t_data *data)
{
/* 	int	i;

	i = 0; */
	calculus_array(data);
	if (data->cal[0] == 1)
		pb(data);
	if (data->cal[0] == 2)
	{
		pb(data);
		rb(data);
	}
}