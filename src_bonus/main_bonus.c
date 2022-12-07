/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 16:32:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char const *argv[])
{
	t_game	*game;
	int		block_size[2];
	int		allow_enemies;

	block_size[0] = BLOCK_WIDTH;
	block_size[1] = BLOCK_HEIGHT;
	allow_enemies = 1;
	game = game_constructor(ft_take_argument(argc, argv), \
		block_size, allow_enemies);
	if (game)
		mlx_loop(game->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	game_dispose(&game);
	return (0);
}