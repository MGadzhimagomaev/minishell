/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:05:18 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/18 12:40:55 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_wait_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 19);
		return (128 + WTERMSIG(status));
	}
	return (0);
}

void	print_cmd_error(char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	is_builtin(char *name)
{
	if (!name)
		return (0);
	if (ft_strncmp(name, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(name, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(name, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(name, "export", 7) == 0)
		return (1);
	if (ft_strncmp(name, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(name, "env", 4) == 0)
		return (1);
	if (ft_strncmp(name, "exit", 5) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_shell *shell, t_cmd *cmd)
{
	char	*name;

	name = cmd->args[0];
	if (ft_strncmp(name, "echo", 5) == 0)
		return (builtin_echo(cmd));
	if (ft_strncmp(name, "cd", 3) == 0)
		return (builtin_cd(cmd, shell));
	if (ft_strncmp(name, "pwd", 4) == 0)
		return (builtin_pwd(shell));
	if (ft_strncmp(name, "export", 7) == 0)
		return (builtin_export(cmd, shell));
	if (ft_strncmp(name, "unset", 6) == 0)
		return (builtin_unset(cmd, shell));
	if (ft_strncmp(name, "env", 4) == 0)
		return (builtin_env(cmd, shell));
	if (ft_strncmp(name, "exit", 5) == 0)
		return (builtin_exit(cmd, shell));
	return (1);
}

void	exec_external(t_shell *shell, t_cmd *cmd)
{
	char		*path;
	struct stat	sb;

	path = resolve_path(cmd->args[0], shell->env);
	if (!path)
	{
		print_cmd_error(cmd->args[0], "command not found");
		exit(127);
	}
	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		print_cmd_error(cmd->args[0], "is a directory");
		free(path);
		exit(126);
	}
	execve(path, cmd->args, shell->env);
	perror(cmd->args[0]);
	free(path);
	exit(126);
}
