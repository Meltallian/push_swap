/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:10:11 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/05 13:26:48 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_height(t_data *data)
{
	data->y = 0;
	while (data->tab[data->y])
		data->y++;
	data->stack_b = (int *)malloc((data->y) * sizeof(int));
}

void	conver_string(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->tab = ft_split(av[1], 32);
	stack_a_height(data);
	data->stack_a = (int *)malloc((data->y) * sizeof(int));
	while (i < data->y)
	{
		data->stack_a[i] = ft_atoi(data->tab[i]);
		i++;
	}
}

void	conver_param(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	{
		data->stack_a = ((int *)malloc((ac) * sizeof (int)));
		while (i < ac)
		{
			data->stack_a[i] = ft_atoi(av[i]);
			i++;
		}
	}
}

void	clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	if (data->tab)
	{
		while (data->tab[i])
			free(data->tab[i++]);
	}
}
