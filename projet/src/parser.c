/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:11:15 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 00:08:49 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_one_full(t_env *e, char *arg)
{
	if (ft_strcmp(arg, "-c") == 0)
	{
		e->option_c = TRUE;
		return (1);
	}
	if (ft_strcmp(arg, "-v") == 0)
	{
		e->option_v = TRUE;
		return (1);
	}
	if (ft_strcmp(arg, "-n") == 0)
	{
		e->option_n = TRUE;
		return (1);
	}
	if (ft_strcmp(arg, "-a") == 0)
	{
		e->option_a = TRUE;
		return (1);
	}
	return (0);
}

static	int	check_arg_for_options(t_env *e, char *arg)
{
	if (check_one_full(e, arg))
		return (1);
//	if (check_two(e, arg))
//		return (1);
//	if (check_three(e, arg))
//		return (1);
	return (0);
}

void		parse_options(t_env *e, char **av)
{
	int		i;

	i = 1;
	e->nb_options = 0;
	while (i < 4)
	{
		if (check_arg_for_options(e, av[i]))
			e->nb_options++;
		i++;
	}
}
