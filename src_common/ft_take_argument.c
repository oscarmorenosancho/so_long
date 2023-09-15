/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/15 19:12:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_take_argument(int argc, char const *argv[])
{
	int	len;

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
	len = ft_strlen_x(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4))
	{
		ft_log_error("File extension doesn't match with *.ber\n");
		exit (-1);
	}
	return ((char *)argv[1]);	
}
