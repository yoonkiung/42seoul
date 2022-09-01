/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:42:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/11 21:42:50 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	image_put(t_gameset g, t_imgset i)
{
	int	h;
	int	w;

	h = -1;
	while (++h < g.map_height)
	{
		w = -1;
		while (++w < g.map_width)
		{
			if (g.map_line[h * g.map_width + w + h] == '1')
				mlx_put_image_to_window(g.mlx, g.win, i.wall, w * 64, h * 64);
			else if (g.map_line[h * g.map_width + w + h] == 'C')
			{
				mlx_put_image_to_window(g.mlx, g.win, i.tile, w * 64, h * 64);
				mlx_put_image_to_window(g.mlx, g.win, i.coll, w * 64, h * 64);
			}
			else if (g.map_line[h * g.map_width + w + h] == 'P')
				mlx_put_image_to_window(g.mlx, g.win, i.player, w * 64, h * 64);
			else if (g.map_line[h * g.map_width + w + h] == 'E')
				mlx_put_image_to_window(g.mlx, g.win, i.exit, w * 64, h * 64);
			else if (g.map_line[h * g.map_width + w + h] == '0')
				mlx_put_image_to_window(g.mlx, g.win, i.tile, w * 64, h * 64);
		}
	}
}

void	image_init(t_gameset g, t_imgset *i)
{
	int	size;

	i->wall = mlx_xpm_file_to_image(g.mlx, "xpm/wall.xpm", &size, &size);
	i->tile = mlx_xpm_file_to_image(g.mlx, "xpm/tile.xpm", &size, &size);
	i->player = mlx_xpm_file_to_image(g.mlx, "xpm/player.xpm", &size, &size);
	i->coll = mlx_xpm_file_to_image(g.mlx, "xpm/collectible.xpm", &size, &size);
	i->exit = mlx_xpm_file_to_image(g.mlx, "xpm/exit.xpm", &size, &size);
}

void	image_rendering(t_gameset g)
{
	t_imgset	imgset;

	image_init(g, &imgset);
	image_put(g, imgset);
}
