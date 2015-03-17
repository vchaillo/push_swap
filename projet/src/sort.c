#include "push_swap.h"

static	int	choose_rotate_way(t_env *e, int dist, int *way)
{
	int	i;
	int	nb;

	nb = 0;
	if (dist <= (e->nb_elem_a / 2))
	{
		i = 0;
		while (i < dist)
		{
			do_rotate(e, RA);
			nb++;
			i++;
			*way = 1;
		}
	}
	else
	{
		i = e->nb_elem_a;
		while (i > dist)
		{
			do_reverse_rotate(e, RRA);
			nb++;
			i--;
			*way = -1;
		}
	}
	return (nb);
}

static	int	get_min_first(t_env *e, t_lst *list, int *way)
{
	t_lst	*tmp;
	int	min;
	int	dist;
	int	i;
	int	nb;

	tmp = list;
	dist = 0;
	i = 0;
	min = tmp->val;
	while (tmp != NULL)
	{
		if (min > tmp->val)
		{
			dist = i;
		}
		tmp = tmp->next;
		i++;
	}
	nb = choose_rotate_way(e, dist, way);
	return (nb);
}
static	void	selection_sort(t_env *e)
{
	int	nb;
	int	way;

	while (e->a->next != NULL)
	{
		nb = get_min_first(e, e->a, &way);
		do_push(e, PB);
		while (nb > 0)
		{
			if (way == 1)
				do_rotate(e, RA);
			if (way == -1)
				do_reverse_rotate(e, RRA);
			nb--;
		}
	}
	while (e->b != NULL)
	{
		do_push(e, PA);
	}
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
