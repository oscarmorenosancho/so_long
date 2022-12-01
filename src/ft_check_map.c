/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:23:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/28 17:34:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_equals(void *s, void *arg)
{
	if (! s || ! arg)
		return (0);
	return ((size_t)(*(int *)arg) == ft_linelen(s));
}

static int	ft_start_n_end_with(void *s, void *arg)
{
	char	wall;
	char	*line;

	if (! s || ! arg)
		return (0);
	wall = *(char *)arg;
	line = (char *)s;
	return (line[0] == wall && line[ft_linelen(s) - 1] == wall);
}

static int	ft_char_eq(char a, char b)
{
	return (a == b);
}

static int	ft_check_stats(t_game *game)
{
	if (game->stats.players < 1)
		return (ft_log_error("Player not found on map\n") && 0);
	if (game->stats.players > 1)
		return (ft_log_error("More than one player found on map\n") && 0);
	if (game->stats.exits < 1)
		return (ft_log_error("Exit not found on map\n") && 0);
	if (game->stats.exits > 1)
		return (ft_log_error("More than one exit found on map\n") && 0);
	if (game->stats.collectables < 1)
		return (ft_log_error("No collectable found on map\n") && 0);
	if (game->stats.invalids > 0)
		return (ft_log_error("Invalid chars found on map\n") && 0);
	return (1);
}

int	ft_check_map(t_game *game)
{
	int		startnendwall;
	char	wall;

	if (! game || !game->list || !game->t)
	{
		ft_log_error("Map is empty\n");
		return (0);
	}
	if (! ft_lstevery(game->list, &ft_equals, &(game->t->size[0])))
	{
		ft_log_error("Map is not squared\n");
		return (0);
	}
	wall = '1';
	startnendwall = ft_lstevery(game->list, &ft_start_n_end_with, &wall);
	if (! startnendwall || \
		! ft_every_in_line(game->list->content, &ft_char_eq, wall) || \
		! ft_every_in_line(ft_lstlast(game->list)->content, &ft_char_eq, wall))
	{
		ft_log_error("Map is not rounded by walls\n");
		return (0);
	}
	ft_count_map_stats(game);
	return (ft_check_stats(game));
}
