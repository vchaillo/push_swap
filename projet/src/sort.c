#include "push_swap.h"

static	void	choose_rotate_way(t_env *e, int dist, int *way)
{
	int	i;

	if (dist <= (e->nb_elem_a / 2))
	{
		i = 0;
		while (i < dist)
		{
			do_rotate(e, RA);
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
			i--;
			*way = -1;
		}
	}
}

static	void	get_min_first(t_env *e, t_lst *list, int *way)
{
	t_lst	*tmp;
	int	min;
	int	dist;
	int	i;

	tmp = list;
	dist = 0;
	i = 0;
	min = tmp->val;
	while (tmp != NULL)
	{
		if (min > tmp->val)
		{
			min = tmp->val;
			dist = i;
		}
		tmp = tmp->next;
		i++;
	}
	choose_rotate_way(e, dist, way);
}

static	int	is_sort(t_lst *list)
{
	t_lst	*tmp;
	int	nb;

	tmp = list;
	while (tmp != NULL)
	{
		nb = tmp->val;
		if (tmp->next && tmp->next->val < nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		simple_sort(t_env *e)
{
	t_lst	*tmp;
	int	i;
	int	nb;

	if (e->nb_elem_a == 3)
	{
		if (e->a->val > e->a->next->val &&
			e->a->next->val > e->a->next->next->val)
		{
			do_swap(e, SA);
			do_reverse_rotate(e, RRA);
		}
	}
	if (e->a->val > e->a->next->val &&
		e->a->next->val < e->a->next->next->val)
		do_swap(e, SA);
	i = 0;
	tmp = e->a;
	while (i < e->nb_elem_a - 2)
	{
		nb = tmp->val;
		if (tmp->next->val < nb)
			return (0);
		tmp = tmp->next;
		i++;
	}
	if (tmp->val > tmp->next->val)
	{
			do_reverse_rotate(e, RRA);
			do_reverse_rotate(e, RRA);
			do_swap(e, SA);
			do_rotate(e, RA);
			do_rotate(e, RA);
	}
	return (1);
}

void		sort(t_env *e)
{
	int	way;

	while (e->a->next != NULL)
	{
		get_min_first(e, e->a, &way);
		if (is_sort(e->a))
			break ;
		do_push(e, PB);
	}
	while (e->b != NULL)
	{
		do_push(e, PA);
	}
}
