/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/12 17:10:55 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_data *data, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		conver_string(data, av);
	if (ac > 2)
		conver_param(data, ac - 1, &av[1]);
	mode_allow(data);
	data->kill.stack = 0;
	data->kill.tab = 0;
	return (0);
}

void print_stack(const char *name, t_int *stack, int length) {
    printf("%s = \n", name);
    for (int i = 0; i < length; i++) {
        printf("%ld ", stack[i].value);
    }
    printf("\n");
}

int main(int ac, char **av) {
    t_data data;

    init(&data, ac, av); // Assuming init properly initializes data

    print_stack("stack_a avant commande", data.stacks[A], data.y_a);
    print_stack("stack_b avant commande", data.stacks[B], data.y_b);

    pb(&data); // Assuming pb modifies data appropriately

    print_stack("stack_a apres commande", data.stacks[A], data.y_a);
    print_stack("stack_b apres commande", data.stacks[B], data.y_b);

    clean(&data);
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
