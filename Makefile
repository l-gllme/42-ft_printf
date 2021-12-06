# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 11:04:55 by lguillau          #+#    #+#              #
#    Updated: 2021/12/06 14:53:15 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./ft_printf.c ./srcs/tools_2.c ./srcs/checks.c ./srcs/tools.c \
		./srcs/parsing.c ./srcs/tools_3.c ./srcs/checks_2.c \
		./bonus/conv_pc_bonus.c \
		./bonus/conv_di_bonus.c \
		./bonus/conv_di_2_bonus.c \
		./bonus/conv_s_bonus.c \
		./bonus/conv_u_bonus.c \
		./bonus/conv_x_bonus.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

HEADERS	=	includes

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

${NAME}:	libft ${OBJS}
			cp libft/libft.a ./
			mv libft.a libftprintf.a
			ar rc ${NAME} ${OBJS}

all:		${NAME}

.c.o:		
			${CC} -I ${HEADERS} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:		
		make -C libft

clean:		
			${RM} ${OBJS}
			make -C libft clean

fclean:		clean
			${RM} ${NAME}
			make -C libft fclean

re:		fclean all

bonus:		all

.PHONY:		all clean fclean re libft bonus
