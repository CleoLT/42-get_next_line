NAME = test_gnl

CC = gcc

CFLAGS = -Werror -Wextra -Wall -D BUFFER_SIZE=$(SIZE)

SRCS = ../get_next_line.c test_gnl.c 

OBJS = $(SRCS:.c=.o)

INCLUDE = Makefile ../get_next_line.c

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: 
		$(RM) $(NAME)

re: fclean all
