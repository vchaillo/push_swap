/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 21:51:25 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/19 23:10:27 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define TRUE 0
# define FALSE 1

# define SELECTION 1
# define INSERTION 2
# define BUBBLE 3

# define SS 1
# define SA 2
# define SB 3
# define RR 4
# define RA 5
# define RB 6
# define RRR 7
# define RRA 8
# define RRB 9
# define PB 0
# define PA -1

# define MAX 2147483647
# define MIN -2147483648

typedef	struct		s_lst
{
	int				val;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	int				nb_elem_a;
	int				nb_elem_b;
	int				nb_options;
	int				option_v;
	int				option_n;
	int				option_c;
	int				nb_op;
	int				end;
	t_lst			*a;
	t_lst			*b;
}					t_env;

int					check_arg(int ac, char **av);
void				parse_options(t_env *e, char **av);
void				sort(t_env *e);
void				simple_sort(t_env *e);
void				do_swap(t_env *e, int op);
void				do_rotate(t_env *e, int op);
void				do_reverse_rotate(t_env *e, int op);
void				do_push(t_env *e, int op);
void				options(t_env *e, int op);

#endif
