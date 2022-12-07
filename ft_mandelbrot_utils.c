/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:19:51 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 16:18:39 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_event *event)
{
	if (key == ESC)
		mlx_loop_end(event->mlx->init);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_event *event)
{
	(void)x;
	(void)y;
	if (button == M_DOWN)
	{
		event->coo->zoom /= 0.9;
		render(event);
	}
	if (button == M_UP)
	{
		event->coo->zoom *= 0.9;
		render(event);
	}
	return (1);
}
