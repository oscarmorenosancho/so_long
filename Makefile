# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2023/07/25 11:05:29 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
NAMEB := ${addsuffix _bonus, $(NAME)}

SRCC_R:= ft_read_map.c\
ft_check_trail_stack.c\
table_class.c\
events.c\
ft_check_collision.c\
ft_check_map.c\
ft_check_trail.c\
ft_count_map_stats.c\
ft_draw.c\
ft_draw_game_chars.c\
ft_extract_game_chars.c\
ft_map_2_table.c\
ft_update_player_seq.c\
ft_check_dest.c\
ft_update_pos.c\
ft_update_enemies.c\
game_class.c\
graph_ctx.c\
gr_ob_class.c\
gr_ob_class2.c\
gr_ob_list_class.c\
fr_seq_class.c\
fr_seq_class2.c\
image_class.c\
ft_take_argument.c

SRC_R := main.c\
ft_init_gr_ob_list.c

SRCB_R := main_bonus.c\
ft_init_gr_ob_list_bonus.c

SRCC_PATH := src_common/
SRC_PATH := src/
SRCB_PATH := src_bonus/
LIBFT_PATH := libft/
MLX_PATH := mlx/
BUILD_PATH	:= build/
SRCC	:= ${addprefix $(SRCC_PATH), $(SRCC_R)}
SRC		:= ${addprefix $(SRC_PATH), $(SRC_R)}
SRCB	:= ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJC	:= $(addprefix $(BUILD_PATH), $(SRCC:.c=.o))
OBJ		:= $(addprefix $(BUILD_PATH), $(SRC:.c=.o))
OBJB	:= $(addprefix $(BUILD_PATH), $(SRCB:.c=.o))
DEPSC	:= $(addprefix $(BUILD_PATH), $(SRCC:.c=.d))
DEPS	:= $(addprefix $(BUILD_PATH), $(SRC:.c=.d))
DEPSB	:= $(addprefix $(BUILD_PATH), $(SRCB:.c=.d))
CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
CFD := -MMD
RM	:= 	rm -f
LIBC := 	ar -rcs
HEADERC := ${addprefix $(SRCC_PATH), common.h}
HEADER := ${addprefix $(SRC_PATH), so_long.h}
HEADERB := ${addprefix $(SRCB_PATH), so_long_bonus.h}
LIBFT_H := ${addprefix $(LIBFT_PATH), libft.h}
LIBFT_A := ${addprefix $(LIBFT_PATH), libft.a}
LIBFT_D := ${addprefix $(LIBFT_PATH), libft.d}
MLX_A := ${addprefix $(MLX_PATH), libmlx.a}
MLX_H := ${addprefix $(MLX_PATH), libmlx.h}
LIBS_FLAGS := -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -I ${LIBFT_H} -I ${MLX_H}
LIBFT_D_CONT := $(shell cat ${LIBFT_D})

folder_create = $(shell mkdir -p $(1))

.SECONDEXPANSION:

$(BUILD_PATH)%.o: %.c ${HEADER} | $$(call folder_create,$$(dir $$@))
	@echo "Compiling " $< " ..."
	${CC} ${CFLAGS} ${CFD} -I ${LIBFT_PATH} -I ${MLX_PATH} -c $< -o $@

all : $(NAME)
bonus : $(NAMEB)

-include $(DEPS)
$(NAME) : ${OBJC} ${OBJ} ${LIBFT_A} ${MLX_A}
	${CC} ${CFLAGS} \
		${OBJ} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

-include $(DEPSB)
$(NAMEB): ${OBJC} ${OBJB} ${LIBFT_A} ${MLX_A}
	${CC} ${CFLAGS} \
		${OBJB} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

${LIBFT_A} : ${LIBFT_D_CONT}
	make -C libft

${MLX_A} :
	make -C mlx 2> /dev/null

clean :
	$(RM) -Rf $(BUILD_PATH)
	make clean -C mlx
	make clean -C libft

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY : clean fclean re all bonus