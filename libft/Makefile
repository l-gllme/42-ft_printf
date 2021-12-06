# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:02:12 by lguillau          #+#    #+#              #
#    Updated: 2021/11/29 15:21:11 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	./ft_atoi.c \
		./ft_isdigit.c \
		./ft_isalpha.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_strlen.c \
		./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memchr.c \
		./ft_strnstr.c \
		./ft_toupper.c \
		./ft_tolower.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strncmp.c \
		./ft_memcmp.c \
		./ft_strlcpy.c \
		./ft_putchar_fd.c \
		./ft_putstr_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c \
		./ft_calloc.c \
		./ft_strdup.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_split.c \
		./ft_strmapi.c \
		./ft_substr.c \
		./ft_strtrim.c \
		./ft_itoa.c \
		./ft_striteri.c \

B_SRCS	=	./ft_lstnew.c \
		./ft_lstadd_front.c \
		./ft_lstsize.c \
		./ft_lstlast.c \
		./ft_lstadd_back.c \
		./ft_lstdelone.c \
		./ft_lstclear.c \
		./ft_lstiter.c \
		./ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

B_OBJS	= ${B_SRCS:.c=.o}

HEADERS = includes

CC		= clang
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:		${B_OBJS}
			ar rc ${NAME} ${B_OBJS}

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:	
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus 
