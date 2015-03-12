#include "push_swap.h"

static void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int		main(int ac, char **av)
{
	(void)av;
	if (ac > 2)
	{
		if (check_arg(ac, av) == TRUE)
		{
			ft_putendl("done!");
			//create_list_ab();
			//sort_stack();
		}
		else
			error_msg();
	}
	else
		error_msg();
	return (0);
}
