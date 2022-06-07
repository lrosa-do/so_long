/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/30 20:37:10 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

static void	player_collide_bullet(t_game *game, t_gameobject	*player)
{
	t_gameobject	*obj_colider;

	obj_colider = colide_type(game, player, GAME_ENEMY_BULLET);
	if (obj_colider)
	{
		obj_colider->live = 0;
		player->energia -= 5;
		create_explosion(game, player->x, player->y - 16);
	}
}

static void	player_update(void *g, t_gameobject	*player)
{
	t_game			*game;

	game = (t_game *)g;
	if (!player || !game)
		return ;
	if (player->energia < 5)
	{
		player->hit = 1;
		create_explosion(game, player->x - 5, player->y - 16);
		create_explosion(game, player->x, player->y - 16);
	}
	if (player->hit)
	{
		if ((get_time(game) > player->timers[1] + 600))
		{
			game->game_state = 1;
			player->hit = 0;
		}
		return ;
	}
	player_update_ex(player, game);
	player_collide_bullet(game, player);
}

t_gameobject	*create_player(t_game *g, int x, int y, int graph)
{
	t_gameobject	*player;

	player = create_gameobject_last(g, x, y, graph);
	if (!player)
		return (NULL);
	g->moves_count = 0;
	player->parts = create_smoke_emitter(g, x, y, 1);
	player->parts->visible = 0;
	player->vars[0] = 4;
	player->vars[1] = 100;
	player->timers[0] = get_time(g);
	player->timers[1] = get_time(g);
	player->type = GAME_PLAYER;
	player->collidable = 1;
	player->bound = c_rect(1, 1, 30, 30);
	player->onupdate = &player_update;
	return (player);
}
