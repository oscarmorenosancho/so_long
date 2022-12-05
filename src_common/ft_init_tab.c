/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:11:29 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 10:57:53 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <math.h>

static int	ft_rand(int min_num, int max_num)
{
	int	result;
	int	low_num;
	int	hi_num;

	result = 0;
	low_num = 0;
	hi_num = 0;
	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1;
	}
	else
	{
		low_num = max_num + 1;
		hi_num = min_num;
	}
	result = (rand() % (hi_num - low_num)) + low_num;
	return (result);
}

static void	ft_set_rand(t_game *game, int el, int *pos_out)
{
	int	pos[2];
	int	done;

	done = 0;
	while (! done)
	{
		pos[0] = ft_rand(0, game->t->size[0] - 1);
		pos[1] = ft_rand(0, game->t->size[1] - 1);
		done = (game->t->mat[pos[1]][pos[0]] == 0);
		if (done)
			game->t->mat[pos[1]][pos[0]] = el;
	}
	if (pos_out)
	{
		pos_out [0] = pos[0];
		pos_out [1] = pos[1];
	}
}

static void	ft_set_n_rand(t_game *game, int n, int el)
{
	int	i;

	i = 0;
	while (i++ < n)
		ft_set_rand(game, el, 0);
}

int	ft_init_tab(t_game *game)
{
	int			i;
	int			j;
	int			n;

	if (! game)
		return (0);
	n = game->t->size[0] * game->t->size[1] / 40;
	i = 0;
	while (i < game->t->size[0])
	{
		j = 0;
		while (j < game->t->size[1])
		{
			game->t->mat[j][i] = GO_GROUND;
			j++;
		}
		i++;
	}
	ft_set_rand(game, GO_EXIT, game->exit_pos);
	ft_set_rand(game, GO_PLAYER, game->pos);
	ft_set_n_rand(game, n * 5, GO_WALL);
	ft_set_n_rand(game, n, GO_COLLECT);
	ft_set_n_rand(game, n, GO_ENEMY);
	game->t->mat[game->pos[1]][game->pos[0]] = GO_GROUND;
	return (0);
}
