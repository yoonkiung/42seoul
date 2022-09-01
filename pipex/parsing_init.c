/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:22:02 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/30 12:22:03 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_filename(int ac, char **av)
{
	char	**filename;

	filename = (char **)malloc(sizeof(char *) * 3);
	if (!filename)
		return (0);
	filename[0] = av[1];
	filename[1] = av[ac - 1];
	return (filename);
}

char	**parsing_cmd(int ac, char **av)
{
	char	**cmd;
	int		i;

	cmd = (char **)malloc(sizeof(char *) * (ac - 2));
	if (!cmd)
		return (NULL);
	i = 0;
	while (i < ac - 3)
	{
		cmd[i] = av[i + 2];
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	**parsing_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ":");
	if (!path)
		return (NULL);
	return (path);
}

int	info_init(t_info *info, int argc, char **argv, char **envp)
{
	if (argc < 3)
		return (0);
	info->filename = parsing_filename(argc, argv);
	if (!info->filename)
		return (0);
	info->cmd = parsing_cmd(argc, argv);
	if (!info->cmd)
	{
		free(info->filename);
		return (0);
	}
	info->path = parsing_path(envp);
	if (!info->path)
	{
		free(info->filename);
		free(info->cmd);
		return (0);
	}
	return (1);
}
