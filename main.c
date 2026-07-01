/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:03:08 by rmarkov           #+#    #+#             */
/*   Updated: 2026/06/28 16:05:48 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal = 0;

static void	run_line(t_shell *shell)
{
	t_token	*tokens;

	if (check_quotes(shell->line) == -1)
	{
		ft_putstr_fd("minishell: unclosed quote\n", STDERR_FILENO);
		shell->exit_status = 2;
		return ;
	}
	tokens = tokenize(shell->line);
	if (!tokens)
		return ;
	expand_tokens(tokens, shell);
	shell->cmds = parse(tokens, shell);
	free_token_list(tokens);
	if (!shell->cmds)
		return ;
	execute(shell);
	free_cmds_full(shell->cmds);
	shell->cmds = NULL;
}

static void	handle_eof(t_shell *shell)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	free_strarr_n(shell->env);
	clear_history();
	exit(shell->exit_status);
}

static void	check_signal(t_shell *shell)
{
	if (g_signal == SIGINT)
	{
		shell->exit_status = 130;
		g_signal = 0;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.env = env_dup(envp);
	shell.exit_status = 0;
	shell.cmds = NULL;
	setup_signals(0);
	while (1)
	{
		check_signal(&shell);
		shell.line = readline(PROMPT);
		if (!shell.line)
			handle_eof(&shell);
		if (ft_strlen(shell.line) > 0)
			add_history(shell.line);
		run_line(&shell);
		free(shell.line);
		shell.line = NULL;
	}
	return (EXIT_SUCCESS);
}
