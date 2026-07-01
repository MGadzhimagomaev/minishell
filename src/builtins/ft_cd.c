/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 09:30:45 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/19 08:22:17 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_pwd(t_shell *shell, char *old_pwd)
{
	char	cwd[4096];
	char	*new_pwd;

	if (old_pwd)
	{
		if (!env_set(shell->env, "OLDPWD", old_pwd))
			shell->env = env_add(shell->env,
					make_env_entry("OLDPWD", old_pwd));
	}
	if (getcwd(cwd, sizeof(cwd)))
	{
		new_pwd = ft_strdup(cwd);
		if (!env_set(shell->env, "PWD", new_pwd))
			shell->env = env_add(shell->env,
					make_env_entry("PWD", new_pwd));
		free(new_pwd);
	}
	return (0);
}

int	builtin_cd(t_cmd *cmd, t_shell *shell)
{
	char	*target;
	char	old_pwd[4096];
	int		ret;

	if (cmd->args[1] && cmd->args[2])
		return (ft_putstr_fd("minishell: cd: too many arguments\n",
				STDERR_FILENO), 1);
	target = cmd->args[1];
	if (!target)
	{
		target = ft_getenv("HOME", shell->env);
		if (!target)
			return (ft_putstr_fd("minishell: cd: HOME not set\n",
					STDERR_FILENO), 1);
	}
	if (!getcwd(old_pwd, sizeof(old_pwd)))
		old_pwd[0] = '\0';
	ret = chdir(target);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		perror(target);
		return (1);
	}
	return (update_pwd(shell, old_pwd));
}
