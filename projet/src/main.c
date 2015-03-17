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
}

static	void	create_new_element(t_env *e, char *arg)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
	{
		ft_putendl("memory allocation failed");
		exit (0);
	}
	new->val = ft_atoi(arg);
	new->next = e->a;
	e->a = new;
}

static	void	create_list_ab(t_env *e, int ac, char **av)
{
	if (!(e->a = (t_lst *)malloc(sizeof(t_lst))))
	{
		ft_putendl("memory allocation failed");
		exit (0);
	}
	e->a->val = ft_atoi(av[ac - 1]);
	e->a->next = NULL;
	e->nb_elem_a = ac - 1;
	e->nb_elem_b = 0;
	while (ac > 2)
	{
		create_new_element(e, av[ac - 2]);
		ac--;
	}
}

static	void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.a = NULL;
	e.b = NULL;
	e.sort_type = SELECTION;
	if (ac > 2)
	{
		if (check_arg(ac, av) == TRUE)
		{
			create_list_ab(&e, ac, av);
			print_list(e.a);
			ft_putchar('\n');
			sort(&e);
			ft_putchar('\n');
			print_list(e.a);
			ft_putchar('\n');
		}
		else
			error_msg();
	}
	else
		error_msg();
	return (0);
}
