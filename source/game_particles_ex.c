/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_particles_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:11:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 15:41:42 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	particle_init(t_particle *particle, int x, int y)
{
		particle->x = x;
		particle->y = y;
		particle->vx = 0;
		particle->vy = 0;
		particle->live = 1;
		particle->active = 1;
}
