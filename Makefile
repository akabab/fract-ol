# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 19:10:49 by jspezia           #+#    #+#              #
#    Updated: 2015/01/30 11:47:09 by ycribier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPATH		= src
OPATH		= obj
HPATH		= includes
LIBPATH		= ./libft
HLIB		= $(LIBPATH)/includes
LIB			= $(LIBPATH) -lft
LIBA		= $(LIBPATH)/libft.a

MLXPATH		= /usr/X11/lib
MLX			= $(MLXPATH) -lXext -lX11 -lmlx

CC			= gcc $(FLAGS) $(XFLAGS)
FLAGS		= -Wall -Werror -Wextra
XFLAGS		= -g -O2

NAME		= exec

SRC			= main.c						\
			  criss_cross.c					\
			  draw.c						\
			  hook.c						\
			  keys.c

CFILE		= $(patsubst %,$(CPATH)/%, $(SRC))
OFILE		= $(patsubst %.c,$(OPATH)/%.o, $(SRC))

# COLORS
C_NO	= "\033[00m"
C_GOOD	= "\033[32m"

all: $(NAME)

$(NAME): $(OPATH) $(OFILE) $(LIBA)
	@$(CC) -I $(HLIB) -I $(HPATH) -L $(LIB) -L $(MLX) $ $(OFILE) -o $(NAME)
	@echo $(C_GOOD)Creation Executable$(C_NO)

$(LIBA):
	@make -C $(LIBPATH)
	@make -C $(LIBPATH) clean

$(OPATH):
	@echo "Creation of building directory"
	@mkdir $(OPATH)

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "Creating file $@"
	@$(CC) -o $@ -c $^ -I $(HPATH) -I $(HLIB) -I /usr/X11/include

clean:
	@echo "Deletion of building directory"
	@rm -rf $(OPATH)

fclean: clean
	@echo "Deletion of $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
