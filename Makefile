NAME 	= push_swap
CC 		= cc
FLAGS 	= -Wall -Werror -Wextra

LIBFT_INC = libft/include
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

VPATH 	= src

SOURCES = main.c stack_util.c stack_actions.c stack_actions_2.c math_utils.c algorithms.c stack_util_2.c
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

$(NAME): $(OBJECTS) libft.a
	$(CC) $(FLAGS) -o push_swap $(OBJECTS) libft.a

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)⏳ Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -c $< -o $@
	@echo "$(GREEN)✅ $< compiled!$(RESET)"

all: $(NAME)
	@echo "$(GREEN)✅ Building all targets...$(RESET)"

libft.a:
	@make -C libft
	mv libft/libft.a libft.a

clean:
	@echo "$(RED)🗑️  Cleaning all object files...$(RESET)"
	$(RM) $(OBJS)

fclean:	clean
	@echo "$(RED)🗑️  Cleaning $(NAME)...$(RESET)"
	$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm libft.a

re:	fclean all

.PHONY: $(NAME) all clean fclean re
