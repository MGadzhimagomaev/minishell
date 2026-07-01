/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:10:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/20 09:45:22 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_clean(t_shell *shell, int code)
{
	free_strarr_n(shell->env);
	clear_history();
	exit(code);
}

int	builtin_exit(t_cmd *cmd, t_shell *shell)
{
	int	code;

	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (!cmd->args[1])
		exit_clean(shell, shell->exit_status);
	if (!is_numeric(cmd->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmd->args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_clean(shell, 255);
	}
	if (cmd->args[2])
		return (ft_putstr_fd("minishell: exit: too many arguments\n",
				STDERR_FILENO), 1);
	code = ft_atoi(cmd->args[1]) & 0xFF;
	free_strarr_n(shell->env);
	clear_history();
	exit(code);
}
