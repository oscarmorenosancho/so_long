/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/06 15:58:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_init_img_null(t_graphics *gr_ctx)
{
	int		i;

	i = 0;
	while (i < MAX_GO)
		gr_ob_set_img_ref(gr_ctx->gos[i++], 0, 0, NULL);
}

int	ft_load_images(t_graphics *gr_ctx)
{
	char	*filenames[MAX_GO];
	int		i;
	int		*size;
	void	*ref;

	ft_init_img_null(gr_ctx);
	ft_init_filenames(filenames);
	i = 0;
	while (i < MAX_GO)
	{
		size = gr_ob_get_img_size(gr_ctx->gos[i], 0, 0);
		ref = mlx_xpm_file_to_image(gr_ctx->inst, \
			filenames[i], &size[0], &size[1]);
		gr_ob_set_img_ref(gr_ctx->gos[i], 0, 0, ref);
		if (! ref)
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
	void	*ref;

	i = 0;
	while (i < MAX_GO)
	{
		ref = gr_ob_get_img_ref(gr_ctx->gos[i], 0, 0);
		if (ref)
		{
			mlx_destroy_image (gr_ctx->inst, ref);
			gr_ob_set_img_ref (gr_ctx->gos[i], 0, 0, NULL);
		}
		i++;
	}
	return (1);
}
