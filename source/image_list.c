/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/29 11:57:21 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_glib	*init_glib(void)
{
	t_glib	*lib;

	lib = (t_glib *)ft_malloc(sizeof(t_glib));
	if (!lib)
		return (NULL);
	lib->count = 0;
	lib->root = NULL;
	return (lib);
}

void	free_glib(t_game *game, t_glib *lib)
{
	t_graph	*current;
	t_graph	*next;

	if (!lib)
		return ;
	if (lib->root)
	{
		current = lib->root;
		while (current != NULL)
		{
			next = current->next;
			mlx_destroy_bitmap(game, current->image);
			free(current);
			current = next;
		}
		lib->root = NULL;
	}
	free(lib);
	lib = NULL;
}

int	glib_contain_graph(t_glib *lib, int id)
{
	t_graph	*current;

	if (lib)
	{
		if (lib->root)
		{
			current = lib->root;
			while (current)
			{
				if (current->id == id)
				{
					return (1);
				}
				current = current->next;
			}
		}
	}
	return (0);
}

t_graph	*glib_get_graph(t_glib *lib, int id)
{
	t_graph	*current;

	if (lib)
	{
		if (lib->root)
		{
			current = lib->root;
			while (current)
			{
				if (current->id == id)
				{
					return (current);
				}
				current = current->next;
			}
		}
	}
	return (NULL);
}

/*
add graph to end of the list
*/
void	glib_add(t_game *game, char *filename, int id)
{
	t_graph	*graph;
	t_graph	*current;

	if (game->graphics)
	{
		graph = (t_graph *)ft_malloc(sizeof(t_graph));
		if (!graph)
			return ;
		graph->image = mlx_load_bitmap(game->mlx, filename);
		graph->id = id;
		graph->width = graph->image->width;
		graph->height = graph->image->height;
		graph->next = NULL;
		if (!game->graphics->root)
			game->graphics->root = graph;
		else
		{
			current = game->graphics->root;
			while (current->next != NULL)
				current = current->next;
			current->next = graph;
			current->next->next = NULL;
		}
		game->graphics->count++;
	}
}
