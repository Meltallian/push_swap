/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/18 15:20:21 by jbidaux          ###   ########.fr       */
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
t_rota_info	rota_for_b(t_data *data, int index)
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

int	calcul_max_min_special(t_data *data, int index)
{
	int		rotations_a;
	char	direction_a;
	int		midpoint_a;
	int		rotations_b;
	int		total_rotations;

	rotations_a = 0;
	total_rotations = 0;
	rotations_b = 0;
	direction_a = 'n';
	midpoint_a = data->y_a / 2;
	if (index <= midpoint_a)
		rotations_a = index;
	else
	{
		rotations_a = data->y_a - index;
		direction_a = 'r';
	}
	if (if_big_b_top(data) == 0)
		rotations_b = 1;
	if (direction_a == 'n' && rotations_b > 0 && rotations_a > 0)
		total_rotations = rotations_a;
	else
		total_rotations = rotations_a + rotations_b;
	total_rotations += 1;
	return (total_rotations);
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
	int					total_rotations;
	int					combined_rotations;
	int					add_rota_a;
	int					add_rota_b;
	const t_rota_info	rota_info_a = rota_for_a(data, index);
	const t_rota_info	rota_info_b = rota_for_b(data, index);

	total_rotations = 0;
	add_rota_a = 0;
	add_rota_b = 0;
	if (int_a_max_or_min(data, index) != 0)
		return (calcul_max_min_special(data, index));
	if (int_a_max_or_min(data, index) == 0)
	{
		if (rota_info_a.rotations == 0 && rota_info_b.rotations == 0)
			total_rotations = 1;
		else if (rota_info_a.direction == rota_info_b.direction)
		{
			combined_rotations = min(rota_info_a.rotations, rota_info_b.rotations);
			total_rotations = combined_rotations;
			total_rotations += max(rota_info_a.rotations - combined_rotations, 0)
				+ max(rota_info_b.rotations - combined_rotations, 0) + 1;
		}
		else
			total_rotations = rota_info_a.rotations + rota_info_b.rotations + 1;
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
