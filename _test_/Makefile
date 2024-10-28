# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 17:19:37 by eproust           #+#    #+#              #
#    Updated: 2024/10/21 19:25:00 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = get_next_line.a
NAME = get_next_line

DEFINES = -D BUFFER_SIZE=4 -D FILENAME=\"test_lorem.txt\"

C_DIR = ../

C_FILES = get_next_line.c \
           get_next_line_utils.c

C_MAIN = main.c

H_DIR = ../

O_FILES = $(addprefix $(C_DIR), $(C_FILES:.c=.o))
O_MAIN = $(C_MAIN:.c=.o)

FLAGS = -Wall -Wextra -Werror -I $(H_DIR) $(DEFINES)

all: $(NAME)

$(C_DIR)%.o: $(C_DIR)%.c
	gcc -c $< -o $@ $(FLAGS)

$(O_MAIN): $(C_MAIN) 
	gcc -c $< -o $@ $(FLAGS)

$(NAME): $(LIB) $(O_MAIN)
	gcc -o $@ $(O_MAIN) $(LIB) $(FLAGS)
	@echo "     ┌─────────────┐"
	@echo "─────┤ Test Output ├───────"
	@echo "     └─────────────┘"
	@./$@ | cat -e
	@echo "\n───────────────────────────"
	rm -f $(O_MAIN)

$(LIB): $(O_FILES)
	ar rcs $@ $^

clean:
	rm -f $(O_FILES) $(O_MAIN)

fclean: clean
	rm -f $(LIB) $(NAME) 

re: fclean all

.PHONY: all clean fclean re test

