#include "push_swap.h"

static	void	selection_sort(t_env *e)
{
	(void)e;
}

void		sort(t_env *e)
{
	if (e->sort_type == SELECTION)
		selection_sort(e);
	else if (e->sort_type == INSERTION)
		selection_sort(e);
	else if (e->sort_type == BUBBLE)
		selection_sort(e);
}
