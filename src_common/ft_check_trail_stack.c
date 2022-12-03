/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_trail_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:16:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 17:55:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_print_pos_push(int *pos)
{
	ft_putstr_fd("Push: ", 1);
	if (pos[0] < 10)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(pos[0], 1);
	ft_putstr_fd(", ", 1);
	if (pos[1] < 10)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(pos[1], 1);
	ft_putstr_fd("\n", 1);
}

int	ft_push_trail_pos(t_trail_data *td, int *pos)
{
	td->node = NULL;
	if (td->t->mat[pos[1]][pos[0]] == RI_WALL || \
		td->t->mat[pos[1]][pos[0]] > 99)
		return (1);
	td->pos = ft_dup_pos(pos);
	if (td->pos)
	{
		td->node = ft_lstnew(td->pos);
		if (! td->node)
		{
			ft_log_error("Malloc failed when pushing node\n");
			free_x((void **)&td->pos);
		}
	}
	else
		ft_log_error("Malloc failed when dup pos in push\n");
	if (td->node)
	{
		ft_lstadd_front(&td->stack, td->node);
		td->t->mat[pos[1]][pos[0]] += 100;
		if (0)
			ft_print_pos_push(pos);
		return (1);
	}
	return (0);
}

static int	ft_push_adjacents(t_trail_data *td, int *pos)
{
	int	pos_adj[2];
	int	res;

	ft_copy_pos(pos_adj, pos);
	pos_adj[0]++;
	res = ft_push_trail_pos(td, pos_adj);
	if (! res)
		return (res);
	ft_copy_pos(pos_adj, pos);
	pos_adj[1]++;
	res = ft_push_trail_pos(td, pos_adj);
	if (! res)
		return (res);
	ft_copy_pos(pos_adj, pos);
	pos_adj[0]--;
	res = ft_push_trail_pos(td, pos_adj);
	if (! res)
		return (res);
	ft_copy_pos(pos_adj, pos);
	pos_adj[1]--;
	res = ft_push_trail_pos(td, pos_adj);
	return (res);
}

int	ft_check_stack(t_trail_data *td)
{
	int		el;
	int		*pos;
	t_list	*node;
	int		res;

	res = 1;
	while (td->stack && res)
	{
		node = td->stack;
		td->stack = node->next;
		pos = node->content;
		el = td->t->mat[pos[1]][pos[0]];
		if (el % 100 == RI_PLAYER)
			td->stats.players++;
		else if (el % 100 == RI_EXIT)
			td->stats.exits++;
		else if (el % 100 == RI_COLLECT)
			td->stats.collectables++;
		td->t->mat[pos[1]][pos[0]] = RI_WALL;
		res = ft_push_adjacents(td, pos);
		ft_lstdelone(node, &free);
	}
	return (res);
}
