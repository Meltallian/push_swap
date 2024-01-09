/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/09 15:39:46 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (data->y_a == 0)
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
	if (!(strcmp(line, "sa\n") == 0 || strcmp(line, "sb\n") == 0 || strcmp(line, "ss\n") == 0 ||
		strcmp(line, "pa\n") == 0 || strcmp(line, "pb\n") == 0 || strcmp(line, "ra\n") == 0 ||
		strcmp(line, "rb\n") == 0 || strcmp(line, "rr\n") == 0 || strcmp(line, "rra\n") == 0 ||
		strcmp(line, "rrb\n") == 0 || strcmp(line, "rrr\n") == 0 || strcmp(line, "\n") == 0))
		{
			free(line);
			ft_printf("Error");
			exit (0);
		}
}
void	move(t_data *data, char *line)
{
	if (strcmp(line, "sa\n") == 0)
		sa(data);
	if (strcmp(line, "sb\n") == 0)
		sb(data);
	if (strcmp(line, "ss\n") == 0)
		ss(data);
	if (strcmp(line, "pa\n") == 0)
		pa(data);
	if (strcmp(line, "pb\n") == 0)
		pb(data);
	if (strcmp(line, "ra\n") == 0)
		ra(data);
	if (strcmp(line, "rb\n") == 0)
		rb(data);
	if (strcmp(line, "rr\n") == 0)
		rr(data);
	if (strcmp(line, "rra\n") == 0)
		rra(data);
	if (strcmp(line, "rrb\n") == 0)
		rrb(data);
	if (strcmp(line, "rrr\n") == 0)
		rrr(data);
}

int	checker(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == 0)
			break ;
		line_check(line);
		move(data, line);
		free(line);
		if (strcmp(line, "\n") == 0)
			break ;
	}
	return (0);
}

/* void	print_stacks_side_by_side(t_data *data)
{
	int max_len = (data->y_a > data->y_b) ? data->y_a : data->y_b;

	printf("%-20s%-20s\n", "stack_a", "stack_b");
	for (int i = 0; i < max_len; i++) {
		if (i < data->y_a)
			printf("%-20ld", data->stacks[A][i].value);
		else
			printf("%-20s", "");

		if (i < data->y_b)
			printf("%-20ld", data->stacks[B][i].value);
		else
			printf("%-20s", "");

		printf("\n");
	}
} */

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);
	checker(&data);
	if (is_stack_a_sorted(&data) == 1)
		ft_printf("OK\n");
	if (is_stack_a_sorted(&data) != 1)
		ft_printf("KO\n");
	clean(&data);
	return (0);
}

/* int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);

	ft_printf("\nBefore master command:\n");
	print_stacks_side_by_side(&data);
	checker(&data);
	ft_printf("\nAfter master command:\n");
	print_stacks_side_by_side(&data);
	if (is_stack_a_sorted(&data) == 1)
		ft_printf("OK\n");
	if (is_stack_a_sorted(&data) != 1)
		ft_printf("KO\n");
	clean(&data);
	return (0);
} */