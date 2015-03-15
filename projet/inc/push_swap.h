#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define TRUE 0
# define FALSE 1

# define SS 1
# define SA 2
# define SB 3

# define RR 1
# define RA 2
# define RB 3
# define RRR 4
# define RRA 5
# define RRB 6

# define PB 1
# define PA 2

# define MAX 2147483647
# define MIN -2147483648

typedef	struct		s_lst
{
	int		val;
	struct	s_lst	*next;
}			t_lst;

typedef struct		s_env
{
	int		nb_elem_a;
	int		nb_elem_b;
	int		option_v;
	int		option_n;
	int		option_c;
	t_lst		*a;
	t_lst		*b;
}			t_env;

int			check_arg(int ac, char **av);
void			do_swap(t_env *e, int op);
void			do_rotate(t_env *e, int op);
void			do_push(t_env *e, int op);

#endif
