/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:52:32 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 03:19:40 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	double_atoi(const char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

static	int		check_digit(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]))
				j++;
			else if (j == 0 && av[i][j] == '-' && ft_isdigit(av[i][j + 1]))
				j++;
			else
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static	int		check_min_max(int ac, char **av)
{
	double	val;
	int		i;

	i = 1;
	while (i < ac)
	{
		val = double_atoi(av[i]);
		if (val > MAX || val < MIN)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static	int		check_double(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int				check_arg(int ac, char **av)
{
	if ((check_digit(ac, av) == FALSE))
		return (FALSE);
	if ((check_min_max(ac, av) == FALSE))
		return (FALSE);
	if ((check_double(ac, av) == FALSE))
		return (FALSE);
	return (TRUE);
}
