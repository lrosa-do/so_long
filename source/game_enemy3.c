/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/29 19:05:14 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	angle_offset(int index)
{
	if (index == 300)
		return (0);
	if (index == 301)
		return (40);
	if (index == 302)
		return (90);
	if (index == 303)
		return (130);
	if (index == 304)
		return (180);
	if (index == 305)
		return (-140);
	if (index == 306)
		return (-90);
	if (index == 307)
		return (-40);
	return (0);
}

void	enemy_shot_player(t_game *game, t_gameobject *b)
{
	int	dir;

	dir = angle_offset(b->vars[6]);
	b->vars[3] = b->x + 15 - cosf(dir * FTPI / 180.0f) * 30;
	b->vars[4] = b->y + 12 - sinf(dir * FTPI / 180.0f) * 30;
	create_enemy_bullet(game, b->vars[3], b->vars[4], b->vars[6]);
}
