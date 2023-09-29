# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2023/09/29 19:52:13 by omoreno-         ###   ########.fr        #
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

SRCC_PATH 		:= src_common/
SRC_PATH		:= src/
SRCB_PATH		:= src_bonus/
LIBFT_PATH		:= libft/
MLX_PATH		:= mlx/
MLX_MC_PATH		:= mlx_mc/
MLX_LX_PATH		:= mlx_lx/
BUILD_PATH		:= .build/
SRCC			:= ${addprefix $(SRCC_PATH), $(SRCC_R)}
SRC				:= ${addprefix $(SRC_PATH), $(SRC_R)}
SRCB			:= ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJC			:= $(addprefix $(BUILD_PATH), $(SRCC:.c=.o))
OBJ				:= $(addprefix $(BUILD_PATH), $(SRC:.c=.o))
OBJB			:= $(addprefix $(BUILD_PATH), $(SRCB:.c=.o))
DEPSC			:= $(addprefix $(BUILD_PATH), $(SRCC:.c=.d))
DEPS			:= $(addprefix $(BUILD_PATH), $(SRC:.c=.d))
DEPSB			:= $(addprefix $(BUILD_PATH), $(SRCB:.c=.d))

OS				:= $(shell uname -s | tr '[:upper:]' '[:lower:]')
CC				:= 	@gcc
OPTIM_FLAG		:= -O3
CFLAGS			:= -Wall -Werror -Wextra -g -O3
SANIT_FLAG		:=  -fsanitize=address
CFD				:= -MMD
RM				:= 	@rm -Rf
LIBC 			:= 	@ar -rcs
HEADERC 		:= ${addprefix $(SRCC_PATH), common.h}
HEADER 			:= ${addprefix $(SRC_PATH), ${addprefix $(NAME), .h}}
HEADERB 		:= ${addprefix $(SRCB_PATH), ${addprefix $(NAMEB), .h}}
LIBFT_H 		:= ${addprefix $(LIBFT_PATH), libft.h}
LIBFT_A 		:= ${addprefix $(LIBFT_PATH), libft.a}
LIBFT_D 		:= ${addprefix $(LIBFT_PATH), libft.d}
MLX_A 			:= ${addprefix $(MLX_PATH), libmlx.a}
MLX_H 			:= ${addprefix $(MLX_PATH), libmlx.h}
LIBS_MC_FLAGS  := -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -I ${LIBFT_H} -I ${MLX_H}
LIBS_LX_FLAGS   := -I/usr/include -Imlx_linux -O1
LIBS_LX_FLAGS_LK:= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz3
ifeq ($(OS),linux)
	LIBS_FLAGS		:= ${LIBS_LX_FLAGS}
	LIBS_FLAGS_LK	:= ${LIBS_LX_FLAGS_LK}
	MLX_OS_PATH		:= ${MLX_LX_PATH}
	OLD_MAKE		:= @make
else
	LIBS_FLAGS		:=
	LIBS_FLAGS_LK	:= ${LIBS_MC_FLAGS}
	MLX_OS_PATH		:= ${MLX_MC_PATH}
	OLD_MAKE		:= @make3.81
endif
LIBFT_D_CONT	:= $(shell cat ${LIBFT_D} 2> /dev/null)

folder_create 	= $(shell mkdir -p $(1))

.SECONDEXPANSION:

$(BUILD_PATH)%.o: %.c ${HEADER} Makefile | $$(call folder_create,$$(dir $$@))
	@echo "Compiling " $@ " ..."
	${CC} ${CFLAGS} ${CFD} -I ${LIBFT_PATH} -I ${MLX_PATH} ${LIBS_FLAGS} -c $< -o $@

all : $(NAME)
bonus : $(NAMEB)

-include $(DEPS)
-include $(DEPSC)
$(NAME) : ${LIBFT_A} ${MLX_A} ${OBJC} ${OBJ} Makefile
	@echo "Linking " $@ " ..."
	${CC} ${CFLAGS} \
		${OBJ} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS_LK} -o $@

-include $(DEPSB)
$(NAMEB): ${LIBFT_A} ${MLX_A} ${OBJC} ${OBJB} Makefile
	@echo "Linking " $@ " ..."
	${CC} ${CFLAGS} \
		${OBJB} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS_LK} -o $@

${LIBFT_A} : ${LIBFT_D_CONT} libft/Makefile
	@echo "Making " $@ " if necessary.."
	@make -C libft

${MLX_A} : $(MLX_PATH)
	@echo "Making " $@ " if nececessary..."
	@echo "Host Operative System: " ${OS}
	${OLD_MAKE} -C mlx 2> /dev/null 1> /dev/null

$(MLX_PATH) :
	cp -R $(MLX_OS_PATH) $(MLX_PATH)

clean :
	@echo "Cleaning ..."
	@echo "Cleaning $(BUILD_PATH) ..."
	$(RM) $(BUILD_PATH)
	@echo "Cleaning MLX ..."
	$(RM) $(MLX_PATH)
	@echo "Cleaning LIBFT ..."
	@make clean -C libft

fclean : clean
	@echo "Full cleaning ..."
	@echo "Cleaning LIBFT ..."
	@make fclean -C libft
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY : clean fclean re all bonus