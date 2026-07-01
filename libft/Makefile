# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 19:53:33 by mgadzhim          #+#    #+#              #
#    Updated: 2025/06/01 20:02:15 by mgadzhim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_striteri.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c

OBJ			= $(SRC:.c=.o)

SRC_BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ_BONUS 	= $(SRC_BONUS:.c=.o)

HEADER		= libft.h

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ}

all	: $(NAME)
	
clean	:
	rm -f ${OBJ} ${OBJ_BONUS}
	
fclean	: clean
	rm -f $(NAME)

re	: fclean all

bonus: ${OBJ} ${OBJ_BONUS}
	ar rcs ${NAME} ${OBJ} ${OBJ_BONUS}

.PHONY: all clean fclean re bonus