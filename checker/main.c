/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 10:33:13 by jbidaux          ###   ########.fr       */
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

void	error_line_bonus(char *line)
{
	free(line);
	ft_printf("Error");
	exit (0);
}

void	line_check(char *line)
{
	if (!(line == "sa" || line == "sb" || line == "ss" || line == "pa" ||
		line == "pb" || line == "ra" || line == "rb" || line == "rr" ||
		line == "rra" || line == "rrb" || line == "rrr"))
		{
			free(line);
			ft_printf("Error");
			exit (0);
		}
}

int	checker(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	line_check(line);

}

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);

	clean(&data);
	return (0);
}
