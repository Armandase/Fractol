/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:18:09 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 17:06:02 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_color	bs_calcul(t_coo coo)
{
	long double	tmp;
	long double	tmp_x;
	long double	tmp_y;
	t_color		color;

	color.iter = 0;
	color.z = 0;
	tmp_x = 0;
	tmp_y = 0;
	while (color.iter < ITERATION && color.z <= 10)
	{
		tmp = tmp_x * tmp_x - tmp_y * tmp_y + coo.x;
		tmp_y = 2 * tmp_x * tmp_y + coo.y;
		tmp_x = tmp;
		tmp_x = absolute_value(tmp_x);
		tmp_y = absolute_value(tmp_y);
		color.z = (tmp_x * tmp_x + tmp_y * tmp_y);
		color.z = absolute_value(color.z);
		color.iter++;
	}
	if (color.iter == ITERATION)
		return (color);
	else
		return (color);
}

int	bs_render(t_event *event)
{
	int		x;
	int		y;
	t_color	color;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			convert_plan(x, y, event);
			color = bs_calcul(*event->coo);
			if (color.iter == ITERATION)
				pixel_img_put(event, x, y, CENTER_COLOR);
			else
				put_color(color, event, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window
		(event->mlx->init, event->mlx->win, event->mlx->img, 0, 0);
	return (0);
}

void	ft_bs_loop(t_event *event)
{
	mlx_key_hook(event->mlx->win, bs_deal_key, event);
	mlx_hook(event->mlx->win,
		DestroyNotify, StructureNotifyMask, ft_clean_exit, event);
	mlx_mouse_hook(event->mlx->win, bs_mouse_hook, event);
	bs_render(event);
	mlx_loop(event->mlx->init);
	ft_clean_exit(event);
}

void	ft_bs(void)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!event)
		exit(1);
	(event->coo) = malloc(sizeof(t_coo));
	if (!event->coo)
		ft_clean_exit(event);
	(event->mlx) = malloc(sizeof(t_mlx));
	if (!event->mlx)
		ft_clean_exit(event);
	event->mlx->init = mlx_init();
	if (event->mlx->init == NULL)
		ft_clean_exit(event);
	event->mlx->win = mlx_new_window
		(event->mlx->init, WIDTH, HEIGHT, "Mandelbrot");
	if (event->mlx->win == NULL)
		ft_clean_exit(event);
	event->mlx->img = mlx_new_image(event->mlx->init, WIDTH, HEIGHT);
	event->mlx->img_addr = mlx_get_data_addr
		(event->mlx->img, &(event->mlx->bits_per_px),
			&(event->mlx->line_len), &(event->mlx->endian));
	ft_init_bs(event);
	ft_bs_loop(event);
}
