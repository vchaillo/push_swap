/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:57:37 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 03:37:15 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		check_end(t_env *e)
{
	t_lst	*tmp;
	int		i;
	int		nb;

	i = 0;
	tmp = e->a;
	while (i < e->nb_elem_a - 2)
	{
		nb = tmp->val;
		if (tmp->next->val < nb)
			return (0);
		tmp = tmp->next;
		i++;
	}
	if (tmp->val > tmp->next->val)
	{
		do_reverse_rotate(e, RRA);
		do_reverse_rotate(e, RRA);
		do_swap(e, SA);
		do_rotate(e, RA);
		e->end = TRUE;
		do_rotate(e, RA);
	}
	return (1);
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

void			simple_sort(t_env *e)
{
	if (e->nb_elem_a == 3)
	{
		if (e->a->val > e->a->next->val &&
			e->a->next->val > e->a->next->next->val)
		{
			do_swap(e, SA);
			e->end = TRUE;
			do_reverse_rotate(e, RRA);
		}
	}
	if (e->a->val > e->a->next->val &&
		e->a->next->val < e->a->next->next->val)
	{
		e->end = TRUE;
		if (!(is_sort(e->a)))
			e->end = FALSE;
		do_swap(e, SA);
	}
	check_end(e);
}
