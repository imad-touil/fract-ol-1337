/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:23:04 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:25:25 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_fractal *f)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->offset_y;
			if (f->fractal_type == 1)
				iter = mandelbrot(c, f->max_iter);
			else if (f->fractal_type == 2)
				iter = julia(c, f->julia_c, f->max_iter);
			else if (f->fractal_type == 3)
				iter = burning_ship(c, f->max_iter);
			color = create_trgb(0, iter % 255, iter % 255, iter % 255);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
