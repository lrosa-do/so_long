/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 13:16:24 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_update2(t_game *game, t_gameobject *b)
{
	if (b->hit)
	{
		draw_rect(game->screen, c_rect(b->x + 2, b->y + 30, 25, 5), CBLACK);
		if (get_time(game) >= b->timers[0] + b->vars[2])
			b->hit = 0;
		if (b->energia > 50)
			draw_rect(game->screen, c_rect(b->x + 2, b->y + 30, \
			b->energia / 5, 5), CGREEN);
		else
		{
			draw_rect(game->screen, c_rect(b->x + 2, b->y + 30, \
			b->energia / 5, 5), CRED);
			b->parts->visible = 1;
		}
	}
	if (b->energia <= 0)
	{
		create_explosion(game, b->x - irandom(-8, 12), b->y - 25);
		b->active = 0;
		b->parts->active = 0;
		b->graph = GAME_ENEMY - 1;
	}
}

static void	enemy_update_ai(t_game *game, t_gameobject *b)
{
	int		dist;

	dist = (int)ft_distance(game->player->x, game->player->y, b->x, b->y);
	if (dist <= (game->width / 2) && (b->vars[7] < 10))
	{
		if (b->vars[5] > 0)
		{
			if ((get_time(game) > b->timers[5] + 800))
			{
				b->timers[5] = get_time(game);
				b->vars[5] -= 1;
				enemy_shot_player(game, b);
			}
		}
	}
	if (b->vars[5] <= 0)
	{
		if ((get_time(game) > b->timers[5] + 2500))
		{
				b->timers[5] = get_time(game);
				b->vars[5] = 10;
		}
	}
}

void	enemy_update(void *g, t_gameobject *b)
{
	t_game			*game;
	t_gameobject	*obj_colider;

	game = (t_game *)g;
	if (!game || !b)
		return ;
	obj_colider = colide_type(game, b, GAME_PLAYER_BULLET);
	if (obj_colider)
	{
		obj_colider->live = 0;
		b->energia -= 25;
		b->hit = 1;
		b->timers[0] = get_time(g);
	}
	b->vars[7] = (int)abs(abs(b->vars[1]) - abs(angle_offset(b->vars[6])));
	enemy_update2(game, b);
	enemy_update_ai(game, b);
}
