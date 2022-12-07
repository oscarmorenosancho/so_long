/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_gr_ob_list_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:14:38 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 15:45:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_fn(int el)
{
	if (el == GO_WALL)
		return ("xpm/bonus/wall/s");
	if (el == GO_COLLECT)
		return ("xpm/bonus/collect/s");
	if (el == GO_ENEMY)
		return ("xpm/bonus/enemy/s");
	if (el == GO_EXIT)
		return ("xpm/bonus/exit/s");
	if (el == GO_PLAYER)
		return ("xpm/bonus/player/s");
	return ("xpm/bonus/ground/s");
}

void	ft_init_gr_ob_list(t_graphics *gr_ctx, t_gr_ob **gr_ob_arr)
{
	int		frms[10];

	frms[0] = 1;
	gr_ob_arr[GO_GROUND] = gr_ob_constructor(gr_ctx, ft_fn(GO_GROUND), 1, frms);
	gr_ob_arr[GO_WALL] = gr_ob_constructor(gr_ctx, ft_fn(GO_WALL), 1, frms);
	frms[0] = 8;
	gr_ob_arr[GO_COLLECT] = gr_ob_constructor(gr_ctx, ft_fn(GO_COLLECT), \
		1, frms);
	frms[0] = 10;
	gr_ob_arr[GO_ENEMY] = gr_ob_constructor(gr_ctx, ft_fn(GO_ENEMY), 1, frms);
	frms[0] = 1;
	frms[1] = 7;
	gr_ob_arr[GO_EXIT] = gr_ob_constructor(gr_ctx, ft_fn(GO_EXIT), 2, frms);
	frms[0] = 7;
	frms[1] = 7;
	frms[2] = 7;
	frms[3] = 7;
	gr_ob_arr[GO_PLAYER] = gr_ob_constructor(gr_ctx, ft_fn(GO_PLAYER), 4, frms);
}
