# PROGRAM
NAME = historian_hysteria

# COMPILATION
CC = clang
CFLAGS = -Wall -Wextra -Werror

# SRC FILES
SRCS = historian_hysteria.c \
		operations/operations.c \
		string/ft_split.c \
		string/get_next_line.c \
		t_list/init_stack.c 

# OBJ
OBJS = $(SRCS:.c=.o)

# RULES
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)