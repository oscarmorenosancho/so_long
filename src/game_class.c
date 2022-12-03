/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:41:52 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 11:45:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*game_constructor(char *map_file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game)
	{
		game->exit_cmd = 0;
		game->map_file = map_file;
		game->t = NULL;
		game->gr_ctx = NULL;
		game = ft_init_game(game);
	}
	else
		ft_log_error("Malloc failed while constructing game\n");
	return (game);
}

t_game	*game_dispose(t_game **game)
{
	t_game	*g;

	if (! game || ! *game)
		return (*game);
	g = *game;
	ft_dispose_graph_ctx(g);
	table_dispose(&g->t);
	ft_lstclear(&(g->list), &free);
	ft_lstclear(&(g->collectables), &free);
	ft_lstclear(&(g->enemies), &free);
	free_x((void **)game);
	exit (0);
	return (g);
}

static void	ft_init_game_stats(t_game *game)
{
	game->stats.players = 0;
	game->stats.exits = 0;
	game->stats.collectables = 0;
	game->stats.enemies = 0;
	game->stats.invalids = 0;
}

static void	ft_init_size(t_game *game, int *size)
{
	if (!game->list)
	{
		ft_log_error("Map file has no data\n");
		game_dispose(&game);
	}
	size[1] = ft_lstsize(game->list);
	size[0] = ft_linelen(game->list->content);
	if (size[0] < 1)
	{
		ft_log_error("Map file starts with empty lines\n");
		game_dispose(&game);
	}
}

t_game	*ft_init_game(t_game *game)
{
	int		size[2];

	game->collectables = NULL;
	game->enemies = NULL;
	ft_init_game_stats(game);
	game->list = ft_read_map(game->map_file);
	ft_init_size(game, size);
	if (size[0] * BLOCK_WIDTH >= DISP_WIDTH || \
		size[1] * BLOCK_HEIGHT >= DISP_HEIGHT)
	{
		ft_log_error("Map size exceeds the display resolution\n");
		game_dispose(&game);
	}
	game->t = table_constructor(size);
	if (! game->t || ! ft_check_map(game) \
		|| ! ft_map_2_table(game) || ! ft_check_trail(game))
		return (game_dispose(&game));
	if (! ft_create_graph_ctx(game))
		return (game_dispose(&game));
	return (game);
}
