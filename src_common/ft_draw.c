/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:34:06 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/06 14:23:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_draw_table(t_game *game)
{
	t_graphics	*gr_ctx;
	int			i;
	int			j;
	int			el;

	gr_ctx = game->gr_ctx;
	i = 0;
	while (i < game->t->size[0])
	{
		j = 0;
		while (j < game->t->size[1])
		{
			el = game->t->mat[j][i];
			mlx_put_image_to_window(gr_ctx->inst, gr_ctx->wnd, \
				gr_ob_get_img_ref(gr_ctx->gos[el], 0, 0), \
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
	game->frame++;
	return (0);
}
