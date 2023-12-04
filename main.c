/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/04 17:21:25 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	conversion(t_data *data, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	{
		while (av[i])
			i++;
		data->y = i;
		data->tab = ((char **)malloc((i + 1) * sizeof (char *)));
		i = 0;
		while (i < data->y)
		{
			data->tab[i] = av[i];
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

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac < 2)
	{
		ft_printf ("Error");
		return (0);
	}
	if (ac == 2)
	{
		data.tab = ft_split(av[1], 32);
		tab_height(&data);
	}
	if (ac > 2)
		conversion(&data, av);
	i = 0;
	while (i < data.y)
	{
		ft_printf("%s", data.tab[i]);
		ft_printf("\n");
		i++;
	}
	return (0);
}