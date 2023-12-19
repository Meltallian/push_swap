/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_s_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:09:53 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/19 11:54:12 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	temp;

	if (data->y_a < 2)
		return ;
	temp = data->stacks[A][0].value;
	data->stacks[A][0].value = data->stacks[A][1].value;
	data->stacks[A][1].value = temp;
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	int	temp;

	if (data->y_a < 2)
		return ;
	temp = data->stacks[B][0].value;
	data->stacks[B][0].value = data->stacks[B][1].value;
	data->stacks[B][1].value = temp;
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_printf("ss\n");
}

void	pa(t_data *data)
{
	int	i;
	int	temp;

	if (!data->stacks[B] || data->y_b == 0)
		return ;
	i = data->y_a - 1;
	while (i >= 0)
	{
		data->stacks[A][i + 1].value = data->stacks[A][i].value;
		i--;
	}
	data->stacks[A][0] = data->stacks[B][0];
	i = 0;
	while (i < data->y_b - 1)
	{
		temp = data->stacks[B][i + 1].value;
		data->stacks[B][i].value = temp;
		i++;
	}
	data->stacks[B][i].value = 0;
	data->y_a++;
	data->y_b--;
ft_printf("pa\n");
}

void	pb(t_data *data)
{
	int	i;
	int	temp;

	if (!data->stacks[A] || data->y_a == 0)
		return ;
	i = data->y_b - 1;
	while (i >= 0)
	{
		data->stacks[B][i + 1].value = data->stacks[B][i].value;
		i--;
	}
	temp = data->stacks[A][0].value;
	data->stacks[B][0].value = temp;
	i = 0;
	while (i < data->y_a - 1)
	{
		temp = data->stacks[A][i + 1].value;
		data->stacks[A][i].value = temp;
		i++;
	}
	data->stacks[A][i].value = 0;
	data->y_a--;
	data->y_b++;
	ft_printf("pb\n");
}
