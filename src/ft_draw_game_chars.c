/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_game_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:57:39 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/28 13:33:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_draw_element(t_game *game, int *pos, int el)
{
	t_graphics	*gr_ctx;

	gr_ctx = game->gr_ctx;
	mlx_put_image_to_window(gr_ctx->inst, gr_ctx->wnd, \
		gr_ctx->img[el].ref, \
		pos[0] * BLOCK_WIDTH, pos[1] * BLOCK_HEIGHT);
}

static void	ft_draw_collectable(unsigned int i, void *content, void *arg)
{
	t_game	*game;

	game = arg;
	if (i >= 0)
		ft_draw_element(game, (int *)content, RI_COLLECT);
}

static void	ft_draw_enemy(unsigned int i, void *content, void *arg)
{
	t_game	*game;

	game = arg;
	if (i >= 0)
		ft_draw_element(game, (int *)content, RI_ENEMY);
}

int	ft_draw_game_chars(t_game *game)
{
	if (! game)
		return (0);
	ft_draw_element(game, game->exit_pos, RI_EXIT);
	ft_lstreduce(game->collectables, &ft_draw_collectable, game);
	ft_lstreduce(game->enemies, &ft_draw_enemy, game);
	ft_draw_element(game, game->pos, RI_PLAYER);
	return (1);
}
