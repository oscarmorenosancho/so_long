/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:44:35 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/30 15:45:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_handle_no_event(void *data)
{
	static int	counter;
	t_game		*game;

	counter++;
	if (! data)
		return (0);
	game = data;
	if (game->exit_cmd || ! game->gr_ctx->wnd)
		game_dispose(&game);
	else
		ft_draw(game);
	return (0);
}

int	ft_close(void *param)
{
	t_game	*game;

	game = param;
	if (! game)
		return (0);
	game->exit_cmd = 1;
	return (0);
}

int	ft_key_input(int keycode, void *param)
{
	t_game		*game;

	if (! param)
		return (0);
	game = param;
	if (! game)
		return (0);
	if (keycode == KC_ESC || keycode == KC_Q)
	{
		game->exit_cmd = 1;
		return (0);
	}
	ft_update_pos(keycode, game);
	return (ft_draw(game));
}
