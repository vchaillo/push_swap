#include "push_swap.h"

static	void	list_reverse_rotate(t_lst *list)
{
	int	temp;
	int	temp2;
	int	temp3;
	t_lst	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			temp = tmp->val;
		tmp = tmp->next;
	}
	tmp = list;
	temp2 = tmp->val;
	while (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			temp3 = tmp->next->val;
			tmp->next->val = temp2;
			temp2 = temp3;
		}
		tmp = tmp->next;
	}
	list->val = temp;
}

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
	}
	else if (op == RA)
		list_rotate(e->a);
	else if (op == RB)
		list_rotate(e->b);
	else if (op == RRR)
	{
		list_reverse_rotate(e->a);
		list_reverse_rotate(e->b);
	}
	else if (op == RRA)
		list_reverse_rotate(e->a);
	else if (op == RRB)
		list_reverse_rotate(e->b);
}
