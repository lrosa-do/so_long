/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/29 20:21:19 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shake_screen(t_game *game)
{
	int	x;

	x = 0;
	if (game->shake)
	{
		if (get_time(game) > game->shake_timer + 20)
		{
			game->shake = 0;
			game->p = c_point(0, 0);
		}
		while (x < 5)
		{
			game->p.x = (int)(frandom(-2, 2));
			game->p.y = (int)(frandom(-2, 2));
			x++;
		}
	}
}
