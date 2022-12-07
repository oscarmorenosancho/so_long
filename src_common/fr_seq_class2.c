/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_seq_class2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:28:25 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/06 17:29:03 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	*fr_seq_get_img_ref(t_fr_seq *fr_seq, int frm)
{
	return (fr_seq->frms[frm]->ref);
}

int	*fr_seq_get_img_size(t_fr_seq *fr_seq, int frm)
{
	return (fr_seq->frms[frm]->size);
}

void	fr_seq_set_img_ref(t_fr_seq *fr_seq, int frm, void *ref)
{
	fr_seq->frms[frm]->ref = ref;
}