/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:09:53 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/12 14:50:30 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (data->y_a < 2)
		return ;
	int	temp;

	temp = data->stack_a[0];
	data->stack_a[0] = data->stack_a[1];
	data->stack_a[1] = temp;
}

void	sb(t_data *data)
{
	if (data->y_a < 2)
		return ;
	int	temp;

	temp = data->stack_b[0];
	data->stack_b[0] = data->stack_b[1];
	data->stack_b[1] = temp;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	int	i;
	int	temp;

	if (!data->stack_b)
		return ;
	i = 0;
	while (i < data->y_a - 1)
	{
		temp = data->stack_a[i];
		data->stack_a[i + 1] = temp;
		i++;
	}
	temp = data->stack_b[0];
	data->stack_a[0] = temp;
	i = 0;
	while (i < data->y_b - 1)
	{
		temp = data->stack_b[i + 1];
		data->stack_b[i] = temp;
		i++;
	}
	data->y_b--;
}

void	pb(t_data *data)
{
	int i;
	int temp;

	if (!data->stack_a)
		return;
	i = data->y_b - 1;
	while (i >= 0)
	{
		data->stack_b[i + 1] = data->stack_b[i];
		i--;
	}
	temp = data->stack_a[0];
	data->stack_b[0] = temp;
	i = 0;
	while (i < data->y_a - 1)
	{
		temp = data->stack_a[i + 1];
		data->stack_a[i] = temp;
		i++;
	}
	data->stack_a[i] = 0;
	data->y_a--;
	data->y_b++;
}
