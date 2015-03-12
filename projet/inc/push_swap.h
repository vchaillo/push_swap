#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	struct		s_lst
{
	int		val;
	struct	s_lst	*next;
}			t_lst;

void			error_msg(void);

#endif
