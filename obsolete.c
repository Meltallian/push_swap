/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obsolete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:48:27 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/04 16:45:35 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rota_info	rota_for_b(t_data *data, int index)
{
	const int	midpoint = data->y_b / 2;
	int			i;
	long int	temp;
	int			dex;
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
				dex = i;
			}
		}
		i++;
	}
	if (info.rotations > midpoint)
	{
		info.rotations = data->y_b - info.rotations - 1;
		info.direction = 'r';
	}
	return (info);
}
