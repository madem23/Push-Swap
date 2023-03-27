# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdemma <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:57:55 by mdemma            #+#    #+#              #
#    Updated: 2022/03/29 16:34:36 by mdemma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fake_libft.a

SRCS		= ft_putstr_fd.c ft_atoi_check_int.c ft_isdigit.c ft_split.c\
			  ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_lstlast.c\
			  ft_strncmp.c get_next_line.c get_next_line_utils.c
		
OBJS		= ${SRCS:.c=.o}

HEADER		= fake_libft.h

CFLAGS		= -Wall -Wextra -Werror

RM 			= rm -f

CC			= gcc

GREEN       :=  "\033[0;32m"

CYAN        :=  "\033[0;36m"

RESET       :=  "\033[0m"

%.o: 		%.c 
			@${CC} ${CFLAGS} -D BUFFER_SIZE=3 -o $@ -c $< -I ${HEADER}

${NAME}:	${OBJS}
			@ar rcs ${NAME} ${OBJS}
			@echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

all:		${NAME}
			
clean:
			@${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			@${RM} ${NAME}
			@echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re:			fclean all

.PHONY:		 all clean fclean re
