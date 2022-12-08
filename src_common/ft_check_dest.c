/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:06:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/08 11:29:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_check_pos(t_game *game, int *pos, int el)
{
	if (! game)
		return (0);
	return (game->t->mat[pos[1]][pos[0]] == el);
}

int	ft_check_dest(t_game *game, int *displ, int el)
{
	int	dest_pos[2];

	if (! game)
		return (0);
	dest_pos[0] = game->pos[0] + displ[0];
	dest_pos[1] = game->pos[1] + displ[1];
	if (dest_pos[0] < 0 || dest_pos[0] > game->t->size[0] || \
		dest_pos[1] < 0 || dest_pos[1] > game->t->size[1])
		return (0);
	return (game->t->mat[dest_pos[1]][dest_pos[0]] == el);
}
