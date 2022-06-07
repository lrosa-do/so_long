/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 18:50:00 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_text(t_game *game, int x, int y, t_rect clip)
{
	unsigned int	color;
	int				i;
	int				j;
	int				px;
	int				py;

	j = clip.y;
	py = 0;
	while (j < (clip.y + clip.h))
	{
		i = clip.x;
		px = 0;
		while (i < (clip.x + clip.w))
		{
			color = mlx_get_pixel(game->font.image, i, j);
			if (color != mlx_get_color(255, 0, 0, 0))
				mlx_draw_pixel(game->screen, x + px, y + py, color);
			i++;
			px++;
		}
		j++;
		py++;
	}
}

void	init_font(t_game *g)
{
	char	*a;

	a = " !\"#$ &´()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	g->font.cols = 12;
	g->font.rows = 8;
	g->font.w = g->font.image->width / 12;
	g->font.h = g->font.image->height / 8;
	g->font.w = g->font.image->width / 12;
	g->font.h = g->font.image->height / 8;
	g->font.alpha = a;
}

int	text_size(t_game *g, const char *text)
{
	return (((int)ft_strlen(text) * g->font.w) + g->font.w);
}

void	print_text(t_game *g, const char *text, int x, int y)
{
	t_rect	clip;
	int		cur_x;
	int		i;
	int		charindex;

	cur_x = x;
	i = 0;
	while (i < (int)ft_strlen(text))
	{
		if (text[i] == ' ')
			cur_x += g->font.w;
		else
		{
			charindex = ft_strpos(g->font.alpha, text[i]) - 2;
			clip = c_rect((charindex % g->font.cols) * g->font.w, \
			(charindex / g->font.cols) * g->font.h, g->font.w, g->font.h);
			draw_text(g, cur_x, y, clip);
			cur_x += g->font.w;
		}
		++i;
	}
}

void	game_print_data(t_game *game)
{	
	if (game->width >= 640)
	{
		draw_rect(
			game->screen, c_rect(0, 0, game->width, game->off_set), CBLACK);
		print_text(game, ft_format_text("MOVES:%d", game->moves_count), 0, -2);
		print_text(game, ft_format_text("POWER:%d", game->player->energia), \
		game->width / 2 - 140, -2);
		print_text(game, ft_format_text("COLECTED:%d/%d", \
		game->colected, game->mapa->colect),
			game->width - text_size(game, ft_format_text(\
			"COLECTED:%d/%d", game->colected, game->mapa->colect)) + 20, -2);
	}
	else
		print_text(game, ft_format_text("M:%d", game->moves_count), 0, -2);
}
