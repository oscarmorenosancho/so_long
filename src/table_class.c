/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:16:49 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/29 17:38:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	*row_constructor(t_table **tab, int i)
{
	t_table	*t;

	if (! tab || ! *tab || ! (*tab)->mat)
		return (NULL);
	t = *tab;
	t->mat[i] = ft_calloc(t->size[0], sizeof(int));
	if (!t->mat[i])
	{
		ft_log_error("Malloc failed while constructing table row\n");
		table_dispose(tab);
		return (NULL);
	}
	return (t->mat[i]);
}

t_table	*table_constructor(int *size)
{
	t_table	*tab;
	int		*row;
	int		i;

	if (size[0] < 1 || size[1] < 1)
		return (NULL);
	tab = malloc(sizeof(t_table));
	if (! tab)
	{
		ft_log_error("Malloc failed while constructing table\n");
		return (NULL);
	}
	ft_copy_pos(tab->size, size);
	tab->mat = ft_calloc(size[1], sizeof(int *));
	if (! tab->mat)
	{
		ft_log_error("Malloc failed while constructing table rows vector\n");
		free_x((void **)&tab);
		return (NULL);
	}
	i = 0;
	row = NULL;
	while (i < size[1] && (i == 0 || row))
		row = row_constructor (&tab, i++);
	return (tab);
}

int	table_dispose(t_table **tab)
{
	int		i;
	t_table	*t;

	if (! tab || ! *tab)
		return (0);
	t = *tab;
	if (t->mat)
	{
		i = 0;
		while (i < t->size[1])
		{
			if (t->mat[i])
				free_x((void **)&t->mat[i]);
			i++;
		}
		free_x((void **)&t->mat);
	}
	free_x((void **)tab);
	return (0);
}

t_table	*table_dup(t_table *tab)
{
	t_table	*t;
	int		i;
	int		j;

	if (! tab)
		return (0);
	t = table_constructor(tab->size);
	if (!t)
		return (t);
	j = 0;
	while (j < t->size[1])
	{
		i = 0;
		while (i < t->size[0])
		{
			t->mat[j][i] = tab->mat[j][i];
			i++;
		}
		j++;
	}
	return (t);
}
