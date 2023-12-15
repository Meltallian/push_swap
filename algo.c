/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/15 10:52:42 by jbidaux          ###   ########.fr       */
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

int	int_a_max_or_min(t_data *data, int index)
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
 * in stack B and returns it. Obsolete since highest int should
 * always be on top of stack B.
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
/**
 * @brief Calculates the amount of rotations needed for index int
 * to get placed at the top of stack A based on where int is in
 * stack A.
 * @param data
 * @param index
 * @return int
 */
int	calculate_rotations_for_a(t_data *data, int index)
{
	int	midpoint;
	int	rotations;

	midpoint = data->y_a / 2;
	if (index <= midpoint)
		rotations = index;
	else
		rotations = data->y_a - index;
	return (rotations);
}
/**
 * @brief calculates
 *
 * @param data
 * @param index
 * @return int
 */
int	mid_stack_b(t_data *data, int index)
{
	int	i;
	int	rotations_needed;

	rotations_needed = 0;
	i = data->y_b - 1;
	while (i >= 0)
	{
		if (data->stacks[B][index].value > data->stacks[A][i].value)
		{
			rotations_needed = data->y_b - i;
			break ;
		}
		i--;
	}
	return (/* rotations_needed + */ calculate_rotations_for_a(data, index));
}

/**
 * @brief This functions does the calculus.
 *
 * @param data
 * @param i
 * @return int
 */
int	calcul(t_data *data, int index)
{
/* 	int	j;

	j = 0; */
	if (int_a_max_or_min(data, index) == 1)
		return (index + 1);
	if (int_a_max_or_min(data, index) == 2)
		return (index + 1);
	else
		return (mid_stack_b(data, index));
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
	int	index;
	int	temp;

	index = 0;
	while (index < data->y_a)
	{
		temp = calcul(data, index);
		data->cal[index] = temp;
		index++;
	}
}
/**
 * @brief This function actually does the moving based on the calculus.
 *
 * @param data
 */
void master(t_data *data)
{
	int	i;

	i = 0;
	calculus_array(data);
/* 	if (data->cal[0] == 1)
		pb(data);
	if (data->cal[0] == 2)
	{
		pb(data);
		rb(data);
	} */
	while (i < data->y_a)
	{
		printf("%d", data->cal[i]);
		i++;
	}
}