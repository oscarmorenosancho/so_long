/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_game_chars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:59:36 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/05 12:02:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_extract_player(t_game *game, int pos[2])
{
	ft_copy_pos (game->pos, pos);
	game->t->mat[pos[1]][pos[0]] = GO_GROUND;
}

static void	ft_extract_exit(t_game *game, int pos[2])
{
	ft_copy_pos (game->exit_pos, pos);
	game->t->mat[pos[1]][pos[0]] = GO_GROUND;
}

static void	ft_extract_collectables(t_game *game, int pos[2])
{
	int		*content;
	t_list	*node;

	content = malloc(2 * sizeof(int));
	if (! content)
	{
		ft_log_error("Malloc failed when allocating collectable position\n");
		game_dispose(&game);
	}
	node = ft_lstnew(content);
	if (! node)
	{
		ft_log_error("Malloc failed when allocating collectable node\n");
		free_x((void *)&content);
		game_dispose(&game);
	}
	ft_copy_pos (content, pos);
	ft_lstadd_front(&game->collectables, node);
	game->t->mat[pos[1]][pos[0]] = GO_GROUND;
}

static void	ft_extract_enemies(t_game *game, int pos[2])
{
	int		*content;
	t_list	*node;

	content = malloc(2 * sizeof(int));
	if (! content)
	{
		ft_log_error("Malloc failed when allocating enemy position\n");
		game_dispose(&game);
	}
	node = ft_lstnew(content);
	if (! node)
	{
		ft_log_error("Malloc failed when allocating enemy node\n");
		free_x((void *)&content);
		game_dispose(&game);
	}
	ft_copy_pos (content, pos);
	ft_lstadd_front(&game->enemies, node);
	game->t->mat[pos[1]][pos[0]] = GO_GROUND;
}

int	ft_extract_game_chars(t_game *game)
{
	int	it[2];

	if (! game || ! game->t || ! game->t->mat)
		return (0);
	it[1] = 0;
	while (it[1] < game->t->size[1])
	{
		it[0] = 0;
		while (it[0] < game->t->size[0])
		{
			if (game->t->mat[it[1]][it[0]] == GO_PLAYER)
				ft_extract_player(game, it);
			else if (game->t->mat[it[1]][it[0]] == GO_EXIT)
				ft_extract_exit(game, it);
			else if (game->t->mat[it[1]][it[0]] == GO_COLLECT)
				ft_extract_collectables(game, it);
			else if (game->t->mat[it[1]][it[0]] == GO_ENEMY)
				ft_extract_enemies(game, it);
			it[0]++;
		}
		it[1]++;
	}
	return (1);
}
