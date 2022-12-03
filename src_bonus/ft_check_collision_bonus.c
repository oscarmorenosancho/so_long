/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:28:27 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 12:03:59 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*ft_check_collision(t_game *game, int *displ, int el)
{
	int		dest_pos[2];
	t_list	*lst;

	lst = NULL;
	if (! game)
		return (0);
	if (el == RI_COLLECT)
		lst = game->collectables;
	else if (el == RI_ENEMY)
		lst = game->enemies;
	dest_pos[0] = game->pos[0] + displ[0];
	dest_pos[1] = game->pos[1] + displ[1];
	if (dest_pos[0] < 0 || dest_pos[0] >= game->t->size[0] || \
		dest_pos[1] < 0 || dest_pos[1] >= game->t->size[1])
		return (0);
	return (ft_findfirst_with_pos(lst, dest_pos));
}
