/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:45:29 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/04 14:47:03 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_left(t_data *data)
{
	if (data->stacks[A][0].value > data->stacks[A][1].value)
		sa(data);
}

void	three_left_utils(t_data *data, int top, int mid, int bot)
{
	if (mid > bot && bot > top)
	{
		rra(data);
		sa(data);
		return ;
	}
	if (mid > top && top > bot)
	{
		rra(data);
		return ;
	}
}

void	three_left(t_data *data)
{
	const int	top = data->stacks[A][0].value;
	const int	mid = data->stacks[A][1].value;
	const int	bot = data->stacks[A][2].value;

	if (top < mid && mid < bot)
		return ;
	if (top > mid && bot > mid && top < bot)
	{
		sa(data);
		return ;
	}
	if (top > mid && bot > mid && top > bot)
	{
		ra(data);
		return ;
	}
	if (top > mid && mid > bot)
	{
		ra(data);
		sa(data);
		return ;
	}
	three_left_utils(data, top, mid, bot);
}
