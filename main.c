/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/12 16:28:40 by jbidaux          ###   ########.fr       */
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
/* 	data.stack_b[0] = 5;
	data.stack_b[1] = 3; */
	printf("stack_a avant commande = \n");
	while (i < len)
	{
		printf("%ld", data.stacks[A][i].value);
		i++;
	}
	i = 0;
	printf("\n");
	printf("stack_b avant commande = \n");
	while (i < len)
	{
		printf("%ld", data.stacks[B][i].value);
		i++;
	}
	pb(&data);
	i = 0;
	printf("\n");
	printf("stack_a apres commande = \n");
	while (i < len)
	{
		printf("%ld", data.stacks[A][i].value);
		i++;
	}
	printf("\n");
	i = 0;
	printf("stack_b apres commande = \n");
	while (i < len)
	{
		printf("%ld", data.stacks[B][i].value);
		i++;
	}
	clean(&data);
	return (0);
}
