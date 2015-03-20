/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:55:25 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 03:03:27 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	choose_rotate_way(t_env *e, int dist, int *way)
{
	int		i;

	if (dist <= (e->nb_elem_a / 2))
	{
		i = 0;
		while (i < dist)
		{
			do_rotate(e, RA);
			i++;
			*way = 1;
		}
	}
	else
	{
		i = e->nb_elem_a;
		while (i > dist)
		{
			do_reverse_rotate(e, RRA);
			i--;
			*way = -1;
		}
	}
}

static	void	get_min_first(t_env *e, t_lst *list, int *way)
{
	t_lst	*tmp;
	int		min;
	int		dist;
	int		i;

	tmp = list;
	dist = 0;
	i = 0;
	min = tmp->val;
	while (tmp != NULL)
	{
		if (min > tmp->val)
		{
			min = tmp->val;
			dist = i;
		}
		tmp = tmp->next;
		i++;
	}
	choose_rotate_way(e, dist, way);
}

static	int		is_sort(t_lst *list)
{
	t_lst	*tmp;
	int		nb;

	tmp = list;
	while (tmp != NULL)
	{
		nb = tmp->val;
		if (tmp->next && tmp->next->val < nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			sort(t_env *e)
{
	int		way;

	if (e->nb_elem_a > 2)
		simple_sort(e);
	while (e->a->next != NULL)
	{
		get_min_first(e, e->a, &way);
		if (is_sort(e->a))
			break ;
		do_push(e, PB);
	}
	while (e->b != NULL)
	{
		do_push(e, PA);
	}
}
