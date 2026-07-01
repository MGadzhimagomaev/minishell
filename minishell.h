/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:03:33 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/18 19:44:11 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <string.h>
# include <dirent.h>
# include "libft/libft.h"

extern int	g_signal;

# define PROMPT "minishell$ "

typedef enum e_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
	TOKEN_EOF
}	t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	int				has_quote;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	t_type			type;
	char			*file;
	int				heredoc_fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	*line;
	char	**env;
	int		exit_status;
	t_cmd	*cmds;
}	t_shell;

/* lexer.c */
t_token	*tokenize(char *line);
t_token	*new_token(t_type type, char *value, int has_quote);
void	token_add_back(t_token **lst, t_token *tok);
int		is_whitespace(char c);
int		is_operator(char c);

/* lexer2.c */
void	lex_one(char *line, int *i, t_token **list);

/* lexer_utils.c */
char	*get_word(char *line, int *i);
char	*get_quoted(char *line, int *i, char quote);
t_type	get_redir_type(char *line, int *i);
int		check_quotes(char *line);
char	*merge_word_parts(char *line, int *i, int *has_q);

/* parser.c */
t_cmd	*parse(t_token *tokens, t_shell *shell);
t_cmd	*new_cmd(void);
int		parse_redir(t_token **tok, t_cmd *cmd);
int		parse_word(t_token **tok, t_cmd *cmd);

/* parser2.c */
int		syntax_error(char *token);
int		leading_pipe(t_token *tokens, t_shell *shell);
int		pipe_advance(t_token **tok, t_cmd *head, t_shell *shell);

/* parser_utils.c */
void	cmd_add_arg(t_cmd *cmd, char *arg);
void	cmd_add_redir(t_cmd *cmd, t_redir *redir);
t_redir	*new_redir(t_type type, char *file);
int		count_args(t_cmd *cmd);
void	free_redir_node(t_redir *redir);

/* expand.c */
char	*expand_str(char *str, t_shell *shell);
char	*expand_dquote(char *str, int *i, t_shell *shell);
char	*expand_squote(char *str, int *i);
char	*get_var_name(char *str, int *i);
char	*get_var_value(char *name, t_shell *shell);

/* expand_utils.c */
char	*expand_dollar(char *str, int *i, t_shell *shell);
char	*str_append(char *dst, char *src);
char	*str_append_c(char *dst, char c);
void	expand_tokens(t_token *tokens, t_shell *shell);
int		is_valid_var_char(char c);

/* env_utils.c */
char	*ft_getenv(char *name, char **env);
int		env_set(char **env, char *name, char *value);
char	**env_add(char **env, char *entry);
char	**env_remove(char **env, char *name);
int		env_count(char **env);

/* env_utils2.c */
char	*make_env_entry(char *name, char *value);
char	**env_dup(char **env);
int		valid_identifier(char *name);
char	*get_env_name(char *entry);
int		env_exists(char *name, char **env);

/* executor.c */
int		execute(t_shell *shell);
int		exec_pipeline(t_shell *shell, int n);
int		exec_single(t_shell *shell, t_cmd *cmd);
void	child_exec(t_shell *shell, t_cmd *cmd, int *info, int *pipes);

/* executor_utils.c */
int		cmd_count(t_cmd *cmds);
pid_t	safe_fork(void);
void	close_pipes(int *pipes, int n);
int		wait_children(pid_t *pids, int n);
void	spawn_children(t_shell *shell, int n, int *pipes, pid_t *pids);

/* exec_cmd.c */
int		is_builtin(char *name);
int		exec_builtin(t_shell *shell, t_cmd *cmd);
void	exec_external(t_shell *shell, t_cmd *cmd);
void	print_cmd_error(char *cmd, char *msg);
int		handle_wait_status(int status);

/* path.c */
char	*resolve_path(char *name, char **env);
char	**get_path_dirs(char **env);
char	*check_in_dirs(char **dirs, char *name);
int		is_valid_path(char *path);
void	free_strarr(char **arr);

/* redirects.c */
int		apply_redirs(t_redir *redirs);
int		redir_in(char *file);
int		redir_out(char *file, t_type type);
int		save_fds(int *saved_in, int *saved_out);
void	restore_fds(int saved_in, int saved_out);

/* heredoc.c */
int		setup_heredocs(t_cmd *cmds, t_shell *shell);
int		heredoc(t_redir *redir, t_shell *shell);
int		heredoc_loop(char *delim, int fd, t_shell *shell, int expand);
char	*expand_heredoc_line(char *line, t_shell *shell);
int		delim_quoted(char *raw, char **clean);

/* signals.c */
void	setup_signals(int mode);
void	sigint_handler(int sig);
void	sig_ignore(int sig);
void	child_signals(void);
void	heredoc_signals(void);

/* builtins.c */
int		builtin_dispatch(t_shell *shell, t_cmd *cmd);

/* ft_echo.c */
int		builtin_echo(t_cmd *cmd);

/* ft_cd.c */
int		builtin_cd(t_cmd *cmd, t_shell *shell);
int		update_pwd(t_shell *shell, char *old_pwd);

/* ft_pwd.c */
int		builtin_pwd(t_shell *shell);

/* ft_export.c */
int		builtin_export(t_cmd *cmd, t_shell *shell);
void	print_export(char **env);
int		export_set(t_shell *shell, char *arg);

/* ft_unset.c */
int		builtin_unset(t_cmd *cmd, t_shell *shell);

/* ft_env.c */
int		builtin_env(t_cmd *cmd, t_shell *shell);

/* ft_exit.c */
int		builtin_exit(t_cmd *cmd, t_shell *shell);

/* free.c */
void	free_cmd(t_cmd *cmd);
void	free_cmds_full(t_cmd *cmds);
void	free_redir_list(t_redir *redir);
void	free_strarr_n(char **arr);
void	free_token_list(t_token *tokens);

#endif
