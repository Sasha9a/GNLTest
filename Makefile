NAME = main
FLAGS = -Wall -Wextra -Werror -D

SRCS = ../get_next_line.c ../get_next_line_utils.c func.c main.c
SRCS_BONUS = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c func.c main_bonus.c

HEADER = ../get_next_line.h
HEADER_BONUS = ../get_next_line_bonus.h

BUFFER_SIZE = 32

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@gcc $(FLAGS) BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS) -o $(NAME)
	@./$(NAME)
	@/bin/rm -f $(NAME)

bonus: $(SRCS_BONUS) $(HEADER_BONUS)
	@gcc $(FLAGS) BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS_BONUS) -o $(NAME)
	@./$(NAME)
	@/bin/rm -f $(NAME)

.PHONY: all bonus