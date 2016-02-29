# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/02/29 09:21:07 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

//CFLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

INCLUDES_MLX = ./minilibx_macos/includes

LIBFT_PATH = ./libft

LIBMLX_PATH = ./minilibx_macos

SRC_NAME = main.c ft_hook.c ft_draw_image.c ft_init_scene.c ft_calc_int_sphere.c \
		   ft_lstfree_malloc.c ft_sphere_new.c \
		   ft_plane_new.c ft_calc_int_plane.c ft_scalar_product.c ft_calc_int_pos.c \
		   ft_light_new.c ft_plane_getlight.c ft_plane_has_int.c \
		   ft_plane_material.c ft_sphere_material.c ft_getlight.c \
		   ft_sphere_has_int.c \
		   ft_calc_int_sphere_light.c ft_sphere_getlight.c ft_plane_ambiant.c \
		   ft_sphere_ambiant.c ft_mix_color.c ft_calc_int_plane_light.c \
		   ft_is_light_interrupt.c ft_getambiant_light.c

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = RTv1

all :	libft libmlx $(NAME)

libft :
	make -C $(LIBFT_PATH)

libmlx :
	make -C $(LIBMLX_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -lmlx -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_MLX) -L$(LIBFT_PATH) -L$(LIBMLX_PATH) -framework OpenGL -framework Appkit

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_MLX)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBMLX_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean
	rm -rf $(LIBMLX_PATH)/libmlx.a

re : fclean all

.PHONY : all clean fclean re libft libmlx
