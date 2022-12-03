/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 12:02:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_init_img_null(t_graphics *gr_ctx)
{
	int		i;

	i = 0;
	while (i < MAX_IMG)
		gr_ctx->img[i++].ref = NULL;
}

int	ft_load_images(t_graphics *gr_ctx)
{
	char	*filename[MAX_IMG];
	int		i;

	ft_init_img_null(gr_ctx);
	filename[RI_GROUND] = "xpm/Ground001.xpm";
	filename[RI_WALL] = "xpm/Wall001.xpm";
	filename[RI_EXIT] = "xpm/Exit001.xpm";
	filename[RI_PLAYER] = "xpm/Man001.xpm";
	filename[RI_COLLECT] = "xpm/Key001.xpm";
	filename[RI_ENEMY] = "xpm/Snake001.xpm";
	filename[RI_BLOCK1] = "xpm/Block001.xpm";
	filename[RI_BLOCK2] = "xpm/Block002.xpm";
	i = 0;
	while (i < MAX_IMG)
	{
		gr_ctx->img[i].ref = mlx_xpm_file_to_image(gr_ctx->inst, filename[i], \
			&gr_ctx->img[i].size[0], &gr_ctx->img[i].size[1]);
		if (! gr_ctx->img[i].ref)
		{
			ft_dispose_images(gr_ctx);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_dispose_images(t_graphics *gr_ctx)
{
	int		i;

	i = 0;
	while (i < MAX_IMG)
	{
		if (gr_ctx->img[i].ref)
		{
			mlx_destroy_image (gr_ctx->inst, gr_ctx->img[i].ref);
			gr_ctx->img[i].ref = 0;
		}
		i++;
	}
	return (1);
}
