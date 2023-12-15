/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/15 15:40:15 by jbidaux          ###   ########.fr       */
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
	i = 0;
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
 * @brief Calculates the amount of rotations needed for index int
 * to get placed at the top of stack A based on where int is in
 * stack A.
 * @param data
 * @param index
 * @return int
 */
t_rota_info	rota_for_a(t_data *data, int index)
{
	int	midpoint;
	t_rota_info	rot;

	rot.direction = 'n';
	rot.rotations = 0;
	midpoint = data->y_a / 2;
	if (index <= midpoint)
		rot.rotations = index;
	else
	{
		rot.rotations = data->y_a - index;
		rot.direction = 'r';
	}
	return (rot);
}

/**
 * @brief calculates number of rotations in stack b to account
 * for int index at the top of stack a.
 * @param data
 * @param index
 * @return int
 */
t_rota_info	mid_stack_b(t_data *data, int index)
{
	int			midpoint;
	int			i;
	t_rota_info	info;

	info.rotations = 0;
	info.direction = 'n';
	i = data->y_b - 1;
	midpoint = data->y_b / 2;
	while (i >= 0)
	{
		if (data->stacks[A][index].value < data->stacks[B][i].value)
		{
			info.rotations = data->y_b - i - 1;
			break ;
		}
		i--;
	}
	if (info.rotations > midpoint)
	{
		info.rotations = data->y_b - info.rotations;
		info.direction = 'r';
	}
	return (info);
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
	int			midpoint;
	int			total_rotations;
	int			combined_rotations;
	t_rota_info	rota_info_a;
	t_rota_info	rota_info_b;

	total_rotations = 0;
	midpoint = data->y_a / 2;
	rota_info_a = rota_for_a(data, index);
	rota_info_b = mid_stack_b(data, index);
	combined_rotations = min(rota_info_a.rotations, rota_info_b.rotations);
	if (int_a_max_or_min(data, index) == 1
		|| int_a_max_or_min(data, index) == 2)
	{
		if (index <= midpoint && if_big_b_top(data) == 1)
			return (index + 1);
		if (index > midpoint && if_big_b_top(data) == 1)
			return (data->y_a - index + 1);
		if (index <= midpoint)
			return (index + 2);
		if (index > midpoint)
			return (data->y_a - index + 2);
	}
	else
	{
		total_rotations = combined_rotations + (rota_info_a.rotations
			- combined_rotations) + (rota_info_b.rotations
			- combined_rotations) + 1;
	}
	return (total_rotations);
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
void	master(t_data *data)
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
