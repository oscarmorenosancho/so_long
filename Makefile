# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/03 12:16:09 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC_R = events.c\
ft_check_collision.c\
ft_check_map.c\
ft_check_trail.c\
ft_check_trail_stack.c\
ft_count_map_stats.c\
ft_draw.c\
ft_draw_game_chars.c\
ft_extract_game_chars.c\
ft_init_tab.c\
ft_map_2_table.c\
ft_read_map.c\
ft_update_pos.c\
game_class.c\
graph_ctx.c\
images.c\
main.c\
table_class.c

SRCB_R = events_bonus.c\
ft_check_collision_bonus.c\
ft_check_map_bonus.c\
ft_check_trail_bonus.c\
ft_check_trail_stack_bonus.c\
ft_count_map_stats_bonus.c\
ft_draw_bonus.c\
ft_draw_game_chars_bonus.c\
ft_extract_game_chars_bonus.c\
ft_init_tab_bonus.c\
ft_map_2_table_bonus.c\
ft_read_map_bonus.c\
ft_update_pos_bonus.c\
game_class_bonus.c\
graph_ctx_bonus.c\
images_bonus.c\
main_bonus.c\
table_class_bonus.c

SRC_PATH = src/
SRCB_PATH = src_bonus/
SRC = ${addprefix $(SRC_PATH), $(SRC_R)}
SRCB = ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJ := $(SRC:.c=.o)
OBJB := $(SRCB:.c=.o)
DEPS = $(SRC:.c=.d)
DEPSB = $(SRCB:.c=.d)
DEPS_SL = so_long.d
CC	= 	gcc
CFLAGS = -Wall -Werror -Wextra -MMD
RM	= 	rm -f
LIBC	= 	ar -rcs
HEADER = src/so_long.h
HEADERB = src_bonus/so_long_bonus.h
LIBFT_H = libft/libft.h
LIBFT_A = libft/libft.a
LIBFT_D = libft/libft.d
MLX_A = mlx/libmlx.a
LIBS_FLAGS = -lm -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_D_CONT = $(shell cat ${LIBFT_D})

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -I ${LIBFT_H} -c $< -o ${<:.c=.o}

all : $(NAME) 

-include $(DEPS) $(DEPS_SL)
$(NAME) : ${LIBFT_A} ${MLX_A} ${OBJ} $(LIBFT_H)
	${CC} ${CFLAGS} -I ${HEADER}  -I ${LIBFT_H} \
		${OBJ} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

-include $(DEPSB) $(DEPS_SL)
bonus: ${LIBFT_A} ${MLX_A} ${OBJB} ${HEADERB} ${LIBFT_H}
	${CC} ${CFLAGS} -I ${HEADERB}  -I ${LIBFT_H} \
		${OBJB} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $(NAME)
	@touch $@

-include $(DEPS_SL)
${LIBFT_A} : ${LIBFT_D_CONT}
	make bonus -C libft

${MLX_A} :
	make -C mlx 2> /dev/null

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJB)
	$(RM) $(DEPS)
	$(RM) $(DEPSB)
	$(RM) *.o
	$(RM) *.d
	make clean -C mlx
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	$(RM) bonus
	make fclean -C libft

re: fclean all

.PHONY : clean fclean re all