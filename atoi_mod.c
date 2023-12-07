/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:38:08 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/07 12:14:05 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_height(t_data *data)
{
	data->y = 0;
	while (data->tab[data->y])
		data->y++;
	data->stack_b = (int *)malloc((data->y) * sizeof(int));
	if (data->y == 1)
		kill(data);
}

long int	ft_atoi_evil(const char *str, t_data *data)
{
	int	i;

	data->ato.neg = 1;
	i = 0;
	data->ato.n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			data->ato.neg = -1;
		i++;
	}
	if (!(str[i] >= 48 && str[i] <= 57))
		kill(data);
	while (str[i] >= 48 && str[i] <= 57)
	{
		data->ato.n = (data->ato.n + (str[i] - 48)) * 10;
		i++;
	}
	return (data->ato.neg * (data->ato.n / 10));
}

void	not_integer(t_data *data)
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
}
