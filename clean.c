/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:16 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/12 16:29:03 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->stacks[A])
	{
		free(data->stacks[A]);
		data->stacks[A] = NULL;
	}
	if (data->stacks[B])
	{
		free(data->stacks[B]);
		data->stacks[B] = NULL;
	}
	if (data->tab)
	{
		while (data->tab[i])
		{
			free(data->tab[i]);
			data->tab[i] = NULL;
			i++;
		}
		free(data->tab);
		data->tab = NULL;
	}
}

int	kill(t_data *data)
{
	ft_printf("Error\n");
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

//void	ft_putstr_fd(char *s, int fd)