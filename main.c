/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/07 11:25:25 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (i < data.y)
	{
		printf("%ld\n", data.stack_a[i]);
		i++;
	}
/* 	while (i < ac - 1)
	{
		printf("%ld\n", data.stack_a[i]);
		i++;
	}
	i = 0; */
	while (i < ac - 1)
	{
		printf("%s\n", data.tab[i]);
		i++;
	}
	clean(&data);
	return (0);
}
