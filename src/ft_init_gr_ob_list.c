/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_gr_ob_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:14:38 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 15:45:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_gr_ob_list(t_graphics *gr_ctx, t_gr_ob **gr_ob_arr)
{
	int		frms[1];

	frms[0] = 1;
	gr_ob_arr[GO_GROUND] = gr_ob_constructor(gr_ctx, \
		"xpm/mand/ground/s", 1, frms);
	gr_ob_arr[GO_WALL] = gr_ob_constructor(gr_ctx, \
		"xpm/mand/wall/s", 1, frms);
	gr_ob_arr[GO_COLLECT] = gr_ob_constructor(gr_ctx, \
		"xpm/mand/collect/s", 1, frms);
	gr_ob_arr[GO_ENEMY] = gr_ob_constructor(gr_ctx, \
		"xpm/mand/enemy/s", 1, frms);
	gr_ob_arr[GO_EXIT] = gr_ob_constructor(gr_ctx, \
		"xpm/mand/exit/s", 1, frms);
	gr_ob_arr[GO_PLAYER] = gr_ob_constructor(gr_ctx, \
		"xpm/mand/player/s", 1, frms);
}
