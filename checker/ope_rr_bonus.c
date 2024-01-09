/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:05:57 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 15:46:31 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rra_for_rrr(t_data *data)
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

void	rrb_for_rrr(t_data *data)
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
	rra_for_rrr(data);
	rrb_for_rrr(data);
}
