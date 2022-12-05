/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 16:28:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_init_img_null(t_graphics *gr_ctx)
{
	int		i;

	i = 0;
	while (i < MAX_GO)
		gr_ctx->gos[i++].seqs[0].frms[0].ref = NULL;
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
		gr_ctx->gos[i].seqs[0].frms[0].ref = \
			mlx_xpm_file_to_image(gr_ctx->inst, \
			filenames[i], &gr_ctx->gos[i].seqs[0].frms[0].size[0], \
			&gr_ctx->gos[i].seqs[0].frms[0].size[1]);
		if (! gr_ctx->gos[i].seqs[0].frms[0].ref)
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
		if (gr_ctx->gos[i].seqs[0].frms[0].ref)
		{
			mlx_destroy_image (gr_ctx->inst, \
				gr_ctx->gos[i].seqs[0].frms[0].ref);
			gr_ctx->gos[i].seqs[0].frms[0].ref = 0;
		}
		i++;
	}
	return (1);
}
