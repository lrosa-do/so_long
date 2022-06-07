/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/01 15:57:00 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_destroy_bitmap(t_game *g, t_bitmap *bitmap)
{
	if (!bitmap)
		return ;
	if (bitmap->buffer)
		mlx_destroy_image(g->mlx, bitmap->buffer);
	free(bitmap);
	bitmap = NULL;
}

void	mlx_draw_bitmap(t_game *g, t_bitmap *gr, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	if (!g || !gr)
		return ;
	j = 0;
	while (j < gr->height)
	{
		i = 0;
		while (i < gr->width)
		{
			color = mlx_get_pixel(gr, i, j);
			if (color != mlx_get_color(255, 0, 0, 0))
				mlx_draw_pixel(g->screen, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

t_rect	c_rect(int x, int y, int w, int h)
{
	t_rect	r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return (r);
}

t_point	c_point(int x, int y)
{
	t_point	c;

	c.x = x;
	c.y = y;
	return (c);
}

t_color	c_color(int r, int g, int b, int a)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}
