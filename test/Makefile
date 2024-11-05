# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 13:15:52 by eproust           #+#    #+#              #
#    Updated: 2024/11/05 14:28:11 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= gnl

C_FILES		= get_next_line_utils.c \
	get_next_line.c 

C_TEST		= main.c

C_DIR		= ../
H_DIR		= ../
TEST_DIR	= ./

FLAGS		= -Wall -Wextra -Werror -I $(H_DIR)

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
END			= \033[0m

SRCS		= $(addprefix $(C_DIR), $(C_FILES)) $(addprefix $(TEST_DIR), $(C_TEST))
OBJS		= $(SRCS:.c=.o)

.c.o:
	gcc -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):	$(OBJS)
	@echo "\n$(YELLOW)Compilation of '$(NAME)':$(END)"
	gcc -o $(NAME) $(OBJS) $(FLAGS)
	@echo "\n$(GREEN)Created '$(NAME)' ✓$(END)"

all:		$(NAME)

clean:
	@ echo "\n$(RED)Delete .o files:$(END)"
	rm -f $(C_DIR)*.o $(TEST_DIR)*.o

fclean:		clean
	@ echo "\n$(RED)Delete binary file:$(END)"
	rm -f $(NAME)

re:			fclean all

test:		re
	@ echo "\n$(BLUE)Run '$(NAME)':$(END)"
	@./$(NAME)

.PHONY:		all clean fclean re
