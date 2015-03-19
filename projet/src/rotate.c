#include "push_swap.h"

static	void	list_rotate(t_lst *list)
{
	int	temp;
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

void		do_rotate(t_env *e, int op)
{
	if (op == RR)
	{
		list_rotate(e->a);
		list_rotate(e->b);
		ft_putstr("rr ");
	}
	else if (op == RA)
	{
		list_rotate(e->a);
		ft_putstr("ra ");
	}
	else if (op == RB)
	{
		list_rotate(e->b);
		ft_putstr("rb ");
	}
	if (e->option_v == TRUE)
	{
		ft_putstr("\033[32mListe a : \033[0m");
		print_list(e->a);
		ft_putchar('\n');
	}
	e->nb_op++;
}
