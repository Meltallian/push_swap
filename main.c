/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/07 17:57:14 by jbidaux          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ac == 2)
		conver_string(&data, av);
	if (ac > 2)
		conver_param(&data, ac - 1, &av[1]);
	// operation(&data);
	while (i < data.y)
	{
		printf("%ld\n", data.stack_a[i]);
		i++;
	}
	while (i < ac - 1)
	{
		printf("%ld\n", data.stack_a[i]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		printf("%s\n", data.tab[i]);
		i++;
	}
//	kill(&data);
	clean(&data);
	return (0);
}
