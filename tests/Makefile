NAME = test_gnl

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g -D BUFFER_SIZE=$(SIZE)

SRCS = ../get_next_line.c ../get_next_line_utils.c test_gnl.c 

OBJS = $(SRCS:.c=.o)

INCLUDE = Makefile ../get_next_line.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

clean:  
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
