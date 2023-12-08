/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:38:08 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/08 16:02:33 by jbidaux          ###   ########.fr       */
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
