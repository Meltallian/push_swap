/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:42:10 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/04 14:44:12 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Helper for same_dir function, stack b side.
 *
 * @param data
 * @param rota_info_a
 */
void	diff_dir_a(t_data *data, t_rota_info rota_info_a)
{
	int	i;

	i = 0;
	while (i < rota_info_a.rotations && rota_info_a.direction == 'n')
	{
		ra(data);
		i++;
	}
	while (i < rota_info_a.rotations && rota_info_a.direction == 'r')
	{
		rra(data);
		i++;
	}
}

/**
 * @brief helper for same_dir function, stack b side.
 *
 * @param data
 * @param rota_info_b
 */
void	diff_dir_b(t_data *data, t_rota_info rota_info_b)
{
	int	i;

	i = 0;
	while (i < rota_info_b.rotations && rota_info_b.direction == 'n')
	{
		rb(data);
		i++;
	}
	while (i < rota_info_b.rotations && rota_info_b.direction == 'r')
	{
		rrb(data);
		i++;
	}
}

/**
 * @brief helper for the same_dir function that does the operation
 * for combined rotations.
 *
 * @param data
 * @param info
 * @param combined
 */
void	same_dir_combined_utils(t_data *data, t_rota_info info, int combined)
{
	int	i;

	i = 0;
	while (i < combined && info.direction == 'n')
	{
		rr(data);
		i++;
	}
	i = 0;
	while (i < combined && info.direction == 'r')
	{
		rrr(data);
		i++;
	}
}

/**
 * @brief helper function to rotate stack A.
 *
 * @param data
 * @param info_a
 * @param rot_a
 */
void	same_dir_rota_a_helper(t_data *data, t_rota_info info_a, int rot_a)
{
	int	i;

	i = 0;
	while (i < rot_a && info_a.direction == 'n')
	{
		ra(data);
		i++;
	}
	i = 0;
	while (i < rot_a && info_a.direction == 'r')
	{
		rra(data);
		i++;
	}
}

/**
 * @brief helper function that does the rotation for stack B
 *
 * @param data
 * @param info_b
 * @param rot_b
 */
void	same_dir_rota_b_helper(t_data *data, t_rota_info info_b, int rot_b)
{
	int	i;

	i = 0;
	while (i < rot_b && info_b.direction == 'n')
	{
		rb(data);
		i++;
	}
	i = 0;
	while (i < rot_b && info_b.direction == 'r')
	{
		rrb(data);
		i++;
	}
}
