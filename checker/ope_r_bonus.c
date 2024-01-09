/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_r_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:05:09 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 15:09:14 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


void	ra(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stacks[A][0].value;
	while (i < data->y_a - 1)
	{
		data->stacks[A][i].value = data->stacks[A][i + 1].value;
		i++;
	}
	data->stacks[A][i].value = temp;
	// ft_printf("ra\n");
}

void	rb(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stacks[B][0].value;
	while (i < data->y_b - 1)
	{
		data->stacks[B][i].value = data->stacks[B][i + 1].value;
		i++;
	}
	data->stacks[B][i].value = temp;
	// ft_printf("rb\n");
}

void	ra_for_rr(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stacks[A][0].value;
	while (i < data->y_a - 1)
	{
		data->stacks[A][i].value = data->stacks[A][i + 1].value;
		i++;
	}
	data->stacks[A][i].value = temp;
}

void	rb_for_rr(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stacks[B][0].value;
	while (i < data->y_b - 1)
	{
		data->stacks[B][i].value = data->stacks[B][i + 1].value;
		i++;
	}
	data->stacks[B][i].value = temp;
}

void	rr(t_data *data)
{
	ra_for_rr(data);
	rb_for_rr(data);
	// ft_printf("rr\n");
}
