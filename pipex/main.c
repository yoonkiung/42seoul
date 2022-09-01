/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:52:38 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/29 17:52:40 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		fd_arr[2];
	pid_t	pid;

	if (!info_init(&info, argc, argv, envp))
		exit(1);
	if (!check_change_cmd_path(&info))
		exit(1);
	if (pipe(fd_arr) < 0)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (!pipex(&info, fd_arr, envp, &pid))
		exit(1);
	return (0);
}
