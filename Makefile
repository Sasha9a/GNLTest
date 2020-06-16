NAME = main.out
FLAGS = -g -O0 -Wall -Wextra -Werror -D

SRCS = ../get_next_line.c ../get_next_line_utils.c func.c main.c
SRCS_BONUS = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c func.c main_bonus.c

HEADER = ../get_next_line.h
HEADER_BONUS = ../get_next_line_bonus.h

BUFFER_SIZE = 32

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@gcc $(FLAGS) BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS) -o $(NAME)
	@echo "========== Valgrind ========================"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	@echo "========== Start ==========================="
	@./$(NAME)
	@echo "========== Norminette ======================"
	@norminette $(HEADER) ../get_next_line.c ../get_next_line_utils.c
	@/bin/rm -f $(NAME)

bonus: $(SRCS_BONUS) $(HEADER_BONUS)
	@gcc $(FLAGS) BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS_BONUS) -o $(NAME)
	@echo "========== Valgrind ========================"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	@echo "========== Start ==========================="
	@./$(NAME)
	@echo "========== Norminette ======================"
	@norminette $(HEADER_BONUS) ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
	@/bin/rm -f $(NAME)

fclean:
	@/bin/rm -f $(NAME)

.PHONY: all bonus fclean
