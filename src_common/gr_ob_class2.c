/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_ob_class2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:30:52 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/06 17:31:24 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	*gr_ob_get_img_ref(t_gr_ob *gr_ob, int seq, int frm)
{
	return (fr_seq_get_img_ref(gr_ob->seqs[seq], frm));
}

int	*gr_ob_get_img_size(t_gr_ob *gr_ob, int seq, int frm)
{
	return (fr_seq_get_img_size(gr_ob->seqs[seq], frm));
}

void	gr_ob_set_img_ref(t_gr_ob *gr_ob, int seq, int frm, void *ref)
{
	fr_seq_set_img_ref(gr_ob->seqs[seq], frm, ref);
}
