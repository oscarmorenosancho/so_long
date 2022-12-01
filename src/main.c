/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/28 10:53:05 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*ft_take_argument(int argc, char const *argv[])
{
	if (argc < 2)
	{
		ft_log_error("You must provide a map file as an argument\n");
		exit (-1);
	}
	if (argc > 2)
	{
		ft_log_error("Too many arguments\n");
		exit (-1);
	}
	return ((char *)argv[1]);
}

int	main(int argc, char const *argv[])
{
	t_game		*game;

	game = game_constructor(ft_take_argument(argc, argv));
	if (game)
		mlx_loop(game->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	game_dispose(&game);
	return (0);
}
