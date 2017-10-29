CC				=	clang
NAME			=	fractol
FLAGS			=	-Wall -Wextra -Werror
FRAMEWORKS		=	-framework OpenGL -framework AppKit -lpthread
MLX_PATH		=	minilibx_macos-sierra/
MLX				=	$(MLX_PATH)/libmlx.a
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft -L $(MLX_PATH) -lmlx
INCLUDES		=	-I $(LIB_PATH)includes -I ./includes -I $(MLX_PATH)
SRCS			=	src/main.c						\
					src/hook.c						\
					src/mlx_handler.c				\
					src/env.c						\
					src/draw.c						\
					src/keys.c						\
					src/keys_handlers.c				\
					src/complex.c					\
					src/tools.c						\
					src/criss_cross.c				\
					src/thread.c					\
					src/color_gradient.c			\
					src/color_convert.c				\
					src/color_calc.c				\
					src/tools.c						\
					src/fract_julia.c				\
					src/fract_mandel.c				\
					src/fract_ark.c					\
					src/fract_tree.c				\
					src/fract_tree_branch.c
OBJS			=	$(SRCS:src/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)


all: obj $(NAME)

$(NAME): $(MLX) $(LIB) $(OBJS)
	@$(CC) $(FLAGS) $(LIB_LINK) $(FRAMEWORKS) -o $@ $^
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

obj/%.o: src/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@make -C $(MLX_PATH) clean
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean

