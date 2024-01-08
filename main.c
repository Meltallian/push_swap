/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/08 14:11:40 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_data *data, int ac, char **av)
{
	if (ac < 2)
		exit (1);
	if (ac == 2)
		conver_string(data, av);
	if (ac > 2)
		conver_param(data, ac - 1, &av[1]);
	mode_allow(data);
	data->kill.stack = 0;
	data->kill.tab = 0;
	data->cal = malloc(data->y_a * sizeof(int));
	if (data->cal == NULL)
		return (0);
	if (is_stack_a_sorted(data) == 1)
		soft_kill(data);
	if (data->y_a > 3)
	{
		pb(data);
		pb(data);
	}
	return (0);
}

/* void	print_stacks_side_by_side(t_data *data)
{
	int max_len = (data->y_a > data->y_b) ? data->y_a : data->y_b;

	ft_printf("%-20s%-20s\n", "stack_a", "stack_b");
	for (int i = 0; i < max_len; i++) {
		if (i < data->y_a)
			ft_printf("%-20ld", data->stacks[A][i].value);
		else
			ft_printf("%-20s", "");

		if (i < data->y_b)
			ft_printf("%-20ld", data->stacks[B][i].value);
		else
			ft_printf("%-20s", "");

		ft_printf("\n");
	}
} */

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);
	while (data.y_a >= 4)
		master(&data);
	master(&data);
	while (data.y_b > 0)
		move_back_a(&data);
	rota_a_final(&data);
	clean(&data);
	return (0);
}

// ft_printf("\nAfter master command:\n");
// print_stacks_side_by_side(&data);
// if (is_stack_a_sorted(&data) == 1)
// 	ft_printf("Shit is sorted.");