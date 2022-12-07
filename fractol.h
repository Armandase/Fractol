/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:16:04 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 17:13:06 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <X11/X.h>

# define HEIGHT 720
# define WIDTH 1080
# define ESC 65307
# define ITERATION 30
# define M_UP 4
# define M_DOWN 5
# define COLOR 0x660066
# define CENTER_COLOR 0x000000

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*img_addr;
	int		img_width;
	int		img_height;
	int		bits_per_px;
	int		line_len;
	int		endian;
}	t_mlx;
typedef struct s_coo
{
	long double	x;
	long double	y;
	long double	zoom;
	long double	value_x;
	long double	value_y;
	int			mouse_x;
	int			mouse_y;
}	t_coo;
typedef struct s_color
{
	int			iter;
	long double	z;
	int			red;
	int			green;
	int			blue;
}	t_color;
typedef struct s_event
{
	t_coo	*coo;
	t_mlx	*mlx;
}	t_event;
int			parsing(int argc, char **argv);
void		ft_mandelbrot(void);
void		ft_julia(void);
long double	absolute_value(long double z);
void		convert_plan(int x, int y, t_event *event);
void		ft_range(t_color color, t_event *event, int x, int y);
int			mouse_coo(t_event *event);	
int			render(t_event *event);
int			render_julia(t_event *event);
void		ft_log_color(t_color color, t_event *event, int x, int y);
void		ft_bicolor(t_color color, t_event *event, int x, int y);
void		ft_mandel_loop(t_event *event);
void		pixel_img_put(t_event *event, int x, int y, int color);
int			ft_clean_exit(t_event *event);
int			deal_key(int key, t_event *event);
void		pixel_img_put(t_event *event, int x, int y, int color);
int			mouse_hook(int button, int x, int y, t_event *event);
void		ft_bicolor(t_color color, t_event *event, int x, int y);
int			mouse_hook_julia(int button, int x, int y, t_event *event);
void		convert_mouse(t_event *event);

#endif
