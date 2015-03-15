#include "push_swap.h"

static	void	list_swap(t_lst *lst)
{
	int	tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}

void	do_swap(t_env *e, int op)
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
}
