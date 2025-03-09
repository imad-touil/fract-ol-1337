/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:19:27 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:29:32 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2)
	{
		write(1, "Usage: ./fractol <fractal_type>\n", 32);
		write(1, "Available fractals: mandelbrot, julia, burning_ship\n", 52);
		return (1);
	}
	init_fractal(&f, argv[1]);
	draw_fractal(&f);
	mlx_hook(f.win, 2, 1L << 0, handle_key, &f);
	mlx_hook(f.win, 4, 1L << 2, handle_mouse, &f);
	mlx_loop(f.mlx);
	return (0);
}
