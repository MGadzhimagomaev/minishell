/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:20:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/06/29 12:00:00 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* info[0] = index, info[1] = total commands */
void	child_exec(t_shell *shell, t_cmd *cmd, int *info, int *pipes)
{
	child_signals();
	if (info[0] > 0)
		dup2(pipes[(info[0] - 1) * 2], STDIN_FILENO);
	if (info[0] < info[1] - 1)
		dup2(pipes[info[0] * 2 + 1], STDOUT_FILENO);
	close_pipes(pipes, info[1]);
	if (apply_redirs(cmd->redirs) == -1)
		exit(1);
	if (cmd->args && is_builtin(cmd->args[0]))
		exit(exec_builtin(shell, cmd));
	exec_external(shell, cmd);
	exit(1);
}

int	exec_pipeline(t_shell *shell, int n)
{
	int		*pipes;
	pid_t	*pids;
	int		i;

	pipes = malloc(sizeof(int) * 2 * (n - 1));
	pids = malloc(sizeof(pid_t) * n);
	if (!pipes || !pids)
		return (free(pipes), free(pids), 1);
	i = -1;
	while (++i < n - 1)
		pipe(pipes + i * 2);
	spawn_children(shell, n, pipes, pids);
	close_pipes(pipes, n);
	i = wait_children(pids, n);
	return (free(pipes), free(pids), i);
}

static int	exec_single_builtin(t_shell *shell, t_cmd *cmd)
{
	int	saved_in;
	int	saved_out;
	int	status;

	if (!save_fds(&saved_in, &saved_out))
		return (1);
	if (apply_redirs(cmd->redirs) == -1)
		return (restore_fds(saved_in, saved_out), 1);
	status = exec_builtin(shell, cmd);
	restore_fds(saved_in, saved_out);
	return (status);
}

int	exec_single(t_shell *shell, t_cmd *cmd)
{
	int		status;
	pid_t	pid;

	if (!cmd->args || !cmd->args[0])
	{
		if (apply_redirs(cmd->redirs) == -1)
			return (1);
		return (0);
	}
	if (is_builtin(cmd->args[0]))
		return (exec_single_builtin(shell, cmd));
	pid = safe_fork();
	if (pid == 0)
	{
		child_signals();
		if (apply_redirs(cmd->redirs) == -1)
			exit(1);
		exec_external(shell, cmd);
		exit(1);
	}
	waitpid(pid, &status, 0);
	return (handle_wait_status(status));
}

int	execute(t_shell *shell)
{
	int	n;
	int	status;

	if (!shell->cmds)
		return (0);
	if (setup_heredocs(shell->cmds, shell) == -1)
		return (shell->exit_status);
	n = cmd_count(shell->cmds);
	if (n == 1)
		status = exec_single(shell, shell->cmds);
	else
		status = exec_pipeline(shell, n);
	shell->exit_status = status;
	return (status);
}
