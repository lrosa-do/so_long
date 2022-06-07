/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/07 09:24:00 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	mlx_get_pixel(t_bitmap *img, int x, int y)
{
	if (!img)
		return (0);
	if ((x < 0 || y < 0) || (x > img->width || y > img->height))
		return (0);
	return (*(unsigned int *)(img->addr + \
	(x * img->bpp / 8 + y * img->line_len)));
}

void	mlx_draw_pixel(t_bitmap *img, int x, int y, int color)
{
	char	*target;

	if (!img || !img->addr)
		return ;
	if (x < 0 || y < 0) 
		return ;
	if  (x > img->width - 1 || y > img->height - 1)
		return ;
		
	target = img->addr + (x * img->bpp / 8 + y * img->line_len);
	*(unsigned int *)target = color;
}

unsigned int	mlx_get_color(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_bitmap	*mlx_create_bitmap(void *mlx, int width, int height)
{
	t_bitmap	*bitmap;

	bitmap = (t_bitmap *)ft_malloc(sizeof(t_bitmap));
	if (!bitmap)
		return (NULL);
	bitmap->buffer = mlx_new_image(mlx, width, height);
	bitmap->width = width;
	bitmap->height = height;
	bitmap->addr = mlx_get_data_addr(bitmap->buffer, \
	&bitmap->bpp, &bitmap->line_len, &bitmap->endian);
	return (bitmap);
}

t_bitmap	*mlx_load_bitmap(void *mlx, char *filename)
{
	t_bitmap	*bitmap;

	bitmap = (t_bitmap *)ft_malloc(sizeof(t_bitmap));
	if (!bitmap)
		return (NULL);
	bitmap->buffer = mlx_xpm_file_to_image(mlx, filename, \
		&bitmap->width, &bitmap->height);
	bitmap->addr = mlx_get_data_addr(bitmap->buffer, &bitmap->bpp, \
	&bitmap->line_len, &bitmap->endian);
	return (bitmap);
}
