#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbie <jbarbie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 18:44:07 by jbarbie           #+#    #+#              #
#    Updated: 2015/03/22 01:28:39 by vchaillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	=	push_swap

CC	=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
RM	=	rm -Rf

SRC	=	main.c \
		check.c \
		swap.c \
		rotate.c \
		push.c \
		sort.c \
		sort2.c \
		reverse_rotate.c \
		options.c \
		parser.c \

FILE := $(shell ls libft/libft.a)

LIBFT =	 -Llibft/ -lft

INC	=	-I inc/ -I libft/include/

OBJ	=	$(patsubst %.c, obj/%.o, $(SRC))


all:   $(NAME)
$(NAME): obj $(OBJ)
		
ifneq ($(FILE), libft/libft.a)
	@make -C libft/
endif
	
		@echo "[\033[1;32m******  Creating $(NAME) executable  ******\033[m]"
		@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)

obj/%.o: src/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
		@echo "[\033[1;32m√\033[m]" $<

obj:
		@mkdir -p obj

clean:
		@echo "[\033[31;1m******  Cleaning object files  ******\033[0m]"
		@$(RM) obj/

fclean:	clean
		@echo "[\033[31;1m******  Cleaning executables  ******\033[0m]"
		@$(RM) $(NAME)

norm:
		@echo "[\033[1;32m******  norminette ...  ******\033[0m]"
		@norminette **/*.[ch]

re: fclean all

.PHONY: all obj clean fclean norm re
