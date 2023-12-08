/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:10:11 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/08 14:37:46 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	not_integer(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->y)
	{
		if (data->stack_a[i] > 2147483647
			|| data->stack_a[i] < -2147483648)
			kill(data);
		i++;
	}
} */

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
	while (data->stack_a[i] != 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (data->stack_a[i] == data->stack_a[j])
				kill(data);
			j--;
		}
		i++;
	}
	i = 0;
	while (i < data->y)
	{
		if (data->stack_a[i] > 2147483647
			|| data->stack_a[i] < -2147483648)
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
	data->stack_a = (long int *)malloc((data->y) * sizeof(long int));
	while (i < data->y)
	{
		data->stack_a[i] = ft_atoi_evil(data->tab[i], data);
		i++;
	}
	data->stack_a[i] = 0;
	string_error(data);
	check_int_dup(data);
	return (0);
}

void	conver_param(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	{
		data->stack_a = ((long int *)malloc((ac) * sizeof (long int)));
		while (i < ac)
		{
			data->stack_a[i] = ft_atoi_evil(av[i], data);
			i++;
		}
		data->stack_a[i] = 0;
		data->tab = (char **)malloc((ac + 1) * sizeof(char *));
		i = 0;
		while (i < ac)
		{
			data->tab[i] = ft_itoa(data->stack_a[i]);
			i++;
		}
	}
	stack_a_height(data);
	string_error(data);
	check_int_dup(data);
	kill_tab_atoi(data);
}
