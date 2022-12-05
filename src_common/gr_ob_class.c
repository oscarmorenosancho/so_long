/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_ob_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:45:10 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 12:57:33 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_gr_ob	*gr_ob_constructor(char **config)
{
	t_gr_ob	*go;

	go = malloc(sizeof(t_gr_ob));
	if (! go)
		return (go);
	return (go);
}

int	dispose_gr_ob(t_gr_ob **go)
{
	t_gr_ob	*lgo;

	if (! go)
		return (0);
	lgo = *go;
	free_x(go);
	return (1);
}