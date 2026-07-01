/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:00:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/06/29 12:00:00 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_count(t_cmd *cmds)
{
	int	n;

	n = 0;
	while (cmds)
	{
		n++;
		cmds = cmds->next;
	}
	return (n);
}

pid_t	safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("minishell: fork");
	return (pid);
}

void	close_pipes(int *pipes, int n)
{
	int	i;

	i = 0;
	while (i < 2 * (n - 1))
		close(pipes[i++]);
}

int	wait_children(pid_t *pids, int n)
{
	int	i;
	int	status;
	int	last;

	i = 0;
	last = 0;
	while (i < n)
	{
		waitpid(pids[i], &status, 0);
		if (i == n - 1)
			last = handle_wait_status(status);
		i++;
	}
	return (last);
}

void	spawn_children(t_shell *shell, int n, int *pipes, pid_t *pids)
{
	t_cmd	*cmd;
	int		info[2];
	int		i;

	cmd = shell->cmds;
	i = -1;
	info[1] = n;
	while (++i < n)
	{
		info[0] = i;
		pids[i] = safe_fork();
		if (pids[i] == 0)
			child_exec(shell, cmd, info, pipes);
		cmd = cmd->next;
	}
}
