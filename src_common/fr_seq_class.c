/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_seq_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:09:20 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 17:22:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_fr_seq	*fr_seq_constructor(char *name, int seq, int frms)
{
	t_fr_seq	*fs;
	char		*filenamebase;
	int			f;
	int			s;

	f = frms;
	s = seq;
	filenamebase = name;
	fs = malloc(sizeof(t_fr_seq));
	if (! fs)
		return (fs);
	return (fs);
}

int	dispose_fr_seq(t_fr_seq **fs)
{
	t_fr_seq	*lfs;

	if (! fs)
		return (0);
	lfs = *fs;
	free_x((void **)fs);
	return (1);
}
