/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_map_stats.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:34:34 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 10:55:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_update(unsigned int it, char *s, void *acum)
{
	t_game_stats	*gs;

	(void)it;
	gs = (t_game_stats *)acum;
	if (s)
	{
		if (*s == 'P')
			gs->players++;
		else if (*s == 'E')
			gs->exits++;
		else if (*s == 'C')
			gs->collectables++;
		else if (*s == 'S')
			gs->enemies++;
		else if (*s != '0' && *s != '1' && *s != '\n')
			gs->invalids++;
	}
}

static void	ft_update_map_stats(unsigned int i, void *content, void *arg)
{
	char			*line;

	(void)i;
	line = (char *)content;
	ft_strreduce(line, &ft_update, arg);
}

void	ft_count_map_stats(t_game *game)
{
	ft_lstreduce(game->list, &ft_update_map_stats, &game->stats);
}
