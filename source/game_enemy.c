/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 16:14:57 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

static int	get_xgraph(int index)
{
	int	graph[32];

	graph[0] = 300;
	graph[1] = 301;
	graph[2] = 301;
	graph[3] = 301;
	graph[4] = 302;
	graph[5] = 302;
	graph[6] = 303;
	graph[7] = 303;
	graph[8] = 303;
	graph[9] = 304;
	graph[10] = 304;
	graph[11] = 304;
	graph[12] = 305;
	graph[13] = 305;
	graph[14] = 306;
	graph[15] = 306;
	graph[16] = 306;
	graph[17] = 307;
	graph[18] = 307;
	graph[19] = 307;
	graph[20] = 300;
	graph[21] = 300;
	return (graph[index]);
}

static t_point	get_offset(int index)
{
	if (index == 0)
		return (c_point(7, 3));
	if (index == 1)
		return (c_point(6, 5));
	if (index == 2)
		return (c_point(-5, 6));
	if (index == 3)
		return (c_point(-1, 5));
	if (index == 4)
		return (c_point(-4, -4));
	if (index == 5)
		return (c_point(-2, 2));
	if (index == 6)
		return (c_point(-5, -5));
	if (index == 7)
		return (c_point(7, 0));
	return (c_point(0, 0));
}

static	void	enemy_render2(t_game *game, t_gameobject *b)
{
	int		xgraph;
	int		index;
	int		a;
	t_point	pt;

	a = b->vars[1] % 360;
	if (a < 0)
		a += 360;
	index = (int)(a * 21 / 360);
	xgraph = get_xgraph(index);
	pt = get_offset(xgraph - 300);
	b->vars[1] = (int)ft_angle(game->player, b);
	b->vars[6] = xgraph;
	b->vars[3] = b->x + 15 - cosf(b->vars[1] * FTPI / 180.0f) * 30;
	b->vars[4] = b->y + 12 - sinf(b->vars[1] * FTPI / 180.0f) * 30;
	draw_alpha_sprite(game, xgraph, (b->x - game->p.x) - pt.x, \
	(b->y - game->p.y) - pt.y);
}

static	void	enemy_render(void *g, t_gameobject *b)
{
	t_game	*game;

	game = (t_game *)g;
	if (!game || !b)
		return ;
	enemy_render2(game, b);
}

t_gameobject	*create_enemy(t_game *g, int x, int y)
{
	t_gameobject	*obj;

	obj = create_gameobject(g, x, y, GAME_ENEMY);
	if (!obj)
		return (NULL);
	obj->vars[0] = 0;
	obj->vars[1] = irandom(0, 360);
	obj->vars[2] = 100;
	obj->vars[5] = 10;
	obj->timers[0] = 0;
	obj->timers[1] = 0;
	obj->type = GAME_ENEMY;
	obj->parts = create_smoke_emitter(g, x + 10, y + 30, 1);
	obj->parts->visible = 0;
	obj->bound = c_rect(0, 0, 30, 30);
	obj->onupdate = &enemy_update;
	obj->onrender = &enemy_render;
	return (obj);
}
