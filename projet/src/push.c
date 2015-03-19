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
		ft_putstr("pb ");
	}
	if (op == PA)
	{
		tmp = e->b;
		e->b = e->b->next;
		tmp->next = e->a;
		e->a = tmp;
		e->nb_elem_a++;
		e->nb_elem_b--;
		ft_putstr("pa ");
	}
	if (e->option_v == TRUE)
	{
		ft_putstr("\033[32mListe a : \033[0m");
		print_list(e->a);
		ft_putchar('\n');
	}
}
