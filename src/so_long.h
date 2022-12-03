/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:37:53 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 18:12:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BLOCK_WIDTH	40
# define BLOCK_HEIGHT	40
# include "../src_common/common.h"

typedef struct s_graphics
{
	void	*inst;
	void	*wnd;
	int		wnd_size[2];
	t_image	img[MAX_IMG];
}	t_graphics;

typedef struct s_game
{
	t_graphics		*gr_ctx;
	char			*map_file;
	t_list			*list;
	t_list			*collectables;
	t_list			*enemies;
	t_table			*t;
	t_game_stats	stats;
	int				pos[2];
	int				exit_pos[2];
	int				exit_cmd;
}	t_game;

int		ft_create_graph_ctx(t_game *game);
int		ft_dispose_graph_ctx(t_game *game);
t_game	*game_constructor(char *map_file);
t_game	*game_dispose(t_game **game);
void	ft_count_map_stats(t_game *game);
int		ft_check_map(t_game *game);
int		ft_map_2_table(t_game *game);
int		ft_check_trail(t_game *game);
t_game	*ft_init_game(t_game *game);
int		ft_extract_game_chars(t_game *game);
t_list	*ft_findfirst_with_pos(t_list *lst, int *pos);
t_list	*ft_check_collision(t_game *game, int *displ, int el);
int		ft_update_pos(int keycode, t_game *game);
int		ft_load_images(t_graphics *gr_ctx);
int		ft_dispose_images(t_graphics *gr_ctx);
int		ft_init_tab(t_game *game);
int		ft_draw(t_game *game);
int		ft_draw_game_chars(t_game *game);
int		ft_handle_no_event(void *data);
int		ft_close(void *param);
int		ft_key_input(int keycode, void *param);
#endif