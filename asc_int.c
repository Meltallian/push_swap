/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:51:41 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/08 15:29:34 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	string_error(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if ((data->tab[i][j] < '0' || data->tab[i][j] > '9')
				&& !(data->tab[i][j] == '-' && data->tab[i][j + 1] >= '0'
				&& data->tab[i][j + 1] <= '9'))
				kill(data);
			j++;
		}
		i++;
	}
}

void	check_int_dup(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->y_a)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (data->stacks[A][i].value == data->stacks[A][j].value)
				kill(data);
			j--;
		}
		i++;
	}
	i = 0;
	while (i < data->y_a)
	{
		if (data->stacks[A][i].value > 2147483647
			|| data->stacks[A][i].value < -2147483648)
			kill(data);
		i++;
	}
}

int	conver_string(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->tab = ft_split(av[1], 32);
	stack_a_height(data);
	data->stacks[A] = (t_int *)malloc((data->y_a) * sizeof(t_int));
	while (i < data->y_a)
	{
		data->stacks[A][i].value = ft_atoi_evil(data->tab[i], data);
		i++;
	}
	data->stacks[A][i].value = 0;
	string_error(data);
	check_int_dup(data);
	return (0);
}

void	conver_param(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	{
		data->stacks[A] = ((t_int *)malloc((ac) * sizeof (t_int)));
		while (i < ac)
		{
			data->stacks[A][i].value = ft_atoi_evil(av[i], data);
			i++;
		}
		data->stacks[A][i].value = 0;
		data->tab = (char **)malloc((ac + 1) * sizeof(char *));
		i = 0;
		while (i < ac)
		{
			data->tab[i] = ft_itoa(data->stacks[A][i].value);
			i++;
		}
	}
	stack_a_height(data);
	string_error(data);
	check_int_dup(data);
	kill_tab_atoi(data);
}

