# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/01 19:13:09 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/*.c get_next_line/*.c
SRCB = bonus/*.c

OBJ := $(SRC:.c=.o)
OBJB := $(SRCB:.c=.o)
DEPS = $(SRC:.c=.d)
DEPSB = $(SRCB:.c=.d)
CC	= 	gcc
CFLAGS = -Wall -Werror -Wextra -MMD
RM	= 	rm -f
LIBC	= 	ar -rcs
HEADER = src/main.h
LIBFT_H = libft/libft.h
LIBFT_A = libft/libft.a
MLX_A = mlx/libmlx.a
LIBS_FLAGS = -lm -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -I ${LIBFT_H} -c $< -o ${<:.c=.o}

all : $(NAME) 

-include: $(DEPS)
$(NAME) : ${LIBFT_A} ${MLX_A} $(LIBFT_H)
	${CC} ${CFLAGS} -I ${HEADER}  -I ${LIBFT_H} \
		src/*.c ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

-include: $(DEPS) $(DEPSB)
bonus: $(OBJ) $(OBJB) $(HEADER) $(LIBFT_H)
	$(LIBC) $(NAME) $(OBJ) $(OBJB)
	@touch $@

${LIBFT_A} :
	make bonus -C libft

${MLX_A} :
	make -C mlx

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