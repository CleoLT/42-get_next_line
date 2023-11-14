NAME = get_next_line.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall -D BUFFER_SIZE=$(SIZE)

SRCS = ../get_next_line.c 

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		ar -r $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: 
		$(RM) $(NAME)

re: fclean all
