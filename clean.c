/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:16 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/08 14:04:34 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->stack_a)
	{
		free(data->stack_a);
		data->stack_a = NULL;
	}
	if (data->stack_b)
	{
		free(data->stack_b);
		data->stack_b = NULL;
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