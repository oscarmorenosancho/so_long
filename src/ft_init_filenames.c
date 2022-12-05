/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_filenames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:54:00 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 14:54:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_filenames(char **filenames)
{
	filenames[GO_GROUND] = "xpm/mand/ground/s00/f00.xpm";
	filenames[GO_WALL] = "xpm/mand/wall/s00/f00.xpm";
	filenames[GO_EXIT] = "xpm/mand/exit/s00/f00.xpm";
	filenames[GO_PLAYER] = "xpm/mand/player/s00/f00.xpm";
	filenames[GO_COLLECT] = "xpm/mand/collect/s00/f00.xpm";
	filenames[GO_ENEMY] = "xpm/mand/enemy/s00/f00.xpm";
	filenames[GO_BLOCK1] = "xpm/mand/block1/s00/f00.xpm";
	filenames[GO_BLOCK2] = "xpm/mand/block2/s00/f00.xpm";
}
