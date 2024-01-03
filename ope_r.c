/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:59:04 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/03 17:04:30 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
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
	ft_printf("rr\n");
}
