/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:04:20 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/19 22:27:25 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	list_swap(t_lst *lst)
{
	int		tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}

void			do_swap(t_env *e, int op)
{
	if (op == SS)
	{
		list_swap(e->a);
		list_swap(e->b);
	}
	else if (op == SA)
		list_swap(e->a);
	else if (op == SB)
		list_swap(e->b);
	options(e, op);
	e->nb_op++;
}
