/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:10:11 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/04 18:10:23 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_height(t_data *data)
{
	data->y = 0;
	while (data->tab[data->y])
		data->y++;
}

void	conver_2(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->tab = ft_split(av[1], 32);
	tab_height(data);
	data->tabi = ((int *)malloc((data->y) * sizeof (int)));
	while (i < data->y)
	{
		data->tabi[i] = ft_atoi(data->tab[i]);
		i++;
	}
}

void	conver_2p(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	{
		data->tabi = ((int *)malloc((ac) * sizeof (int)));
		while (i < ac)
		{
			data->tabi[i] = ft_atoi(av[i]);
			i++;
		}
	}
}

void	clean(t_data *data)
{
	int	i;

	i = 0;
	free(data->tabi);
	if (data->tab)
	{
		while (data->tab[i])
			free(data->tab[i++]);
	}
}