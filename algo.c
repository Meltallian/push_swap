/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:19:58 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/05 18:42:46 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	const	int	midpoint = data->y_a / 2;
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
			if (data->stacks[A][i].value > temp)
			{
				temp = data->stacks[A][i].value;
				rot.rotations = i + 1;
			}
			if (temp < data->stacks[B][0].value &&
				temp == data->stacks[A][data->y_a - 1].value)
			{
				rot.rotations = 0;
				return (rot);
			}
		}
		i++;
	}
	D(rot.rotations);
	if (is_max_or_min_back(data) == 2)
		rot.rotations = index_min_a(data);
	if (rot.rotations > midpoint)
	{
		rot.rotations = data->y_a - rot.rotations;
		rot.direction = 'r';
	}
	D(rot.rotations);
	return (rot);
}

/**
 * @brief pushed back ints from stack b to stack a and rotates
 * stack a if needed
 *
 * @param data
 */
void	move_back_a(t_data *data)
{
	const t_rota_info	info = rota_for_a_back(data);
	int	i;

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

/**
 * @brief helper for rota_for_b. Includes if the int from A will be
 * either a max or a min.
 *
 * @param data
 * @param info
 * @param index
 * @param midpoint
 */
t_rota_info	rota_for_b_helper(t_data *data, t_rota_info info, const int midpoint)
{
	if (if_big_b_top(data) == 1)
	{
		info.rotations = 0;
		info.direction = 'r';
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

/**
 * @brief calculates number of rotations in stack b to account
 * for int index at the top of stack a.
 * @param data
 * @param index
 * @return int
 */
t_rota_info	rota_for_b(t_data *data, int index)
{
	const int	midpoint = data->y_b / 2 + 1;
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
	if (info.rotations > midpoint)
	{
		info.rotations = data->y_b - info.rotations;
		info.direction = 'r';
	}
	return (info);
}

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
		if(data->cal[i] < temp)
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
	int					index = index_to_move(data);
	const t_rota_info	rota_info_a = rota_for_a(data, index);
	const t_rota_info	rota_info_b = rota_for_b(data, index);

	if (data->y_a == 2)
		two_left(data);
	else if (data->y_a == 3)
	{
		three_left(data);
			return ;
	}
	else if (rota_for_a(data, index).direction == rota_for_b(data, index).direction)
	{
		same_dir(data, rota_info_a, rota_info_b);
	}
	else if (rota_for_a(data, index).direction != rota_for_b(data, index).direction)
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
	int	i;

	i = 0;
	calculus_array(data);
	while (i < data->y_a)
	{
		printf("%d,", data->cal[i]);
		i++;
	}
	D(index_to_move(data));
	index_ope(data);
}
