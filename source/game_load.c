/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 18:52:59 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_solid(t_game *g)
{
	int				x;
	int				y;
	t_gameobject	*obj;

	y = 0;
	while (g->mapa->map[y])
	{
		x = 0;
		while (g->mapa->map[y][x])
		{
			if (g->mapa->map[y][x] == '1')
			{
				obj = create_gameobject(g, x * TILE_WIDTH, y * TILE_HEIGHT, \
					irandom(1, 2));
				obj->type = GAME_SOLID;
			}
			else if (g->mapa->map[y][x] == 'X')
				create_enemy(g, x * TILE_WIDTH, y * TILE_HEIGHT);
			x++;
		}
		y++;
	}
}

void	process_back(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->mapa->map[y])
	{
		x = 0;
		while (g->mapa->map[y][x])
		{
			if (g->mapa->map[y][x] == 'C')
				create_collect(g, x * TILE_WIDTH + 8, y * TILE_HEIGHT + 8, 200);
			else if (g->mapa->map[y][x] == 'E')
				g->exit = create_gameobject(g, x * TILE_WIDTH, \
				y * TILE_HEIGHT, 20);
			x++;
		}
		y++;
	}
}

void	process_player(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->mapa->map[y])
	{
		x = 0;
		while (g->mapa->map[y][x])
		{
			if (g->mapa->map[y][x] == 'P')
			{
				create_gameobject(g, x * TILE_WIDTH, y * TILE_HEIGHT, 21);
				g->player = create_player(g, x * TILE_WIDTH, \
				y * TILE_HEIGHT, 100);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	game_load(t_game *g)
{
	if (!g)
		return ;
	g->game_state = 0;
	init_timer(g);
	load_images(g);
	g->font.image = mlx_load_bitmap(g->mlx, "assets/images/font2.xpm");
	init_font(g);
	process_player(g);
	process_back(g);
	process_solid(g);
	game_objects_update(g);
}
