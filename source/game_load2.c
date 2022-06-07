/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/29 16:59:09 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images2(t_game *g)
{
	glib_add(g, "assets/images/tile.xpm", 0);
	glib_add(g, "assets/images/rock.xpm", 1);
	glib_add(g, "assets/images/rock2.xpm", 2);
	glib_add(g, "assets/images/exit.xpm", 20);
	glib_add(g, "assets/images/start.xpm", 21);
	glib_add(g, "assets/images/gem/gem_0.xpm", 200);
	glib_add(g, "assets/images/gem/gem_1.xpm", 201);
	glib_add(g, "assets/images/gem/gem_2.xpm", 202);
	glib_add(g, "assets/images/gem/gem_3.xpm", 203);
	glib_add(g, "assets/images/gem/gem_4.xpm", 204);
	glib_add(g, "assets/images/bullet.xpm", GAME_PLAYER_BULLET);
	glib_add(g, "assets/images/bullet-enemy.xpm", GAME_ENEMY_BULLET);
	glib_add(g, "assets/images/tank/tank_end.xpm", GAME_ENEMY - 1);
	glib_add(g, "assets/images/tank/tank.xpm", GAME_ENEMY);
	glib_add(g, "assets/images/tank/cano_0.xpm", 300);
	glib_add(g, "assets/images/tank/cano_1.xpm", 301);
	glib_add(g, "assets/images/tank/cano_2.xpm", 302);
	glib_add(g, "assets/images/tank/cano_3.xpm", 303);
	glib_add(g, "assets/images/tank/cano_4.xpm", 304);
	glib_add(g, "assets/images/tank/cano_5.xpm", 305);
	glib_add(g, "assets/images/tank/cano_6.xpm", 306);
	glib_add(g, "assets/images/tank/cano_7.xpm", 307);
}

void	load_images(t_game *g)
{
	glib_add(g, "assets/images/player/player_0.xpm", 100);
	glib_add(g, "assets/images/player/player_1.xpm", 101);
	glib_add(g, "assets/images/player/player_2.xpm", 102);
	glib_add(g, "assets/images/player/player_3.xpm", 103);
	glib_add(g, "assets/images/player/player_4.xpm", 104);
	glib_add(g, "assets/images/player/player_5.xpm", 105);
	glib_add(g, "assets/images/player/player_6.xpm", 106);
	glib_add(g, "assets/images/player/player_7.xpm", 107);
	glib_add(g, "assets/images/explode/explode_0.xpm", GAME_EXPLOSION);
	glib_add(g, "assets/images/explode/explode_1.xpm", 451);
	glib_add(g, "assets/images/explode/explode_2.xpm", 452);
	glib_add(g, "assets/images/explode/explode_3.xpm", 453);
	glib_add(g, "assets/images/explode/explode_4.xpm", 454);
	glib_add(g, "assets/images/explode/explode_5.xpm", 455);
	glib_add(g, "assets/images/explode/explode_6.xpm", 456);
	glib_add(g, "assets/images/explode/explode_7.xpm", 457);
	glib_add(g, "assets/images/explode/explode_8.xpm", 458);
	glib_add(g, "assets/images/explode/explode_9.xpm", 459);
	glib_add(g, "assets/images/explode/explode_10.xpm", 460);
	glib_add(g, "assets/images/explode/explode_11.xpm", 461);
	glib_add(g, "assets/images/explode/explode_12.xpm", 462);
	glib_add(g, "assets/images/explode/explode_13.xpm", 463);
	load_images2(g);
}
