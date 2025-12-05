# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 11:40:57 by osukhore          #+#    #+#              #
#    Updated: 2025/12/05 11:39:53 by osukhore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := get_next_line.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
#CFLAGS += -D BUFFER_SIZE=42

OBJ_DIR := obj
IFLAGS  := -I.

SRC_FILES := \
	get_next_line.c \
	get_next_line_utils.c

OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	@rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

test: re
	$(CC) $(CFLAGS) $(IFLAGS) OS_gnl.c $(NAME)
	./a.out

.PHONY: all clean fclean re test
