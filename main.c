/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/12 13:53:10 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	operation(t_data *data)
{
	data->line = get_next_line(STDIN_FILENO);
	while (data->line != NULL)
	{
		data->line[ft_strcspn(data->line, "\n")] = '\0';
		if (ft_strncmp(data->line, "sa", 2) == 0)
			swap_a(data);
		free (data->line);
		data->line = get_next_line(STDIN_FILENO);
	}
	if (data->line != NULL)
		free(data->line);
	return (0);
} */


void	initiating(t_data *data)
{
	data->kill.stack = 0;
	data->kill.tab = 0;
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	int		len;

	initiating(&data);
	i = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
		conver_string(&data, av);
	if (ac > 2)
		conver_param(&data, ac - 1, &av[1]);
	len = data.y_a;
	while (i < len)
	{
		printf("%ld", data.stack_a[i]);
		i++;
	}
	printf("\n");
	data.stack_b[0] = 5;
	data.stack_b[1] = 3;
//	pa(&data);
	i = 0;
	while (i < len)
	{
		printf("%ld", data.stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < len)
	{
		printf("%d", data.stack_b[i]);
		i++;
	}
	clean(&data);
	return (0);
}
