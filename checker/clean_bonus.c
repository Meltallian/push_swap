/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:12:51 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 14:17:06 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->stacks[A])
	{
		free(data->stacks[A]);
		data->stacks[A] = 0;
	}
	free(data->stacks[B]);
	data->stacks[B] = 0;
	while (data->tab[i])
	{
		free(data->tab[i]);
		data->tab[i] = 0;
		i++;
	}
	free(data->tab);
	data->tab = 0;
	free(data->cal);
	data->cal = 0;
}

int	kill(t_data *data)
{
	ft_printf("Error\n");
	clean(data);
	exit (1);
}

int	soft_kill(t_data *data)
{
	clean(data);
	exit (1);
}

void	kill_tab_atoi(t_data *data)
{
	if (data->kill.stack == 1)
	{
		ft_printf("Error\n");
		clean(data);
		exit (1);
	}
}

/**
 * @brief check whether stack a is fully sorted (1).
 * also checks whether it is full. return -1 if not full
 * and 0 if not sorted.
 * @param data
 * @return int
 */
int	is_stack_a_sorted(t_data *data)
{
	int	i;

	i = 0;
	if (data->y_a != data->length_tot)
		return (-1);
	while (i < data->length_tot - 1)
	{
		if (data->stacks[A][i].value > data->stacks[A][i + 1].value)
			return (0);
		i++;
	}
	return (1);
}
