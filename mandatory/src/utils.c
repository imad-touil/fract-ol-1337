/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:25:47 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:28:35 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_fractal *f, char *fractal_type)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = MAX_ITER;
	if (strcmp(fractal_type, "mandelbrot") == 0)
		f->fractal_type = 1;
	else if (strcmp(fractal_type, "julia") == 0)
		f->fractal_type = 2;
	else if (strcmp(fractal_type, "burning_ship") == 0)
		f->fractal_type = 3;
	else
	{
		write(1, ERROR_MSSG, 55);
		exit(1);
	}
	if (f->fractal_type == 2)
	{
		f->julia_c.real = -0.7;
		f->julia_c.imag = 0.27015;
	}
}

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
