/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:10:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/20 09:30:14 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

int	export_set(t_shell *shell, char *arg)
{
	char	*eq;
	char	*name;
	char	*value;
	int		ret;

	eq = ft_strchr(arg, '=');
	if (!eq)
	{
		if (!env_exists(arg, shell->env))
			shell->env = env_add(shell->env, make_env_entry(arg, NULL));
		return (0);
	}
	name = ft_substr(arg, 0, eq - arg);
	value = eq + 1;
	ret = env_set(shell->env, name, value);
	if (!ret)
		shell->env = env_add(shell->env, make_env_entry(name, value));
	free(name);
	return (0);
}

static int	export_one(t_shell *shell, char *arg)
{
	char	*name;
	int		valid;

	name = get_env_name(arg);
	valid = valid_identifier(name);
	free(name);
	if (!valid)
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		return (1);
	}
	return (export_set(shell, arg));
}

int	builtin_export(t_cmd *cmd, t_shell *shell)
{
	int	i;
	int	ret;

	if (!cmd->args[1])
	{
		print_export(shell->env);
		return (0);
	}
	ret = 0;
	i = 1;
	while (cmd->args[i])
	{
		if (export_one(shell, cmd->args[i]))
			ret = 1;
		i++;
	}
	return (ret);
}
