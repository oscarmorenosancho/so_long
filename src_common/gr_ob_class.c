/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_ob_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:45:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/20 16:59:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_gr_ob	*gr_ob_constructor(t_graphics *gr_ctx, \
		char *name, int seqs, int *frms)
{
	t_gr_ob	*go;
	int		i;

	if (seqs < 1)
		return (NULL);
	go = ft_calloc(1, sizeof(t_gr_ob));
	if (! go)
		return (go);
	go->count = seqs;
	go->seqs = ft_calloc(seqs, sizeof(t_fr_seq *));
	if (! go->seqs)
		gr_ob_dispose(&go);
	i = 0;
	while (i < seqs && go)
	{
		go->seqs[i] = fr_seq_constructor(gr_ctx, name, i, frms[i]);
		if (! go->seqs[i])
			gr_ob_dispose(&go);
		i++;
	}
	return (go);
}

int	gr_ob_dispose(t_gr_ob **go)
{
	t_gr_ob	*lgo;
	int		i;

	if (! go)
		return (0);
	lgo = *go;
	if (! lgo)
		return (0);
	i = 0;
	while (i < lgo->count)
	{
		fr_seq_dispose(&lgo->seqs[i]);
		i++;
	}
	free_x((void **)&lgo->seqs);
	free_x((void **) go);
	return (1);
}
