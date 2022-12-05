# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/05 11:14:28 by omoreno-         ###   ########.fr        #
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
ft_init_tab.c\
ft_map_2_table.c\
ft_update_pos.c\
game_class.c\
graph_ctx.c\
images.c\
ft_take_argument.c

SRC_R := main.c

SRCB_R := main.c

SRCC_PATH := src_common/
SRC_PATH := src/
SRCB_PATH := src_bonus/
LIBFT_PATH := libft/
MLX_PATH := mlx/
SRCC := ${addprefix $(SRCC_PATH), $(SRCC_R)}
SRC := ${addprefix $(SRC_PATH), $(SRC_R)}
SRCB := ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJC := $(SRCC:.c=.o)
OBJ := $(SRC:.c=.o)
OBJB := $(SRCB:.c=.o)
DEPSC := $(SRCC:.c=.d)
DEPS := $(SRC:.c=.d)
DEPSB := $(SRCB:.c=.d)
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

src/%.o : src/%.c ${HEADER}
	${CC} ${CFLAGS} ${CFD} -I ${HEADER} -I ${LIBFT_H} -I ${MLX_H} -c $< -o $@

src_common/%.o : src_common/%.c ${HEADERC}
	${CC} ${CFLAGS} ${CFD} -I ${HEADERC} -I ${LIBFT_H} -I ${MLX_H} -c $< -o $@

src_bonus/%.o : src_bonus/%.c ${HEADERB}
	${CC} ${CFLAGS} ${CFD} -I ${HEADERB} -I ${LIBFT_H} -I ${MLX_H} -c $< -o $@

all : $(NAME)
bonus : $(NAMEB)

-include $(DEPS)
$(NAME) : ${LIBFT_A} ${MLX_A} ${OBJC} ${OBJ} 
	${CC} ${CFLAGS} -I ${HEADER} \
		${OBJC} ${OBJ} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

-include $(DEPSB)
$(NAMEB): ${LIBFT_A} ${MLX_A} ${OBJC} ${OBJB}
	${CC} ${CFLAGS} -I ${HEADERB} \
		${OBJC} ${OBJB} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

${LIBFT_A} : ${LIBFT_D_CONT}
	make bonus -C libft

${MLX_A} :
	make -C mlx 2> /dev/null

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJC)
	$(RM) $(OBJB)
	$(RM) $(DEPS)
	$(RM) $(DEPSC)
	$(RM) $(DEPSB)
	$(RM) *.o
	$(RM) *.d
	make clean -C mlx
	make clean -C libft

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY : clean fclean re all bonus