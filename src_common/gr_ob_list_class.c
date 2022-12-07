/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_ob_list_class.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:37:40 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 13:56:38 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_gr_ob	**gr_ob_list_constructor(t_graphics *gr_ctx)
{
	t_gr_ob	**gr_ob_arr;
	int		i;

	gr_ob_arr = calloc(MAX_GO, sizeof(t_gr_ob *));
	if (! gr_ob_arr)
		return (gr_ob_arr);
	ft_init_gr_ob_list(gr_ctx, gr_ob_arr);
	i = 0;
	while (i < MAX_GO && gr_ob_arr)
	{
		if (! gr_ob_arr[i])
		{
			ft_log_error("Gr ob not available\n");
			gr_ob_list_dispose(&gr_ob_arr);
		}
		i++;
	}
	if (!gr_ob_arr)
		ft_log_error("Gr ob list creation failed\n");
	return (gr_ob_arr);
}

int	gr_ob_list_dispose(t_gr_ob	***gr_ob_arr)
{
	int	i;

	if (! gr_ob_arr || ! *gr_ob_arr)
		return (0);
	i = 0;
	while (i < MAX_GO)
		gr_ob_dispose(gr_ob_arr[i++]);
	free_x((void **)gr_ob_arr);
	return (1);
}
