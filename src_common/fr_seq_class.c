/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_seq_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:09:20 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/07 18:10:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static char	*ft_itoa_fixed2(int nbr)
{
	char	*buf1;
	char	*buf2;
	char	*buf3;

	buf2 = ft_itoa(nbr);
	if (ft_strlen_x(buf2) < 2)
	{
		buf1 = ft_strdup("0");
		buf3 = ft_str_merge(&buf1, &buf2);
		return (buf3);
	}
	return (buf2);
}

static char	*ft_construct_name(char *name, int seq, int frame)
{
	char	*buf1;
	char	*buf2;
	char	*buf3;

	buf1 = ft_strdup(name);
	buf2 = ft_itoa_fixed2(seq);
	buf3 = ft_str_merge(&buf1, &buf2);
	buf1 = buf3;
	buf2 = ft_strdup("/f");
	buf3 = ft_str_merge(&buf1, &buf2);
	buf1 = buf3;
	buf2 = ft_itoa_fixed2(frame);
	buf3 = ft_str_merge(&buf1, &buf2);
	buf1 = buf3;
	buf2 = ft_strdup(".xpm");
	buf3 = ft_str_merge(&buf1, &buf2);
	return (buf3);
}

t_fr_seq	*fr_seq_constructor(t_graphics *gr_ctx, char *name, \
			int seq, int frms)
{
	t_fr_seq	*fs;
	int			i;
	char		*framename;

	if (frms < 1)
		return (NULL);
	fs = ft_calloc(1, sizeof(t_fr_seq));
	if (! fs)
		return (fs);
	fs->count = frms;
	fs->frms = ft_calloc(frms, sizeof(t_image *));
	if (! fs->frms)
		fr_seq_dispose(&fs);
	fs->count = frms;
	i = 0;
	while (i < frms && fs)
	{
		framename = ft_construct_name(name, seq, i);
		fs->frms[i] = image_constructor(gr_ctx, framename);
		free_x((void **)&framename);
		if (! fs->frms[i])
			fr_seq_dispose(&fs);
		i++;
	}
	return (fs);
}

int	fr_seq_dispose(t_fr_seq **fs)
{
	int			i;
	t_fr_seq	*lfs;

	if (! fs)
		return (0);
	lfs = *fs;
	i = 0;
	while (i < lfs->count)
	{
		image_dispose(&lfs->frms[i]);
		i++;
	}
	free_x((void **)&lfs->frms);
	free_x((void **)fs);
	return (1);
}
