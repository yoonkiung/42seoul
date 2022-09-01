/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:24:44 by kiyoon            #+#    #+#             */
/*   Updated: 2022/04/02 15:24:46 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_pipe_exit(int *fildes)
{
	dup2(fildes[0], 0);
	close(fildes[1]);
}

void	set_pipe_entry(int *fildes)
{
	dup2(fildes[1], 1);
	close(fildes[0]);
}

int	pipex(t_info *info, int *fd_arr, char **envp, pid_t *pid)
{
	if (*pid == 0)
	{
		if (info->cmd[1] == NULL)
			return (0);
		set_pipe_exit(fd_arr);
		ft_stdout(info->filename[1]);
		if (execve(info->cmd[1], info->cmd_arg[1], envp) < 0)
			perror(info->cmd[1]);
	}
	*pid = fork();
	if (*pid == 0)
	{
		ft_stdin(info->filename[0]);
		if (info->cmd[0] == NULL)
			return (0);
		set_pipe_entry(fd_arr);
		if (execve(info->cmd[0], info->cmd_arg[0], envp) < 0)
			perror(info->cmd[0]);
	}
	close(fd_arr[0]);
	close(fd_arr[1]);
	// wait(0);
	// wait(0);
	return (0);
}
