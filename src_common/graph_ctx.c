/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:35:33 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 12:37:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_create_wnd(t_game *game)
{
	t_graphics	*gr_ctx;

	if (! game || ! game->gr_ctx)
		return (0);
	gr_ctx = game->gr_ctx;
	gr_ctx->wnd = mlx_new_window(gr_ctx->inst, \
		gr_ctx->wnd_size[0], gr_ctx->wnd_size[1], "Game Wnd");
	if (! gr_ctx->wnd)
	{
		game->exit_cmd = 1;
		return (1);
	}
	mlx_hook(gr_ctx->wnd, ON_DESTROY, 0, &ft_close, game);
	mlx_key_hook(gr_ctx->wnd, &ft_key_input, game);
	return (1);
}

int	ft_create_graph_ctx(t_game *game)
{
	t_graphics	*gr_ctx;

	if (! game)
		return (0);
	gr_ctx = ft_calloc(1, sizeof(t_graphics));
	game->gr_ctx = gr_ctx;
	if (! gr_ctx)
	{
		ft_log_error("Malloc failed while constructing graphic context\n");
		return (0);
	}
	gr_ctx->wnd_size[0] = game->t->size[0] * game->block_size[0];
	gr_ctx->wnd_size[1] = game->t->size[1] * game->block_size[0];
	gr_ctx->inst = mlx_init();
	if (! gr_ctx->inst)
		return (0);
	gr_ctx->gos = gr_ob_list_constructor(gr_ctx);
	if (! gr_ctx->gos)
		return (0);
	mlx_loop_hook(game->gr_ctx->inst, &ft_handle_no_event, game);
	return (ft_create_wnd(game));
}

int	ft_dispose_graph_ctx(t_game *game)
{
	if (! game || ! game->gr_ctx)
		return (0);
	if (game->gr_ctx->inst)
	{
		mlx_loop_hook(game->gr_ctx->inst, NULL, NULL);
		if (game->gr_ctx->wnd)
		{
			mlx_key_hook(game->gr_ctx->wnd, NULL, game);
			mlx_hook(game->gr_ctx->wnd, ON_DESTROY, 0, NULL, NULL);
			mlx_destroy_window (game->gr_ctx->inst, game->gr_ctx->wnd);
			game->gr_ctx->wnd = NULL;
		}
		gr_ob_list_dispose(&game->gr_ctx->gos);
	}
	free_x((void **)&game->gr_ctx);
	return (0);
}
