/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:32:32 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/08 14:33:17 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief calculates number of operations if index stack A is
 * a maximum or a minimum in stack B
 * @param data
 * @param index
 * @return int
 */

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
	if (direction_a == 'r' && rotations_b > 0 && rotations_a > 0)
		total_rotations = rotations_a + 1;
	else
		total_rotations = rotations_a + rotations_b + 1;
	return (total_rotations);
}

/**
 * @brief calculates number of operations when there are rotation overlapping
 *
 * @param data
 * @param index
 * @return int
 */
int	calcul_utils(t_data *data, int index)
{
	int					total_rotations;
	int					combined_rota;
	const t_rota_info	rota_info_a = rota_for_a(data, index);
	const t_rota_info	rota_info_b = rota_for_b(data, index);

	total_rotations = 0;
	if (rota_info_a.rotations == 0 && rota_info_b.rotations == 0)
		total_rotations = 1;
	else if (rota_info_a.direction == rota_info_b.direction)
	{
		combined_rota = min(rota_info_a.rotations, rota_info_b.rotations);
		total_rotations = combined_rota;
		total_rotations += (rota_info_a.rotations - combined_rota)
			+ (rota_info_b.rotations - combined_rota) + 1;
	}
	else
		total_rotations = rota_info_a.rotations + rota_info_b.rotations + 1;
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
	if (is_max_or_min(data, index) != 0)
		return (calcul_max_min_special(data, index));
	if (is_max_or_min(data, index) == 0)
		return (calcul_utils(data, index));
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
