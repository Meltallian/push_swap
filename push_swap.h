/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:51 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/08 14:38:52 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_kill {
	int	tab;
	int	stack;
}			t_kill;
typedef struct s_ato {
	long int	n;
	int			neg;
}	t_ato;
typedef struct s_data {
	char		**tab;
	long int	*stack_a;
	int			*stack_b;
	char		*line;
	int			y;
	t_kill		kill;
	t_ato		ato;
}	t_data;

void		stack_a_height(t_data *data);
int			conver_string(t_data *data, char **av);
void		conver_param(t_data *data, int ac, char **av);
void		clean(t_data *data);
int			kill(t_data *data);
void		string_error(t_data *data);
void		check_int_dup(t_data *data);
long int	ft_atoi_evil(const char *str, t_data *data);
size_t		ft_strcspn(const char *s1, const char *s2);
int			operation(t_data *data);
void		kill_tab_atoi(t_data *data);

#endif // PUSH_SWAP_H