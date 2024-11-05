# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 13:15:52 by eproust           #+#    #+#              #
#    Updated: 2024/11/05 13:26:49 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= gnl
FLAGS	:= -Wall -Wextra -Werror 

SRCS	:= get_next_line_utils.c \
	get_next_line.c \
	main.c \
                          
OBJS	:= $(SRCS:.c=.o)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

RED		:= \033[1;31m
GREEN	:= \033[1;32m
YELLOW	:= \033[1;33m
BLUE	:= \033[1;34m
END		:= \033[0m

$(NAME):	$(OBJS)
	@echo "\n$(YELLOW)Compilation of '$(NAME)':$(END)"
	gcc $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(GREEN)Created '$(NAME)' ✓$(END)"

all:		$(NAME)

clean:
	@ echo "\n$(RED)Delete .o files:$(END)"
	rm -f *.o */*.o */*/*.o

fclean:		clean
	@ echo "\n$(RED)Delete binary file:$(END)"
	rm -f $(NAME)

re:			fclean all

test:		re
	@ echo "\n$(BLUE)Run '$(NAME)':$(END)"
	@./$(NAME)

.PHONY:		all clean fclean re
