NAME		= fractol
SRCS		= ft_julia.c ft_mandelbrot.c main.c parsing.c utils.c ft_color.c ft_mandelbrot_utils.c ft_julia_utils.c
SRCS_BONUS	= main_bonus.c parsing_bonus.c ft_color_bonus.c ft_mandelbrot_utils_bonus.c ft_mandelbrot_bonus.c ft_julia_bonus.c ft_julia_utils_bonus.c multibulb_bonus.c multibulb_utils_bonus.c burning_ship_bonus.c burning_ship_utils_bonus.c utils_bonus.c
CC			= clang
CFLAGS		= -Wall -Werror -Wextra
LIBS		= -Llibft -lft
MATH		= -lm
MLX			= -lmlx -lXext -lX11 -L./minilibx-linux/ -lmlx_Linux
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	make -C ./minilibx-linux
	make -C ./libft
	${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${LIBS} ${MLX} ${MATH} -Ofast 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: ${OBJS_BONUS}
	make -C ./minilibx-linux
	make -C ./libft
	${CC} ${CFLAGS} -o ${NAME} ${SRCS_BONUS} ${LIBS} ${MLX} ${MATH} -Ofast 

clean:
	make clean -C ./minilibx-linux
	make clean -C ./libft
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}

fclean : clean
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re makemlx makelibft bonus re_bonus
