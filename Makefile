CC				=	gcc
FLAGS			=	-g -Wall -Wextra -Werror
NAME			=	fractol
LIB				=	libft/libft.a
LIB_PATH		=	libft/
INCLUDES		=	-I $(LIB_PATH)./includes -I ./includes
DIR_LIBS		=	/usr/X11/lib
LDFLAGS			=	-L$(DIR_LIBS) -lXext -lX11 -lmlx
SRCS			=	src/main.c						\
					src/env.c						\
					src/criss_cross.c				\
					src/draw.c						\
					src/hook.c						\
					src/mlx_handler.c				\
					src/keys.c						\
					src/complex.c					\
					src/tools.c
OBJS			=	$(SRCS:src/.c=obj/.o)

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

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LDFLAGS) -L $(LIB_PATH) -lft
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

obj/%.o: src/%.c $(INCLUDES)/fract.h
	@$(CC) $(FLAGS) -c -o $@ $^ $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean

