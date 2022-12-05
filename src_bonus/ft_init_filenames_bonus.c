/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_filenames_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:54:00 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 16:02:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_filenames(char **filenames)
{
	filenames[GO_GROUND] = "xpm/bonus/ground/s00/f00.xpm";
	filenames[GO_WALL] = "xpm/bonus/wall/s00/f00.xpm";
	filenames[GO_EXIT] = "xpm/bonus/exit/s00/f00.xpm";
	filenames[GO_PLAYER] = "xpm/bonus/player/s00/f00.xpm";
	filenames[GO_COLLECT] = "xpm/bonus/collect/s00/f00.xpm";
	filenames[GO_ENEMY] = "xpm/bonus/enemy/s00/f00.xpm";
	filenames[GO_BLOCK1] = "xpm/bonus/block1/s00/f00.xpm";
	filenames[GO_BLOCK2] = "xpm/bonus/block2/s00/f00.xpm";
}
