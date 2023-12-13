/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:34:46 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/13 14:59:06 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	i;
	int	temp;

	i = data->y_a - 2;
	temp = data->stacks[A][data->y_a - 1].value;
	while (i >= 0)
	{
		data->stacks[A][i + 1].value = data->stacks[A][i].value;
		i--;
	}
	data->stacks[A][0].value = temp;
}

void	rrb(t_data *data)
{
	int	i;
	int	temp;

	i = data->y_b - 2;
	temp = data->stacks[B][data->y_b - 1].value;
	while (i >= 0)
	{
		data->stacks[B][i + 1].value = data->stacks[B][i].value;
		i--;
	}
	data->stacks[B][0].value = temp;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
