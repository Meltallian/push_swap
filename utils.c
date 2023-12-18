/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:41:29 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/18 11:30:13 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	count;
	size_t	j;

	count = 0;
	while (s1[count] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[count] == s2[j])
				return (count);
			j++;
		}
		j = 0;
		count++;
	}
	return (count);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
