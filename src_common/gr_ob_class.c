/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_ob_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:45:10 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 17:22:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_gr_ob	*gr_ob_constructor(char *name, int seqs, int *frms)
{
	t_gr_ob	*go;
	char	*filenamebase;
	int		s;
	int		*f;

	s = seqs;
	f = frms;
	filenamebase = name;
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
	free_x((void **) go);
	return (1);
}
