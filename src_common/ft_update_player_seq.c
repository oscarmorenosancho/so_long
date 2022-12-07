/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_player_seq.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:55:00 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 16:06:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_update_player_seq(int *displ, t_game *game)
{
	if (displ[0] == -1)
		game->player_seq = 0;
	else if (displ[1] == 1)
		game->player_seq = 1;
	else if (displ[0] == 1)
		game->player_seq = 2;
	else if (displ[1] == -1)
		game->player_seq = 3;
}
