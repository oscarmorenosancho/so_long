/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 19:04:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_init_img_null(t_graphics *gr_ctx)
{
	int		i;

	i = 0;
	while (i < MAX_GO)
		gr_ctx->gos[i++].frms[0].ref = NULL;
}

static void	ft_init_filenames(char **filenames)
{
	filenames[GO_GROUND] = "xpm/Ground001.xpm";
	filenames[GO_WALL] = "xpm/Wall001.xpm";
	filenames[GO_EXIT] = "xpm/Exit001.xpm";
	filenames[GO_PLAYER] = "xpm/Man001.xpm";
	filenames[GO_COLLECT] = "xpm/Key001.xpm";
	filenames[GO_ENEMY] = "xpm/Snake001.xpm";
	filenames[GO_BLOCK1] = "xpm/Block001.xpm";
	filenames[GO_BLOCK2] = "xpm/Block002.xpm";
}

int	ft_load_images(t_graphics *gr_ctx)
{
	char	*filenames[MAX_GO];
	int		i;

	ft_init_img_null(gr_ctx);
	ft_init_filenames(filenames);
	i = 0;
	while (i < MAX_GO)
	{
		gr_ctx->gos[i].frms[0].ref = mlx_xpm_file_to_image(gr_ctx->inst, \
			filenames[i], &gr_ctx->gos[i].frms[0].size[0], \
			&gr_ctx->gos[i].frms[0].size[1]);
		if (! gr_ctx->gos[i].frms[0].ref)
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
	while (i < MAX_GO)
	{
		if (gr_ctx->gos[i].frms[0].ref)
		{
			mlx_destroy_image (gr_ctx->inst, gr_ctx->gos[i].frms[0].ref);
			gr_ctx->gos[i].frms[0].ref = 0;
		}
		i++;
	}
	return (1);
}
