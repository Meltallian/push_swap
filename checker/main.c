/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/08 15:47:59 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../push_swap.h"

int	init(t_data *data, int ac, char **av)
{
	if (ac < 2)
		exit (1);
	if (ac == 2)
		conver_string(data, av);
	if (ac > 2)
		conver_param(data, ac - 1, &av[1]);
	data->kill.stack = 0;
	data->kill.tab = 0;
	if (data->y_a = 0)
		kill(data);
	return (0);
}

void	checker(t_data *data)
{
	int		bytes;
	char	buffer[5];

	bytes = 0;
	while (1)
	{
		bytes = read(STDIN_FILENO, buffer, 5);
		if (bytes > 0)
		{

		}
		else if (bytes == 0)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);

	clean(&data);
	return (0);
}
