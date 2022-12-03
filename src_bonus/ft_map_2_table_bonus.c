/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2_table_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:00:17 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 18:51:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_char_2_table(unsigned int it, char *s, void *arg)
{
	int	*row;

	if (! s || ! arg)
		return ;
	row = (int *)arg;
	if (*s == '0')
		row[it] = GO_GROUND;
	else if (*s == '1')
		row[it] = GO_WALL;
	else if (*s == 'P')
		row[it] = GO_PLAYER;
	else if (*s == 'E')
		row[it] = GO_EXIT;
	else if (*s == 'C')
		row[it] = GO_COLLECT;
	else if (*s == 'S')
		row[it] = GO_ENEMY;
}

static void	ft_line_2_table(unsigned int it, void *content, void *arg)
{
	int		**tab;
	char	*line;

	if (! arg || ! content)
		return ;
	tab = (int **)arg;
	line = (char *)content;
	if (! tab[it])
		return ;
	ft_strreduce(line, &ft_char_2_table, tab[it]);
}

int	ft_map_2_table(t_game *game)
{
	if (! game)
		return (0);
	ft_lstreduce(game->list, &ft_line_2_table, game->t->mat);
	ft_lstclear(&game->list, &free);
	return (1);
}
