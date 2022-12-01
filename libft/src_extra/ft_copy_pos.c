/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:03 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 17:50:54 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

void	ft_copy_pos(int *dst, int *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}

int	*ft_dup_pos(int *src)
{
	int	*dst;

	dst = malloc(2 * sizeof(int));
	if (dst)
		ft_copy_pos(dst, src);
	return (dst);
}
