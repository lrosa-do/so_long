/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_objects_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/07 09:28:33 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gameobject	*game_objects_get(t_game *g, int type)
{
	t_gameobject	*current;

	if (g->gameobjects && g->gameobjects->root)
	{
		current = g->gameobjects->root;
		while (current)
		{
			if (current->type == type)
			{
				return (current);
			}
			current = current->next;
		}
	}
	return (NULL);
}

void	game_objects_clean(t_game *g)
{
	t_gameobject	*current;
	t_gameobject	*previous;

	if (!g->gameobjects || !g->gameobjects->root)
		return ;
	current = g->gameobjects->root;
	while (current->live)
	{
		if (current->next == NULL)
			return ;
		else
		{
			previous = current;
			current = current->next;
		}
	}
	if (current == g->gameobjects->root)
		g->gameobjects->root = g->gameobjects->root->next;
	else
		previous->next = current->next;
	free (current);
	if (current->type == GAME_COLLECT)
		g->colected++;
	g->gameobjects->count -= 1;
	current = NULL;
}

int	game_objects_out_screen(t_game *g, t_gameobject *o)
{
	return ((o->x >= 0 && o->y >= 0) \
	&& (o->x <= g->width && o->y <= g->height));
}

void	draw_tiles_onscreen(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width  / TILE_WIDTH)
	{
		y = 0;
		while (y < game->height   / TILE_HEIGHT)
		{
			draw_alpha_sprite(game, 0, x * TILE_WIDTH, y * TILE_HEIGHT + \
			game->off_set);
			y++;
		}
		x++;
	}
}
