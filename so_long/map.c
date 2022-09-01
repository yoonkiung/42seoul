/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:43:17 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/11 21:43:18 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	read_map(char *file, t_gameset *gameset)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_printerr("file open error\n");
	line = get_next_line(fd);
	gameset->map_height = 0;
	gameset->map_width = ft_strlen(line) - 1;
	gameset->map_line = line;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = gameset->map_line;
			gameset->map_line = ft_strjoin(temp, line);
			free(temp);
			free(line);
		}
		gameset->map_height++;
	}
	close(fd);
}

void	check_map_compare(char c, char compare)
{
	if (c != compare)
		ft_printerr("map error\n");
}

int	check_object(t_gameset gameset)
{
	int	i;
	int	exit_cnt;
	int	position_cnt;
	int	collectible_cnt;

	i = 0;
	exit_cnt = 0;
	position_cnt = 0;
	collectible_cnt = 0;
	while ((size_t)i < ft_strlen(gameset.map_line))
	{
		if (gameset.map_line[i] == 'P')
			position_cnt++;
		else if (gameset.map_line[i] == 'C')
			collectible_cnt++;
		else if (gameset.map_line[i] == 'E')
			exit_cnt++;
		i++;
	}
	if (exit_cnt == 0 || position_cnt != 1 || collectible_cnt == 0)
		ft_printerr("map element error\n");
	return (collectible_cnt);
}

void	check_map(t_gameset *gameset)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(gameset->map_line))
	{
		if (i < gameset->map_width)
			check_map_compare(gameset->map_line[i], '1');
		else if (i % (gameset->map_width + 1) == 0)
			check_map_compare(gameset->map_line[i], '1');
		else if (i > (int)ft_strlen(gameset->map_line) - gameset->map_width)
			check_map_compare(gameset->map_line[i], '1');
		else if (i % (gameset->map_width + 1) == gameset->map_width)
		{
			check_map_compare(gameset->map_line[i], '\n');
			check_map_compare(gameset->map_line[i - 1], '1');
		}
		i++;
	}
	if (i % (gameset->map_width + 1) != gameset->map_width)
		check_map_compare(gameset->map_line[i], '\n');
	gameset->coll_max = check_object(*gameset);
}
