/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 18:51:00 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	draw_alpha_sprite(t_game *g, int id, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;
	t_graph			*gr;

	if (!g)
		return ;
	gr = glib_get_graph(g->graphics, id);
	if (!gr || !gr->image)
		return ;
	j = 0;
	while (j < gr->height)
	{
		i = 0;
		while (i < gr->width)
		{
			color = mlx_get_pixel(gr->image, i, j);
			if (color != mlx_get_color(255, 0, 0, 0))
				mlx_draw_pixel(g->screen, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_sprite(t_game *game, int id, int x, int y)
{
	t_graph	*gr;

	if (game->graphics)
	{
		gr = glib_get_graph(game->graphics, id);
		if (gr && gr->image)
		{
			mlx_put_image_to_window(
				game->mlx, game->win, gr->image->buffer, x + game->width, y);
		}
	}
}

void	put_pixel(t_bitmap *g, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (!g)
		return ;
	if ((x < 0 || y < 0) || (x > g->width || y > g->height))
		return ;
	i = g->bpp - 8;
	pixel = g->addr + (y * g->line_len + x * (g->bpp / 8));
	while (i >= 0)
	{
		if (g->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (g->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	clear_bitmap(t_bitmap *g, int color)
{
	int	i;
	int	j;

	if (!g || !g->buffer)
		return ;
	i = 0;
	while (i < g->width)
	{
		j = 0;
		while (j < g->height)
			put_pixel(g, j++, i, color);
		++i;
	}
}

void	draw_rect(t_bitmap *g, t_rect r, int color)
{
	int	i;
	int	j;

	if (!g)
		return ;
	i = r.y;
	while (i < r.y + r.h)
	{
		j = r.x;
		while (j < r.x + r.w)
			mlx_draw_pixel(g, j++, i, color);
		++i;
	}
}
