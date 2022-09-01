/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:53:06 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/29 17:53:07 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_info
{
	char	**filename;
	char	**cmd;
	char	***cmd_arg;
	char	**path;
}				t_info;

char	**parsing_filename(int ac, char **av);

char	**parsing_cmd(int ac, char **av);

char	**parsing_path(char **envp);

int		info_init(t_info *info, int argc, char **argv, char **envp);

char	*vaild_cmd_path(t_info *info, char *cmd);

int		check_change_cmd_path(t_info *info);

int		ft_stdin(char *path);

int		ft_stdout(char *path);

void	set_pipe_exit(int *fildes);

void	set_pipe_entry(int *fildes);

int		pipex(t_info *info, int *fd_arr, char **envp, pid_t *pid);

#endif
