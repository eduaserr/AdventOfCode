# PROGRAM
NAME = Red-Nosed.out

# COMPILATION
CC = clang
CFLAGS = -Wall -Wextra -Werror

# SRC FILES
SRCS = Red-Nosed.c \
		parse/ft_check.c \
		string/ft_split.c \
		string/get_next_line.c

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