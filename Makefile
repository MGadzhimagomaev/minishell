NAME		= minishell
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_PARSING	= src/parsing/lexer.c \
			  src/parsing/lexer2.c \
			  src/parsing/lexer_utils.c \
			  src/parsing/parser.c \
			  src/parsing/parser2.c \
			  src/parsing/parser_utils.c \
			  src/parsing/expand.c \
			  src/parsing/expand_utils.c

SRC_EXEC	= src/exec/executor.c \
			  src/exec/executor_utils.c \
			  src/exec/exec_cmd.c \
			  src/exec/path.c \
			  src/exec/redirects.c \
			  src/exec/heredoc.c

SRC_BUILTINS	= src/builtins/builtins.c \
				  src/builtins/ft_echo.c \
				  src/builtins/ft_cd.c \
				  src/builtins/ft_pwd.c \
				  src/builtins/ft_export.c \
				  src/builtins/ft_unset.c \
				  src/builtins/ft_env.c \
				  src/builtins/ft_exit.c

SRC_UTILS	= src/utils/signals.c \
			  src/utils/env_utils.c \
			  src/utils/env_utils2.c \
			  src/utils/free.c

SRC			= main.c \
			  $(SRC_PARSING) \
			  $(SRC_EXEC) \
			  $(SRC_BUILTINS) \
			  $(SRC_UTILS)

OBJ			= $(SRC:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
