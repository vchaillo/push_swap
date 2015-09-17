/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:54:26 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 02:57:26 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	list_rotate(t_lst *list)
{
	int		temp;
	t_lst	*tmp;

	tmp = list;
	temp = list->val;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			tmp->val = temp;
		else
			tmp->val = tmp->next->val;
		tmp = tmp->next;
	}
}

void			do_rotate(t_env *e, int op)
{
	if (op == RR)
	{
		list_rotate(e->a);
		list_rotate(e->b);
	}
	else if (op == RA)
		list_rotate(e->a);
	else if (op == RB)
		list_rotate(e->b);
	options(e, op);
	e->nb_op++;
}
