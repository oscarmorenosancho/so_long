/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_game_chars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:57:39 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 18:49:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_draw_element(t_game *game, int *pos, int el)
{
	t_graphics	*gr_ctx;

	gr_ctx = game->gr_ctx;
	mlx_put_image_to_window(gr_ctx->inst, gr_ctx->wnd, \
		gr_ctx->gos[el].seqs[0].frms[0].ref, \
		pos[0] * game->block_size[0], pos[1] * game->block_size[1]);
}

static void	ft_draw_collectable(unsigned int i, void *content, void *arg)
{
	t_game	*game;

	game = arg;
	if (i >= 0)
		ft_draw_element(game, (int *)content, GO_COLLECT);
}

static void	ft_draw_enemy(unsigned int i, void *content, void *arg)
{
	t_game	*game;

	game = arg;
	if (i >= 0)
		ft_draw_element(game, (int *)content, GO_ENEMY);
}

int	ft_draw_game_chars(t_game *game)
{
	if (! game)
		return (0);
	ft_draw_element(game, game->exit_pos, GO_EXIT);
	ft_lstreduce(game->collectables, &ft_draw_collectable, game);
	ft_lstreduce(game->enemies, &ft_draw_enemy, game);
	ft_draw_element(game, game->pos, GO_PLAYER);
	return (1);
}
