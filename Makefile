#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
NAME_BONUS	:= checker
LIBFT_DIR	:= ./libft
LIBFT		:= libft.a
CC        	:= cc
FLAGS    	:= -g -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)/include
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/stack.c \
					src/sort_couple.c \
					src/find_min_max.c \
					src/move_costs.c \
					src/move_cheapest.c \
					src/list_debug.c \
					src/check_cheapest.c \
					src/new_element_a.c \
					src/rev_rotations.c \
					src/move_back.c \
					src/sorting.c \
					src/rotations.c \
					src/swap.c \
					src/stack_positioning.c \
					src/max_min_a.c \
					src/push_swap.c \
					src/linked_list.c \
					src/validate_input.c \
					src/input_util.c \

SRCS_BONUS		:=	src/checker.c \
					src/sort_couple.c \
					src/find_min_max.c \
					src/move_costs.c \
					src/move_cheapest.c \
					src/list_debug.c \
					src/check_cheapest.c \
					src/new_element_a.c \
					src/rev_rotations.c \
					src/move_back.c \
					src/sorting.c \
					src/rotations.c \
					src/swap.c \
					src/stack_positioning.c \
					src/max_min_a.c \
					src/linked_list.c \
					src/validate_input.c \
					src/input_util.c \
					src/stack.c \

OBJ_DIR		:= obj
OBJS        := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS  := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

${NAME}:	${LIBFT} ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBFT}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

${NAME_BONUS}:	${LIBFT} ${OBJS_BONUS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME_BONUS) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT}
			@echo "$(GREEN)$(NAME_BONUS) created[0m ✔️"

${LIBFT}:
	@echo "$(BLUE)Building libft...$(CLR_RMV)"
	@make -C ${LIBFT_DIR}
	@cp ${LIBFT_DIR}/libft.a ./${LIBFT}
	@echo "$(GREEN)Libft created ✔️$(CLR_RMV)"

all:		${NAME}

bonus:		${NAME_BONUS}

clean:
			@ ${RM} -r $(OBJ_DIR)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
			@ make -C ${LIBFT_DIR} clean

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			@ make -C ${LIBFT_DIR} fclean
			@ ${RM} ${LIBFT}

re:			fclean all

.PHONY:		all clean fclean re


