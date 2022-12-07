/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:34:06 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 17:46:18 by omoreno-         ###   ########.fr       */
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

	gr_ctx = game->gr_ctx;
	inst = gr_ctx->inst;
	wnd = gr_ctx->wnd;
	str = ft_movements_to_str(game->movements);
	mlx_string_put(inst, wnd, 22, 42, 0x00000000, str);
	mlx_string_put(inst, wnd, 20, 40, 0x00FFFFFF, str);
	free_x((void **)&str);
}

int	ft_draw(t_game *game)
{
	t_graphics	*gr_ctx;

	if (! game || game->exit_cmd)
		return (0);
	gr_ctx = game->gr_ctx;
	mlx_clear_window(gr_ctx->inst, gr_ctx->wnd);
	ft_draw_table(game);
	ft_draw_game_chars(game);
	if (game->movs_on_gr)
		ft_draw_movements(game);
	game->frame++;
	return (0);
}
