/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_trail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:05:36 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 11:44:34 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_stats(t_game_stats *game_stats)
{
	game_stats->players = 0;
	game_stats->exits = 0;
	game_stats->collectables = 0;
	game_stats->enemies = 0;
	game_stats->invalids = 0;
}

int	ft_check_trail(t_game *game)
{
	t_trail_data	td;
	int				res;

	res = 1;
	ft_init_stats(&td.stats);
	if (! game || ! game->t || ! game->t->mat)
		return (1);
	td.t = table_dup(game->t);
	if (! td.t)
		return (0);
	ft_extract_game_chars(game);
	res = ft_push_trail_pos(&td, game->pos);
	if (res)
		res = ft_check_stack(&td);
	if (res)
	{
		res = (td.stats.players == 1 && td.stats.exits == 1);
		res = (res && td.stats.collectables == game->stats.collectables);
	}
	ft_lstclear(&td.stack, &free);
	table_dispose(&td.t);
	if (! res)
		ft_log_error("There is no path to exit the map\n");
	return (res);
}
