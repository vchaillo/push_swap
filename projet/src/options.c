/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:53:00 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/20 02:59:11 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	print_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->val);
		ft_putstr(", ");
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static	void	option_v(t_env *e)
{
	ft_putchar('\n');
	ft_putstr("\033[33;1mListe a : \033[0m");
	print_list(e->a);
	ft_putstr("\033[34;1mListe b : \033[0m");
	print_list(e->b);
}

static	void	print_op(int op)
{
	if (op == RA)
		ft_putstr("ra");
	else if (op == RB)
		ft_putstr("rb");
	else if (op == RR)
		ft_putstr("rr");
	else if (op == RRA)
		ft_putstr("rra");
	else if (op == RRB)
		ft_putstr("rrb");
	else if (op == RRR)
		ft_putstr("rrr");
	else if (op == SA)
		ft_putstr("sa");
	else if (op == SB)
		ft_putstr("sb");
	else if (op == PA)
		ft_putstr("pa");
	else if (op == PB)
		ft_putstr("pb");
	ft_putchar(' ');
}

static	void	print_op_color(int op)
{
	if (op == RA)
		ft_putstr("\033[32mra\033[0m");
	else if (op == RB)
		ft_putstr("rb");
	else if (op == RR)
		ft_putstr("rr");
	else if (op == RRA)
		ft_putstr("\033[34;1mrra\033[0m");
	else if (op == RRB)
		ft_putstr("rrb");
	else if (op == RRR)
		ft_putstr("rrr");
	else if (op == SA)
		ft_putstr("\033[35msa\033[0m");
	else if (op == SB)
		ft_putstr("sb");
	else if (op == PA)
		ft_putstr("\033[33;1mpa\033[0m");
	else if (op == PB)
		ft_putstr("\033[31mpb\033[0m");
	ft_putchar(' ');
}

void			options(t_env *e, int op)
{
	if (e->option_c == TRUE)
		print_op_color(op);
	if (e->option_c == FALSE)
		print_op(op);
	if (e->option_v == TRUE)
		option_v(e);
}
