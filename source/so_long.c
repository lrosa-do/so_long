/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:41:13 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/07 09:43:21 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_game(t_game *game)
{
	game->end_game = 0;
	game->width = game->mapa->width;
	game->colected = 0;
	game->p.x = 0;
	game->p.y = 0;
	game->shake = 0;
	game->height = game->mapa->height + game->off_set;
}

t_game	*create_game(char *mapa, int off_set)
{
	t_game	*game;

	game = (t_game *)ft_malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mapa = (t_map *)ft_malloc(sizeof(t_map));
	if (!game->mapa)
		return (NULL);
	game->mapa->colect = 0;
	game->mapa->player = 0;
	game->mapa->exit = 0;
	game->mapa->map = read_map(mapa);
	if (!check_map(game->mapa))
	{
		destroy_game(game);
		return (NULL);
	}
	game->off_set = off_set;
	setup_game(game);
	if (!create_libx(game))
	{
		destroy_game(game);
		return (NULL);
	}
	return (game);
}

int	main(void)
{
	t_game	*game;

	game = create_game("maps/map3.ber", 22);
	if (!game)
	{
		destroy_game(game);
		return (1);
	}
	return (0);
}
/*
int	main(int argc, char **args)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\n Please type the map to be load. \n");
		return (1);
	}
	if (ft_file_exists(args[1]) && (ft_isfile_extension(args[1], ".ber")))
	{
		game = create_game(args[1], 22);
		if (!game)
			return (1);
		destroy_game(game);
	}
	else
		ft_printf("Error\n File %s dont exists or is not valid .\n", args[1]);
	return (0);
}

*/