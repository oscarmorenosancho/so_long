/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 11:26:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char const *argv[])
{
	t_game	*game;
	int		block_size[2];

	block_size[0] = BLOCK_WIDTH;
	block_size[1] = BLOCK_HEIGHT;
	game = game_constructor(ft_take_argument(argc, argv), block_size);
	if (game)
		mlx_loop(game->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	game_dispose(&game);
	return (0);
}