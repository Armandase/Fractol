/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibulb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:05:33 by adamiens          #+#    #+#             */
/*   Updated: 2022/12/07 16:37:05 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_color	bonus_calcul(t_coo coo)
{
	long double	tmp;
	long double	tmp_x;
	long double	tmp_y;
	t_color		color;
	int			n;

	color.iter = 0;
	color.z = 0;
	tmp_x = 0;
	tmp_y = 0;
	n = coo.bulb;
	while (color.iter < ITERATION && color.z <= 4)
	{
		tmp = pow((tmp_x * tmp_x + tmp_y * tmp_y), (n / n))
			* cos(n * atan2(tmp_y, tmp_x)) + coo.x;
		tmp_y = pow((tmp_x * tmp_x + tmp_y * tmp_y), (n / n))
			* sin(n * atan2(tmp_y, tmp_x)) + coo.y;
		tmp_x = tmp;
		color.z = (pow(tmp_x, n) + pow(tmp_y, n));
		color.z = absolute_value(color.z);
		color.iter += 1;
	}
	return (color);
}

int	render_multi(t_event *event)
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
			color = bonus_calcul(*event->coo);
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

void	ft_multi_loop(t_event *event)
{
	mlx_key_hook(event->mlx->win, bonus_deal_key, event);
	mlx_hook(event->mlx->win,
		DestroyNotify, StructureNotifyMask, ft_clean_exit, event);
	mlx_mouse_hook(event->mlx->win, mouse_multi_hook, event);
	render_multi(event);
	mlx_loop(event->mlx->init);
	ft_clean_exit(event);
}

void	ft_multibulb(void)
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
	ft_init_value(event);
	event->mlx->init = mlx_init();
	if (event->mlx->init == NULL)
		ft_clean_exit(event);
	event->mlx->win = mlx_new_window
		(event->mlx->init, WIDTH, HEIGHT, "Multibulb");
	if (event->mlx->win == NULL)
		ft_clean_exit(event);
	event->mlx->img = mlx_new_image(event->mlx->init, WIDTH, HEIGHT);
	event->mlx->img_addr = mlx_get_data_addr
		(event->mlx->img, &(event->mlx->bits_per_px),
			&(event->mlx->line_len), &(event->mlx->endian));
	ft_multi_loop(event);
}
