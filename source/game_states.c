/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/30 20:16:26 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_on_game(t_game *game)
{
	draw_tiles_onscreen(game);
	game_objects_update(game);
	game_emitter_update(game);
	game_print_data(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->buffer, 0, 0);
}

void	game_on_game_over(t_game *game)
{
	int	w;
	int	h;

	w = (game->width / 2) - (8 * 12);
	h = (game->height / 2);
	draw_rect(game->screen, c_rect(0, 0, game->width, game->height), CBLACK);
	print_text(game, "GAME OVER", w, h - 20);
	print_text(game, "YOU LOSE", w + 12, h + 20);
	print_text(game, "PRESS ESQ KEY TO EXIT", w, game->height - 26);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->buffer, 0, 0);
	if (game->last_key == KEY_ESC)
		game->end_game = 1;
}

void	game_on_game_win(t_game *game)
{
	int	w;
	int	h;

	w = (game->width / 2) - (8 * 12);
	h = (game->height / 2);
	draw_rect(game->screen, c_rect(0, 0, game->width, game->height), CBLACK);
	print_text(game, "GAME OVER", w, h - 20);
	print_text(game, "YOU WIN", w + 12, h + 20);
	print_text(game, "PRESS ESQ KEY TO EXIT", w, game->height - 26);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->buffer, 0, 0);
	if (game->last_key == KEY_ESC)
		game->end_game = 1;
}

void	game_mainloop(t_game *game)
{
	if (game->game_state == 0)
		game_on_game(game);
	if (game->game_state == 1)
		game_on_game_over(game);
	if (game->game_state == 2)
		game_on_game_win(game);
}
