/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:53:36 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 02:57:28 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_push(t_env *e, int op)
{
	t_lst	*tmp;

	if (op == PB)
	{
		tmp = e->a;
		e->a = e->a->next;
		tmp->next = e->b;
		e->b = tmp;
		e->nb_elem_a--;
		e->nb_elem_b++;
	}
	if (op == PA)
	{
		tmp = e->b;
		e->b = e->b->next;
		tmp->next = e->a;
		e->a = tmp;
		e->nb_elem_a++;
		e->nb_elem_b--;
	}
	options(e, op);
	e->nb_op++;
}
