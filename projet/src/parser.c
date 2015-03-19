/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:11:15 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/19 23:20:40 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_options(t_env *e, char **av)
{
	e->option_v = TRUE;
	e->option_n = TRUE;
	e->option_c = TRUE;
	(void)av;
}
