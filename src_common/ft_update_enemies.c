/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:11:19 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/20 22:29:40 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	ft_change_pos_when_allow(t_game *game, int *pos, int x, int y)
{
	int		cur[2];
	int		displ[2];
	int		ret;
	t_list	*enemy;
	t_list	*col;

	ft_set_pos(displ, x, y);
	ft_copy_pos(cur, pos);
	ft_add_pos(cur, displ);
	enemy = ft_findfirst_with_pos(game->enemies, cur);
	col = ft_findfirst_with_pos(game->collectables, cur);
	ret = (! enemy && ! col);
	if (ret)
	{
		ret = ! ft_check_pos(game, cur, GO_WALL);
		if (ret)
			ft_add_pos(pos, displ);
	}
	return (ret);
}

static void	ft_update_enemy(unsigned int i, void *item, void *arg)
{
	int		*pos;
	t_game	*game;

	(void)i;
	if (! arg || ! item)
		return ;
	game = arg;
	pos = item;
	if (pos[0] > game->pos[0] && ft_change_pos_when_allow(game, pos, -1, 0))
		return ;
	if (pos[0] < game->pos[0] && ft_change_pos_when_allow(game, pos, 1, 0))
		return ;
	if (pos[1] > game->pos[1] && ft_change_pos_when_allow(game, pos, 0, -1))
		return ;
	if (pos[1] < game->pos[1] && ft_change_pos_when_allow(game, pos, 0, 1))
		return ;
}

void	ft_update_enemies(t_game *game)
{
	if (game->frame % ENEMY_DELAY == 0)
		ft_lstreduce(game->enemies, &ft_update_enemy, game);
}
