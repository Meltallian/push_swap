/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_int_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:16 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/05 15:48:40 by jbidaux          ###   ########.fr       */
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

int	kill(t_data *data)
{
	ft_printf("Error\n");
	clean(data);
	exit (1);
}
