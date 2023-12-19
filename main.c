/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/19 16:24:50 by jbidaux          ###   ########.fr       */
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
	pb(data);
	pb(data);
	return (0);
}

void print_stacks_side_by_side(t_data *data) {
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
}

int main(int ac, char **av) {
    t_data data;

    init(&data, ac, av); // Initialize the data structure

    printf("Before command:\n");
    print_stacks_side_by_side(&data);
    // pb(&data); // Execute the command (modify the stacks as needed)
	pb(&data);
	pb(&data);
	// pb(&data);
	// pa(&data);
	// rrb(&data);

    printf("\nAfter command:\n");
    print_stacks_side_by_side(&data);
	master(&data);
//	master(&data);
//	master(&data);
    clean(&data); // Clean up resources
    return 0;
}

/*
int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	int		len;

	init(&data, ac, av);
	i = 0;
	len = data.y_a;
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
} */
