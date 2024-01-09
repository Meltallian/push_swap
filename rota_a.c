/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:13:19 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 13:40:02 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rota_for_a_helper(t_data *data, t_rota_info *rot)
{
	const int	midpoint = data->y_a / 2;

	if (is_max_or_min_back(data) != 0)
	{
		rot->rotations = index_min_a(data);
	}
	if (rot->rotations > midpoint)
	{
		rot->rotations = data->y_a - rot->rotations;
		rot->direction = 'r';
	}
}

long int	rota_for_a_helperr(t_data *data, t_rota_info *rot, long int temp, int i)
{
	// printf("\nLook at this \n");
	// D(i);
	// printf(" ,");
	// L(data->stacks[A][i].value);
	// printf(" ,");
	// L(temp);
	// printf(" ,");
	// printf("\nend of check");
	if (data->stacks[A][i].value > temp)
	{
		temp = data->stacks[A][i].value;
		rot->rotations = i + 1;
	}
	return (temp);
}

/**
 * @brief calculates number of rotation needed in stack a
 * to correctly fit index 0 of stack b into it. without the pa.
 *
 * @param data
 * @return t_rota_info
 */
t_rota_info	rota_for_a_back(t_data *data)
{
	t_rota_info	rot;
	int			i;
	long int	temp;

	rot.rotations = 0;
	rot.direction = 'n';
	i = 0;
	temp = -2147483649;
	while (i < data->y_a)
	{
		if (data->stacks[A][i].value < data->stacks[B][0].value)
		{
			temp = rota_for_a_helperr(data, &rot, temp, i);
			if (temp < data->stacks[B][0].value && temp ==
				data->stacks[A][data->y_a - 1].value)
			{
				rot.rotations = 0;
				return (rot);
			}
		}
		i++;
	}
	// D(rot.rotations);
	rota_for_a_helper(data, &rot);
	// D(rot.rotations);
	return (rot);
}

// void	rota_for_a_helperr(t_data *data, t_rota_info *rot, long int temp, int i)
// {
// 	if (data->stacks[A][i].value > temp)
// 	{
// 		temp = data->stacks[A][i].value;
// 		rot->rotations = i + 1;
// 	}
// }

// /**
//  * @brief calculates number of rotation needed in stack a
//  * to correctly fit index 0 of stack b into it. without the pa.
//  *
//  * @param data
//  * @return t_rota_info
//  */
// t_rota_info	rota_for_a_back(t_data *data)
// {
// 	t_rota_info	rot;
// 	int			i;
// 	long int	temp;

// 	rot.rotations = 0;
// 	rot.direction = 'n';
// 	i = 0;
// 	temp = -2147483649;
// 	while (i < data->y_a)
// 	{
// 		if (data->stacks[A][i].value < data->stacks[B][0].value)
// 		{
// 			rota_for_a_helperr(data, &rot, temp, i);
// 			if (temp < data->stacks[B][0].value && temp ==
// 				data->stacks[A][data->y_a - 1].value)
// 			{
// 				rot.rotations = 0;
// 				return (rot);
// 			}
// 		}
// 		i++;
// 	}
// 	D(rot.rotations);
// 	rota_for_a_helper(data, &rot);
// 	return (rot);
// }

/**
 * @brief pushed back ints from stack b to stack a and rotates
 * stack a if needed
 *
 * @param data
 */
void	move_back_a(t_data *data)
{
	const t_rota_info	info = rota_for_a_back(data);
	int					i;

	i = 0;
	while (i < info.rotations && info.direction == 'n')
	{
		ra(data);
		i++;
	}
	while (i < info.rotations && info.direction == 'r')
	{
		rra(data);
		i++;
	}
	pa(data);
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
	int			midpoint;
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
