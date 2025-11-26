# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osukhore <osukhore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 11:40:57 by osukhore          #+#    #+#              #
#    Updated: 2025/11/26 14:54:44 by osukhore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := get_next_line.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -D BUFFER_SIZE=n
#CFLAGS += -g

OBJ_DIR = obj/
LIFLAGS = -L.
LFLAGS = -lftgnl
LFLAGS += -lft

SRC_FILES := \
get_next_line.c \

OBJ_FILES := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBDIR)
	cp $(LIBFT) $(NAME)

clean:
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(OBJ_FILES)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean all

test: fclean $(NAME)
	$(CC) $(CFLAGS) OS_gnl.c $(IFLAGS) $(LIFLAGS) $(LFLAGS)
#	valgrind ./a.out
	./a.out

.PHONY: all clean fclean re test
