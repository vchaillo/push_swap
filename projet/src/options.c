#include "push_swap.h"

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
}

void		options(t_env *e, int op)
{
	if (e->option_v == TRUE)
		option_v(e);
	//if (e->option_c == TRUE)
	//	print_op_color(op);
	if (e->option_c == FALSE)
		print_op(op);
}
