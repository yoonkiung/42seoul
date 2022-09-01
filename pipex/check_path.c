/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:55:07 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/31 15:55:09 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_only_cmd(char *cmd)
{
	int		i;
	char	*temp;
	char	*add_path;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, cmd, ft_strlen(cmd) + 1);
	while (cmd[i])
	{
		if (ft_isspace(cmd[i]))
		{
			temp[i] = '\0';
			break ;
		}
		i++;
	}
	add_path = ft_strjoin("/", temp);
	free(temp);
	if (!add_path)
		return (NULL);
	return (add_path);
}

char	*vaild_cmd_path(t_info *info, char *cmd)
{
	char	*cmd_path;
	char	*temp;
	int		i;

	temp = path_only_cmd(cmd);
	if (!temp)
		return (NULL);
	i = 0;
	while (info->path[i])
	{
		cmd_path = ft_strjoin(info->path[i++], temp);
		if (!cmd_path)
		{
			free(temp);
			return (NULL);
		}
		if (access(cmd_path, X_OK) != -1)
		{
			free(temp);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free(temp);
	return (NULL);
}

int	check_change_cmd_path(t_info *info)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	info->cmd_arg = (char ***)malloc(sizeof(char **) * 2);
	if (!info->cmd_arg)
		return (0);
	while (info->cmd[i])
	{
		info->cmd_arg[i] = ft_split(info->cmd[i], " ");
		if (!(info->cmd_arg)[i])
			return (0);
		temp = vaild_cmd_path(info, info->cmd[i]);
		if (!temp)
		{
			i++;
			continue ;
		}
		info->cmd[i++] = temp;
	}
	if (!temp)
		return (0);
	return (1);
}
