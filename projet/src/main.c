#include "push_swap.h"

static	void	create_new_element(t_env *e, char *arg)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
	{
		ft_putendl("memory allocation failed");
		exit (0);
	}
	(void)e;
	(void)arg;
	ft_putendl("seg seg seg segfaullllltttt!!!!");
	e->a->val = ft_atoi(arg);
	//e->a->next = e->a;
}

static	void	create_list_ab(t_env *e, int ac, char **av)
{
	int	i;

	i = 1;
	if (!(e->a = (t_lst *)malloc(sizeof(t_lst))))
	{
		ft_putendl("memory allocation failed");
		exit (0);
	}
	e->a->val = ft_atoi(av[i]);
	ft_putendl("seg seg seg segfaullllltttt!!!!");
	//e->a->next = NULL;		// Why this fucking segfault?
	//e->b->next = NULL;
	i = ac;
	while (i > 1)
	{
		create_new_element(e, av[i]);
		i--;
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

	if (ac > 2)
	{
		if (check_arg(ac, av) == TRUE)
		{
			ft_putendl("done!");
			create_list_ab(&e, ac, av);
			//sort_stack();
		}
		else
			error_msg();
	}
	else
		error_msg();
	return (0);
}
