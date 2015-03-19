#include "push_swap.h"

void	print_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->val);
		ft_putstr(", ");
		tmp = tmp->next;
	}
}
