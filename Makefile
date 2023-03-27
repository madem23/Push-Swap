# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdemma <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:57:55 by mdemma            #+#    #+#              #
#    Updated: 2022/04/05 09:46:17 by mdemma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BONUS 		= checker

SRCS		= get_rank.c main.c reverse_rotate.c\
			rotate.c swap_push.c main_sort.c\
			first_sort.c free.c find_scenario.c\
			count_ra.c count_moves_ab.c sort_misc.c\
			check_parsing.c find_scenario_bis.c

SRCS_BONUS	= checker.c r_checker.c rr_checker.c\
			s_p_checker.c read_execute.c check_parsing.c\
			get_rank.c sort_misc.c swap_push.c\
			reverse_rotate.c rotate.c free.c\

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

HEADER		= push_swap.h

CFLAGS		= -Wall -Wextra -Werror

RM 			= rm -f

CC			= gcc

MAKE 		= ./fake_libft/

GREEN       :=  "\033[0;32m"

CYAN        :=  "\033[0;36m"

RESET       :=  "\033[0m"

%.o: 		%.c 
			@${CC} ${CFLAGS} -o $@ -c $< -I ${HEADER}

${NAME}:	${OBJS}
			@make all -C ${MAKE}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} fake_libft/fake_libft.a
			@echo ${GREEN}"Compiled '${NAME}' with success" ${RESET} 

all:		${NAME}

bonus:		${OBJS} ${OBJS_BONUS}
			@make all -C ${MAKE}
			@${CC} ${CFLAGS} -o ${BONUS} ${OBJS_BONUS} -g  fake_libft/fake_libft.a
			@touch bonus
			@echo ${GREEN}"Compiled '${BONUS}' with success" ${RESET} 

clean:
			@${RM} ${OBJS} ${OBJS_BONUS} bonus
			@make clean -C ${MAKE}
			@echo ${CYAN}"Cleaned objects with success"${RESET}

fclean:		clean
			@${RM} ${NAME} ${BONUS} 
			@make fclean -C ${MAKE}
			@echo ${CYAN}"Removed '${NAME}/${BONUS}' with success"${RESET}

re:			fclean all

.PHONY:		 all clean fclean re
