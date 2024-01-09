/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:16:08 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 10:50:48 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief helper for rota_for_b. Includes if the int from A will be
 * either a max or a min.
 *
 * @param data
 * @param info
 * @param index
 * @param midpoint
 */
t_rota_info	rota_for_b_helper(t_data *data,
	t_rota_info info, const int midpoint)
{
	if (if_big_b_top(data) == 1)
	{
		info.rotations = 0;
		info.direction = 'n';
		return (info);
	}
	if (index_max_b(data) <= midpoint)
	{
		info.direction = 'n';
		info.rotations = index_max_b(data);
		return (info);
	}
	if (index_max_b(data) > midpoint)
	{
		info.direction = 'r';
		info.rotations = data->y_b - index_max_b(data);
		return (info);
	}
	return (info);
}

void	b_helper(t_data *data, t_rota_info *info)
{
	const int	midpoint = data->y_b / 2;

	if (info->rotations > midpoint)
	{
		info->rotations = data->y_b - info->rotations;
		info->direction = 'r';
	}
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
	const int	midpoint = data->y_b / 2;
	int			i;
	long int	temp;
	t_rota_info	info;

	info.rotations = 0;
	info.direction = 'n';
	temp = -2147483649;
	i = 0;
	if (is_max_or_min(data, index) != 0)
		return (rota_for_b_helper(data, info, midpoint));
	while (i < data->y_b)
	{
		if (data->stacks[B][i].value < data->stacks[A][index].value)
		{
			if (data->stacks[B][i].value > temp)
			{
				temp = data->stacks[B][i].value;
				info.rotations = i;
			}
		}
		i++;
	}
	b_helper(data, &info);
	return (info);
}
