# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 17:24:10 by humanfou          #+#    #+#              #
#    Updated: 2021/02/23 22:11:57 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SANITIZE = -O1 -g -fsanitize=address -fno-omit-frame-pointer

NAME = cub3D

BONUS = cub3D_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS_DIR = -Lmlx -Llibft

LIBS = -lmlx -lXext -lX11 -lm -lbsd -lft

COMMON_INC = -Iincludes \
		-Ilibft \
		-Imlx \
		-Isrcs/common/bmp \
		-Isrcs/common/engine \
		-Isrcs/common/event \
		-Isrcs/common/init \
		-Isrcs/common/isset \
		-Isrcs/common/render \
		-Isrcs/common/setup \
		-Isrcs/common/sprites \
		-Isrcs/common/util \
		-Isrcs/common/validate \
		-Isrcs/common/wall \
		-Isrcs/common/window \

MANDATORY_INC = -Isrcs/mandatory/includes

BONUS_INC = -Isrcs/bonus/includes

COMMON_SRCS = srcs/main.c \
		$(wildcard srcs/common/bmp/*.c) \
		$(wildcard srcs/common/engine/*.c) \
		$(wildcard srcs/common/event/*.c) \
		$(wildcard srcs/common/init/*.c) \
		$(wildcard srcs/common/isset/*.c) \
		$(wildcard srcs/common/render/*.c) \
		$(wildcard srcs/common/setup/*.c) \
		$(wildcard srcs/common/sprites/*.c) \
		$(wildcard srcs/common/util/*.c) \
		$(wildcard srcs/common/validate/*.c) \
		$(wildcard srcs/common/wall/*.c) \
		$(wildcard srcs/common/window/*.c) \

MANDATORY_SRCS = srcs/mandatory/cub3d.c \
		srcs/mandatory/isset/is_set_config.c \
		srcs/mandatory/setup/set_config.c \
		srcs/mandatory/setup/set_map.c \
		srcs/mandatory/setup/set_sprites.c \
		srcs/mandatory/setup/set_textures.c \
		srcs/mandatory/sprites/count_sprites.c \
		srcs/mandatory/sprites/set_sprite_params.c \
		srcs/mandatory/util/is_sprite.c \
		srcs/mandatory/validate/is_valid_char.c \
		srcs/mandatory/validate/is_valid_texture.c \

BONUS_SRCS = srcs/bonus/cub3d_bonus.c \
		srcs/bonus/isset/is_set_config_bonus.c \
		srcs/bonus/setup/set_config_bonus.c \
		srcs/bonus/setup/set_map_bonus.c \
		srcs/bonus/setup/set_sprites_bonus.c \
		srcs/bonus/setup/set_textures_bonus.c \
		srcs/bonus/sprites/count_sprites_bonus.c \
		srcs/bonus/sprites/set_sprite_params_bonus.c \
		srcs/bonus/util/is_sprite_bonus.c \
		srcs/bonus/validate/is_valid_char_bonus.c \
		srcs/bonus/validate/is_valid_texture_bonus.c \

COMMON_OBJS = $(COMMON_SRCS: %.c=%.o)

MANDATORY_OBJS = $(MANDATORY_SRCS: %.c=%.o)

BONUS_OBJS = $(BONUS_SRCS: %.c=%.o)

all: $(NAME)

$(NAME): $(COMMON_OBJS) $(MANDATORY_OBJS)
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	@$(CC) $(SANITIZE) -o $(NAME) $(COMMON_OBJS) $(MANDATORY_OBJS) $(COMMON_INC) $(MANDATORY_INC) $(LIBS) $(LIBS_DIR)

bonus: $(BONUS)

$(BONUS): $(COMMON_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C mlx
	@$(MAKE) -C libft
	@$(CC) $(SANITIZE) -o $(BONUS) $^ $(COMMON_INC) $(BONUS_INC) $(LIBS) $(LIBS_DIR)

clean:
	@cd libft && $(MAKE) clean
	@echo libft objects files cleaned!
	@rm -fr *.o screenshot.bmp
	@echo cub3d ojects files and screenshot removed!

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -fr $(NAME) $(BONUS)

re: fclean bonus

.PHONY: all bonus clean fclean re
