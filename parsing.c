/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:50:07 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/14 11:23:29 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_msg(void)
{
	ft_printf("usage : fractol [fractals]\n");
	ft_printf(" fractals :\n");
	ft_printf(" --> Mandelbrot\n");
	ft_printf(" --> Julia\n");
}

int	parsing(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error_msg();
		return (0);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		return (1);
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		return (2);
	else
	{
		ft_error_msg();
		return (0);
	}
}
