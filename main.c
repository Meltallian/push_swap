/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/04 18:11:16 by jbidaux          ###   ########.fr       */
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
		ft_printf ("Error");
		return (0);
	}
	if (ac == 2)
		conver_2(&data, av);
	if (ac > 2)
		conver_2p(&data, ac - 1, &av[1]);
	while (i < ac - 1 /*OU*/ /*i < data.y*/)
	{
		printf("%d\n", data.tabi[i]);
		i++;
	}
	clean (&data);
	return (0);
}