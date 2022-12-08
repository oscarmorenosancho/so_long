/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:34:06 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/08 12:58:17 by omoreno-         ###   ########.fr       */
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

static	char	*ft_movements_to_str(int movements)
{
	char	*buf1;
	char	*buf2;
	char	*str;

	buf1 = ft_strdup("Movements: ");
	buf2 = ft_itoa(movements);
	str = ft_str_merge(&buf1, &buf2);
	return (str);
}

static void	ft_draw_movements(t_game *game)
{
	t_graphics	*gr_ctx;
	void		*inst;
	void		*wnd;
	char		*str;
	int			pos[2];

	gr_ctx = game->gr_ctx;
	inst = gr_ctx->inst;
	wnd = gr_ctx->wnd;
	pos[0] = game->block_size[0] / 2;
	pos[1] = game->block_size[1] / 2 + 4;
	str = ft_movements_to_str(game->movements);
	mlx_string_put(inst, wnd, pos[0] + 2, pos[1] + 2, 0x00000000, str);
	mlx_string_put(inst, wnd, pos[0], pos[1], 0x00FFFFFF, str);
	free_x((void **)&str);
}

int	ft_draw(t_game *game)
{
	t_graphics	*gr_ctx;
	t_list		*enemy;
	int			same_pos[0];

	if (! game || game->exit_cmd)
		return (0);
	gr_ctx = game->gr_ctx;
	mlx_clear_window(gr_ctx->inst, gr_ctx->wnd);
	ft_draw_table(game);
	ft_draw_game_chars(game);
	if (game->movs_on_gr)
		ft_draw_movements(game);
	ft_update_enemies(game);
	ft_set_pos(same_pos, 0, 0);
	enemy = ft_check_collision(game, same_pos, GO_ENEMY);
	if (enemy)
	{
		ft_putstr_fd("Collision with enemy\n", 1);
		game->exit_cmd = 1;
	}
	game->frame++;
	return (0);
}
