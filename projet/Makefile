#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbie <jbarbie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 18:44:07 by jbarbie           #+#    #+#              #
#    Updated: 2015/03/01 22:35:35 by vchaillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	=	push_swap

CC	=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

SRC	=	main.c \
		check.c \
		swap.c \

LIBFT	=	-Llibft/ -lft

INC	=	-I inc/ -I libft/includes/

OBJ	=	$(patsubst %.c, obj/%.o, $(SRC))

RM	=	rm -Rf

all:   $(NAME)


$(NAME): obj $(OBJ)
		@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBMLX) $(LIBFT)

obj/%.o: src/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
		@echo "[\033[1;32m√\033[m]" $<

obj:
		@mkdir -p obj

clean:
		@echo "\033[33;31mCleaning files .o ...\033[0m"
		@$(RM) obj/

fclean:	clean
		@echo "\033[33;31mCleaning executables...\033[0m"
		@$(RM) $(NAME)

norm:
		@echo "\033[32mnorminette...\033[0m"
		@norminette **/*.[ch]

re: fclean all

.PHONY: all clean fclean norm re
