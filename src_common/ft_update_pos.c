/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:35:39 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/08 12:36:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_print_movements(int movements)
{
	ft_putstr_fd("Movements: ", 1);
	ft_putnbr_fd(movements, 1);
	ft_putstr_fd("\r", 1);
}

static int	ft_check_exit(t_game *game, int *displ)
{
	int			dest_pos[2];

	if (! game)
		return (0);
	dest_pos[0] = game->pos[0] + displ[0];
	dest_pos[1] = game->pos[1] + displ[1];
	if (dest_pos[0] < 0 || dest_pos[0] >= game->t->size[0] || \
		dest_pos[1] < 0 || dest_pos[1] >= game->t->size[1])
		return (0);
	return (dest_pos[0] == game->exit_pos[0] \
			&& dest_pos[1] == game->exit_pos[1]);
}

static int	ft_check_interactions(t_game *game, int *displ)
{
	t_list	*enemy;
	t_list	*collectable;

	enemy = ft_check_collision(game, displ, GO_ENEMY);
	collectable = ft_check_collision(game, displ, GO_COLLECT);
	if (enemy)
	{
		ft_putstr_fd("Collision with enemy\n", 1);
		game->exit_cmd = 1;
	}
	if (ft_check_exit(game, displ) && ! game->collectables)
	{
		ft_putstr_fd("You ecaped the laberinth\n", 1);
		game->exit_cmd = 1;
	}
	if (collectable)
		ft_lstdeletenode(&game->collectables, collectable);
	if (! game->collectables && game->gr_ctx->gos[GO_EXIT]->count > 1)
		game->exit_seq = 1;
	return (enemy != NULL || ft_check_dest(game, displ, GO_WALL));
}

int	ft_update_pos(int keycode, t_game *game)
{
	int			displ[2];

	if (! game)
		return (0);
	displ[0] = 0;
	displ[1] = 0;
	if (keycode == KC_LEFT || keycode == KC_A)
		displ[0] = -1;
	else if (keycode == KC_RIGHT || keycode == KC_D)
		displ[0] = 1;
	else if (keycode == KC_UP || keycode == KC_W)
		displ[1] = -1;
	else if (keycode == KC_DOWN || keycode == KC_S)
		displ[1] = 1;
	ft_update_player_seq(displ, game);
	if (ft_check_interactions(game, displ))
		return (displ[0] || displ[1]);
	game->pos[0] += displ[0];
	game->pos[1] += displ[1];
	game->movements++;
	if ((displ[0] || displ[1]) && ! game->movs_on_gr)
		ft_print_movements(game->movements);
	return (displ[0] || displ[1]);
}
