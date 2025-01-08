#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
CC        	:= cc
FLAGS    	:= -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)/include
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/stack.c \
                          src/sort_three.c \
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
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

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

${NAME}:	${LIBFT} ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBFT}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

${LIBFT}:
	@echo "$(BLUE)Building libft...$(CLR_RMV)"
	@make -C ${LIBFT_DIR}

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
			@ make -C ${LIBFT_DIR} clean

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			@ make -C ${LIBFT_DIR} fclean

re:			fclean all

.PHONY:		all clean fclean re


