/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/08 14:32:24 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief This function returns the index in stack A that has
 * the smallest amount of potential moves.
 * @param data
 * @return int
 */
int	index_to_move(t_data *data)
{
	int	i;
	int	temp;
	int	index;

	i = 1;
	temp = data->cal[0];
	index = 0;
	while (i < data->y_a)
	{
		if (data->cal[i] < temp)
		{
			temp = data->cal[i];
			index = i;
		}
		i++;
	}
	return (index);
}

/**
 * @brief function that does the operation if both direction are similar.
 *
 * @param data
 * @param info_a
 * @param info_b
 */
void	same_dir(t_data *data, t_rota_info info_a, t_rota_info info_b)
{
	const int	combined = min(info_a.rotations, info_b.rotations);
	int			rot_a;
	int			rot_b;

	rot_a = info_a.rotations - combined;
	rot_b = info_b.rotations - combined;
	same_dir_combined_utils(data, info_a, combined);
	same_dir_rota_a_helper(data, info_a, rot_a);
	same_dir_rota_b_helper(data, info_b, rot_b);
	pb(data);
}

/**
 * @brief master function leading the way for operations based
 * on wheter same direction, not same, depending on size of stack.
 * @param data
 * @return int
 */
void	index_ope(t_data *data)
{
	const int			index = index_to_move(data);
	const t_rota_info	rota_info_a = rota_for_a(data, index);
	const t_rota_info	rota_info_b = rota_for_b(data, index);

	if (data->y_a == 2)
		two_left(data);
	else if (data->y_a == 3)
	{
		three_left(data);
		return ;
	}
	else if (rota_for_a(data, index).direction
		== rota_for_b(data, index).direction)
	{
		same_dir(data, rota_info_a, rota_info_b);
	}
	else if (rota_for_a(data, index).direction
		!= rota_for_b(data, index).direction)
	{
		diff_dir_a(data, rota_info_a);
		diff_dir_b(data, rota_info_b);
		pb(data);
	}
}

/**
 * @brief This function actually does the moving based on the calculus.
 *
 * @param data
 */
void	master(t_data *data)
{
	calculus_array(data);
	index_ope(data);
}
