NAME = fractol
CC = cc
# CFLAGS = -Wall -Werror -Wextra
LMX_F = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

SRC = fractol.c ./mandatory/operations.c ./mandatory/ft_strlen.c\
	./mandatory/ft_strncmp.c ./mandatory/ft_putendl_fd.c\
	./mandatory/fractol_init.c


OBJS = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LMX_F) $(OBJS) -o $(NAME)


%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean