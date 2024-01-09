/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_mod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:11:57 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 14:12:06 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_a_height(t_data *data)
{
	data->y_a = 0;
	while (data->tab[data->y_a])
		data->y_a++;
	data->stacks[B] = (t_int *)malloc(data->y_a * sizeof(t_int));
	data->y_b = 0;
	data->length_tot = data->y_a;
}

void	atoi_evil_utils(const char *str, t_data *data, int i)
{
	if (!(str[i] >= 48 && str[i] <= 57))
		data->kill.stack = 1;
}

long int	ft_atoi_evil(const char *str, t_data *data)
{
	int	i;

	data->ato.neg = 1;
	i = 0;
	data->ato.n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			data->ato.neg = -1;
		i++;
	}
	atoi_evil_utils(str, data, i);
	while (str[i] >= 48 && str[i] <= 57)
	{
		data->ato.n = (data->ato.n + (str[i] - 48)) * 10;
		i++;
	}
	while (str[i++])
	{
		if (str[i - 1] != ' ')
			data->kill.stack = 1;
	}
	return (data->ato.neg * (data->ato.n / 10));
}
