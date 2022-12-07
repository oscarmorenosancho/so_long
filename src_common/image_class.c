/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:54:12 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 15:05:05 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_image	*image_constructor(t_graphics *gr_ctx, char *filename)
{
	t_image	*img;

	img = ft_calloc(1, sizeof(t_image));
	if (! img)
		return (img);
	img->gr_ctx = gr_ctx;
	img->ref = mlx_xpm_file_to_image(gr_ctx->inst, \
		filename, &img->size[0], &img->size[1]);
	if (! img->ref)
	{
		ft_log_error("Image reference failed to load\n");
		image_dispose(&img);
	}
	return (img);
}

int	image_dispose(t_image **img)
{
	t_image		*limg;
	t_graphics	*gr_ctx;

	if (! img)
		return (0);
	limg = *img;
	if (limg->ref)
	{
		gr_ctx = limg->gr_ctx;
		mlx_destroy_image (gr_ctx->inst, limg->ref);
		limg->ref = NULL;
	}
	free_x((void **) img);
	return (1);
}
