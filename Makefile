# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/03 20:19:19 by yizhang       #+#    #+#                  #
#    Updated: 2022/11/03 20:19:21 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS):$(SRCS)
	$(CC) $(FLAGS) $(SRCS)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	fclean all