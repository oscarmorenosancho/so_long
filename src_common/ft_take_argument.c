/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 11:17:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_take_argument(int argc, char const *argv[])
{
	if (argc < 2)
	{
		ft_log_error("You must provide a map file as an argument\n");
		exit (-1);
	}
	if (argc > 2)
	{
		ft_log_error("Too many arguments\n");
		exit (-1);
	}
	return ((char *)argv[1]);
}
