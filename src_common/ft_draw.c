/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:34:06 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 12:03:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_draw_table(t_game *game)
{
	t_graphics	*gr_ctx;
	int			i;
	int			j;

	gr_ctx = game->gr_ctx;
	i = 0;
	while (i < game->t->size[0])
	{
		j = 0;
		while (j < game->t->size[1])
		{
			mlx_put_image_to_window(gr_ctx->inst, gr_ctx->wnd, \
				gr_ctx->gos[game->t->mat[j][i]].frms[0].ref, \
				i * game->block_size[0], j * game->block_size[1]);
			j++;
		}
		i++;
	}
}

int	ft_draw(t_game	*game)
{
	t_graphics	*gr_ctx;

	if (! game || game->exit_cmd)
		return (0);
	gr_ctx = game->gr_ctx;
	mlx_clear_window(gr_ctx->inst, gr_ctx->wnd);
	ft_draw_table(game);
	ft_draw_game_chars(game);
	return (0);
}