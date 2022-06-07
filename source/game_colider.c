/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_colider.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/01 07:57:52 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collide_with(t_gameobject *a, t_gameobject *e, int x, int y)
{
	int	_x;
	int	_y;

	_x = a->x;
	_y = a->y;
	a->x = x;
	a->y = y;
	if (a && e)
	{
		if (e->collidable && e->live && e->active
			&& x - a->bound.x + a->bound.w > e->x - e->bound.x
			&& y - a->bound.y + a->bound.h > e->y - e->bound.y
			&& x - a->bound.x < e->x - e->bound.x + e->bound.w
			&& y - a->bound.y < e->y - e->bound.y + e->bound.h)
		{
			a->x = _x;
			a->y = _y;
			return (1);
		}
	}
	a->x = _x;
	a->y = _y;
	return (0);
}

t_gameobject	*place_meeting(t_game *g, t_gameobject *a, int x, int y)
{
	t_gameobject	*current;

	if (g->gameobjects && g->gameobjects->root)
	{
		current = g->gameobjects->root;
		while (current)
		{
			if (collide_with(a, current, x, y))
				return (current);
			current = current->next;
		}
	}
	return (NULL);
}

int	place_empty(t_game *g, t_gameobject *a, int x, int y)
{
	t_gameobject	*current;

	if (g->gameobjects && g->gameobjects->root)
	{
		current = g->gameobjects->root;
		while (current)
		{
			if (current->live && collide_with(a, current, x, y))
				return (0);
			current = current->next;
		}
	}
	return (1);
}

int	place_free(t_game *g, t_gameobject *a, int x, int y)
{
	t_gameobject	*current;

	if (g->gameobjects && g->gameobjects->root)
	{
		current = g->gameobjects->root;
		while (current)
		{
			if (collide_with(a, current, x, y) && current->type == GAME_SOLID)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

t_gameobject	*colide_type(t_game *g, t_gameobject *a, int type)
{
	t_gameobject	*current;

	if (g->gameobjects && g->gameobjects->root)
	{
		current = g->gameobjects->root;
		while (current)
		{
			if (collide_with(a, current, a->x, a->y) && current->type == type)
				return (current);
			current = current->next;
		}
	}
	return (NULL);
}
