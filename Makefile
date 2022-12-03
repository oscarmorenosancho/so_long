# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/03 11:46:24 by omoreno-         ###   ########.fr        #
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

SRCB_R = 

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

-include $(DEPS) $(DEPSB) $(DEPS_SL)
bonus: ${LIBFT_A} ${MLX_A} ${OBJ} ${OBJB} ${HEADER} ${LIBFT_H}
	${CC} ${CFLAGS} -I ${HEADER}  -I ${LIBFT_H} \
		${OBJ} ${OBJB} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@
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