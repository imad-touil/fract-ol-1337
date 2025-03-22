NAME = fractol
BNAME = fractol_bonus


CC = cc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lmlx -framework OpenGL -framework AppKit


BLACK = \033[30m
GREEN = \033[32m
RESET = \033[0m
WHITE = \033[37m
UNDER = \033[4m
RE_UN = \033[0m


MSG = "$(GREEN)\n\
╭$(BLACK)━━━$(GREEN)╮       ╭╮     ╭╮$(BLACK)\n\
┃$(GREEN)╭$(BLACK)━━$(GREEN)╯      ╭╯╰╮    $(BLACK)┃┃\n\
┃$(GREEN)╰$(BLACK)━━┳━┳━━┳━┻$(GREEN)╮╭╯ ╭$(BLACK)━━┫┃\n\
┃$(GREEN)╭$(BLACK)━━┫$(GREEN)╭$(BLACK)┫$(GREEN)╭╮$(BLACK)┃$(GREEN)╭$(BLACK)━┫┣━━┫$(GREEN)╭╮$(BLACK)┃┃\n\
┃┃  ┃┃┃$(GREEN)╭╮$(BLACK)┃$(GREEN)╰$(BLACK)━┫$(GREEN)╰$(BLACK)┳━┫$(GREEN)╰╯$(BLACK)┃$(GREEN)╰╮\n\
$(GREEN)╰╯  ╰╯╰╯╰$(BLACK)┻━━┻━$(GREEN)╯ ╰$(BLACK)━━┻━$(GREEN)╯$(RESET)\
 $(GREEN)	Created By: $(UNDER)imatouil$(RE_UN)$(WHITE) ©️$(RESET)\n"

SRC = ./mandatory/src/main.c ./mandatory/src/utils0.c\
	./mandatory/src/utils1.c ./mandatory/src/mandelbrot.c\
	./mandatory/src/julia.c ./mandatory/src/events.c\

OBJ = $(SRC:.c=.o)


B_SRC = ./bonus/src_bonus/main_bonus.c ./bonus/src_bonus/utils0_bonus.c\
		./bonus/src_bonus/burning_bonus.c ./bonus/src_bonus/events_bonus.c\

B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./mandatory/includes/fractol.h
	@echo "$(GREEN)Futur Is Loading..."
	@sleep 0.5
	@echo $(MSG)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)


bonus: $(B_OBJ) ./bonus/includes_bonus/fractol_bonus.h
	@echo $(MSG)
	@$(CC) $(CFLAGS) -o $(BNAME) $(B_OBJ) $(LFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning..."
	@rm -f $(OBJ) $(B_OBJ)
	@sleep 0.3
	@echo "$(GREEN)Done"

fclean: clean
	@rm -f $(NAME) $(BNAME)

re: fclean all


.PHONY: clean 
