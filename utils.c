/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:09:35 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 16:18:36 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_img_put(t_event *event, int x, int y, int color)
{
	char	*px;

	px = event->mlx->img_addr
		+ (y * event->mlx->line_len + x * (event->mlx->bits_per_px / 8));
	*(int *)px = color;
}

long double	absolute_value(long double z)
{
	if (z < 0)
		z *= -1;
	return (z);
}

int	ft_clean_exit(t_event *event)
{
	if (event)
	{
		if (event->mlx)
		{
			if (event->mlx->img)
				mlx_destroy_image(event->mlx->init, event->mlx->img);
			if (event->mlx->win)
				mlx_destroy_window(event->mlx->init, event->mlx->win);
			if (event->mlx->init)
			{
				mlx_destroy_display(event->mlx->init);
				free(event->mlx->init);
			}
			free(event->mlx);
		}
		if (event->coo)
			free(event->coo);
		free(event);
	}
	exit(1);
}
