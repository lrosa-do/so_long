/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/07 09:40:12 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_game(t_game *g)
{
	if (!g)
		return ;
	free_map(g->mapa->map);
	free(g->mapa);
	free(g);
}

int	on_close(t_game *game)
{
	free_glib(game, game->graphics);
	game_objects_destroy(game->gameobjects);
	game_emitter_destroy(game->gamepar);
	mlx_destroy_bitmap(game, game->screen);
	mlx_destroy_bitmap(game, game->font.image);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	destroy_game(game);
	printf("BY! BY! :) \n");
	exit(0);
	return (0);
}

int	on_key_down(int keycode, t_game *game)
{
	if (!game || !game->win)
		return (1);
	if (keycode == KEY_ESC)
	{
		on_close(game);
	}
	game->keys[keycode] = 1;
	game->last_key = keycode;
	return (0);
}

int	on_render(t_game *game)
{
	int	x;

	x = 0;
	if (!game || !game->win || game->end_game)
		on_close(game);
	mlx_clear_window(game->mlx, game->win);
	updade_timer(game);
	shake_screen(game);
	game_mainloop(game);
	while (x < 256)
	{
		game->keys[x] = 0;
		x++;
	}
	game->last_key = -1;
	return (0);
}

int	create_libx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->screen = mlx_create_bitmap(game->mlx, game->width , game->height );
	game->bound = c_rect(0, 0, game->width, game->height);
	game->graphics = init_glib();
	game->gameobjects = game_objects_create();
	game->gamepar = game_emitter_create();
	game_load(game);
	mlx_hook(game->win, 2, 1L << 0, &on_key_down, game);
	mlx_hook(game->win, 17, (1L << 17), &on_close, game);
	mlx_loop_hook(game->mlx, &on_render, game);
	mlx_loop(game->mlx);
	return (1);
}
