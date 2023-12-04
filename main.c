/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/04 18:00:30 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conver_2p(t_data *data, int ac, char **av)
{
	int		i;

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

void	tab_height(t_data *data)
{
	data->y = 0;
	while (data->tab[data->y])
		data->y++;
}

void	clean(t_data *data)
{
	int	i;

	i = 0;
	free(data->tabi);
	i = 0;
	if (data->tab)
	{
		while (data->tab[i])
			free(data->tab[i++]);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac < 2)
	{
		ft_printf ("Error");
		return (0);
	}
	if (ac == 2)
	{
		data.tab = ft_split(av[1], 32);
		tab_height(&data);
		data.tabi = ((int *)malloc((data.y) * sizeof (int)));
		while (i < data.y)
		{
			data.tabi[i] = ft_atoi(data.tab[i]);
			i++;
		}
	}
	if (ac > 2)
		conver_2p(&data, ac - 1, &av[1]);
	clean (&data);
	return (0);
}