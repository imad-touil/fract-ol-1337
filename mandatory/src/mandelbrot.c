/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:32:22 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/20 22:21:51 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandel(double real, double imaginary, int max_iter)
{
	double	z_r;
	double	z_i;
	double	z_rtemp;
	double	z_itemp;
	int		iter;

	z_r = 0;
	z_i = 0;
	iter = 0;
	while (iter < max_iter)
	{
		z_rtemp = z_r * z_r;
		z_itemp = z_i * z_i;
		if (z_rtemp + z_itemp > 4.0)
			break ;
		z_i = 2 * z_r * z_i + imaginary;
		z_r = z_rtemp - z_itemp + real;
		iter++;
	}
	return (iter);
}

void	render_mandel(t_fract *f)
{
	int		x;
	int		y;
	int		iter;
	double	real;
	double	imaginary;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = f->min_r + (double)x / WIDTH
				* (f->max_r - f->min_r) + f->offset_x;
			imaginary = f->min_i + (double)y / HEIGHT
				* (f->max_i - f->min_i) + f->offset_y;
			iter = mandel(real, imaginary, f->max_iter);
			put_pixel(&f->img, x, y, get_color(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
