/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:50:56 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 15:55:14 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook_julia(int button, int x, int y, t_event *event)
{
	(void)x;
	(void)y;
	if (button == M_DOWN)
	{
		event->coo->zoom /= 0.9;
		render_julia(event);
	}
	if (button == M_UP)
	{
		event->coo->zoom *= 0.9;
		render_julia(event);
	}
	return (1);
}

void	convert_mouse(t_event *event)
{
	long double	pixel_x;
	long double	pixel_y;
	long double	tmp;

	if (WIDTH > HEIGHT)
	{
		pixel_y = 4.0 / HEIGHT;
		pixel_x = pixel_y;
		tmp = pixel_y * (WIDTH / 2 - (HEIGHT / 2));
		event->coo->value_x = pixel_x * event->coo->mouse_x - 2 - tmp;
		event->coo->value_y = pixel_y * event->coo->mouse_y - 2;
	}
	else
	{
		pixel_x = 4.0 / WIDTH;
		pixel_y = pixel_x;
		tmp = pixel_x * (HEIGHT / 2 - (WIDTH / 2));
		event->coo->value_x = pixel_x * event->coo->mouse_x - 2;
		event->coo->value_y = pixel_y * event->coo->mouse_y - 2 - tmp;
	}
}
