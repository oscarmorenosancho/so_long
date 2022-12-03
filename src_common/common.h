/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:37:53 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/03 18:43:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# define MAX_GO			8
# define DISP_WIDTH		2600
# define DISP_HEIGHT	1360

//Prototypes
//ON_KEYDOWN	2	int (*f)(int keycode, void *param)
//ON_KEYUP*		3	int (*f)(int keycode, void *param)
//ON_MOUSEDOWN*	4	int (*f)(int button, int x, int y, void *param)
//ON_MOUSEUP	5	int (*f)(int button, int x, int y, void *param)
//ON_MOUSEMOVE	6	int (*f)(int x, int y, void *param)
//ON_EXPOSE*	12	int (*f)(void *param)
//ON_DESTROY	17	int (*f)(void *param)
enum e_on_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum e_events
{
	ev_KeyPress = 2,
	ev_KeyRelease = 3,
	ev_ButtonPress = 4,
	ev_ButtonRelease = 5,
	ev_MotionNotify = 6,
	ev_EnterNotify = 7,
	ev_LeaveNotify = 8,
	ev_FocusIn = 9,
	ev_FocusOut = 10,
	ev_KeymapNotify = 11,
	ev_Expose = 12,
	ev_GraphicsExpose = 13,
	ev_NoExpose = 14,
	ev_VisibilityNotify = 15,
	ev_CreateNotify = 16,
	ev_DestroyNotify = 17,
	ev_UnmapNotify = 18,
	ev_MapNotify = 19,
	ev_MapRequest = 20,
	ev_ReparentNotify = 21,
	ev_ConfigureNotify = 22,
	ev_ConfigureRequest = 23,
	ev_GravityNotify = 24,
	ev_ResizeRequest = 25,
	ev_CirculateNotify = 26,
	ev_CirculateRequest = 27,
	ev_PropertyNotify = 28,
	ev_SelectionClear = 29,
	ev_SelectionRequest = 30,
	ev_SelectionNotify = 31,
	ev_ColormapNotify = 32,
	ev_ClientMessage = 33,
	ev_MappingNotify = 34,
	ev_GenericEvent = 35,
	ev_LASTEvent = 36
};
enum e_masks
{
	NoEventMask = 0X0,
	KeyPressMask = 0x1,
	KeyReleaseMask = 0x2,
	ButtonPressMask = 0x4,
	ButtonReleaseMask = 0x8,
	EnterWindowMask = 0x10,
	LeaveWindowMask = 0x20,
	PointerMotionMask = 0x40,
	PointerMotionHintMask = 0x80,
	Button1MotionMask = 0x100,
	Button2MotionMask = 0x200,
	Button3MotionMask = 0x400,
	Button4MotionMask = 0x800,
	Button5MotionMask = 0x1000,
	ButtonMotionMask = 0x2000,
	KeymapStateMask = 0x4000,
	ExposureMask = 0x8000,
	VisibilityChangeMask = 0x10000,
	StructureNotifyMask = 0x20000,
	ResizeRedirectMask = 0x40000,
	SubstructureNotifyMask = 0x80000,
	SubstructureRedirectMask = 0x100000,
	FocusChangeMask = 0x200000,
	PropertyChangeMask = 0x400000,
	ColormapChangeMask = 0x800000,
	OwnerGrabButtonMask = 0x1000000
};

enum e_keycodes
{
	KC_ESC = 0x35,
	KC_Q = 0xc,
	KC_W = 0xd,
	KC_E = 0xe,
	KC_R = 0xf,
	KC_T = 0x11,
	KC_A = 0x0,
	KC_S = 0x1,
	KC_D = 0x2,
	KC_F = 0x3,
	KC_G = 0x5,
	KC_Z = 0x6,
	KC_X = 0x7,
	KC_C = 0x8,
	KC_V = 0x9,
	KC_LEFT = 0x7b,
	KC_RIGHT = 0x7c,
	KC_DOWN = 0x7d,
	KC_UP = 0x7e,
	KC_RETURN = 0x24
};

enum e_gr_ob_refs
{
	GO_GROUND = 0,
	GO_WALL = 1,
	GO_EXIT = 2,
	GO_PLAYER = 3,
	GO_COLLECT = 4,
	GO_ENEMY = 5,
	GO_BLOCK1 = 6,
	GO_BLOCK2 = 7
};

typedef struct s_image
{
	void	*ref;
	int		size[2];
}	t_image;

typedef struct s_gr_ob
{
	t_image	frms[10];
	int		count;
}	t_gr_ob;


typedef struct s_game_stats
{
	int	players;
	int	exits;
	int	collectables;
	int	enemies;
	int	invalids;
}	t_game_stats;

typedef struct s_table
{
	int	size[2];
	int	**mat;
}	t_table;

typedef struct s_trail_data
{
	t_table			*t;
	t_list			*stack;
	t_list			*node;
	t_game_stats	stats;
	int				*pos;
}	t_trail_data;

t_list	*ft_read_map(char *filename);
int		ft_check_stack(t_trail_data	*td);
int		ft_push_trail_pos(t_trail_data *td, int *pos);
t_table	*table_constructor(int *size);
int		table_dispose(t_table **tab);
t_table	*table_dup(t_table *tab);
#endif