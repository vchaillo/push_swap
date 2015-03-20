/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:11:15 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 02:49:15 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_full(t_env *e, char *arg)
{
	if (ft_strcmp(arg, "-cvn") == 0 || ft_strcmp(arg, "-vnc") == 0 ||
			ft_strcmp(arg, "-vcn") == 0 || ft_strcmp(arg, "-cnv") == 0 ||
			ft_strcmp(arg, "-ncv") == 0 || ft_strcmp(arg, "-nvc") == 0)
	{
		e->option_c = TRUE;
		e->option_n = TRUE;
		e->option_v = TRUE;
		return (1);
	}
	return (0);
}

static	int	check_two(t_env *e, char *arg)
{
	if (ft_strcmp(arg, "-cv") == 0 || ft_strcmp(arg, "-vc") == 0)
	{
		e->option_c = TRUE;
		e->option_v = TRUE;
		return (1);
	}
	if (ft_strcmp(arg, "-cn") == 0 || ft_strcmp(arg, "-nc") == 0)
	{
		e->option_c = TRUE;
		e->option_n = TRUE;
		return (1);
	}
	if (ft_strcmp(arg, "-vn") == 0 || ft_strcmp(arg, "-nv") == 0)
	{
		e->option_v = TRUE;
		e->option_n = TRUE;
		return (1);
	}
	return (0);
}

static	int	check_one(t_env *e, char *arg)
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
	return (0);
}

static	int	check_arg_for_options(t_env *e, char *arg)
{
	if (check_one(e, arg))
		return (1);
	if (check_two(e, arg))
		return (1);
	if (check_full(e, arg))
		return (1);
	return (0);
}

void		parse_options(t_env *e, char **av)
{
	int		i;

	i = 1;
	while (i < 4)
	{
		if (av[i] && check_arg_for_options(e, av[i]))
			e->nb_options++;
		i++;
	}
}
