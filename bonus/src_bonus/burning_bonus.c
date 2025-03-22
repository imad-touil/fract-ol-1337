/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:49:04 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/16 11:38:58 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

int	burning_ship(double real, double imaginary, int max_iter)
{
	double	z_real;
	double	z_imag;
	double	z_rtmp;
	double	z_itmp;
	int		iter;

	z_real = 0;
	z_imag = 0;
	z_rtmp = 0;
	z_itmp = 0;
	iter = 0;
	while (iter < max_iter)
	{
		z_rtmp = z_real * z_real;
		z_itmp = z_imag * z_imag;
		if (z_rtmp + z_itmp > 4.0)
			break ;
		z_imag = -fabs(2 * z_real * z_imag) + imaginary;
		z_real = fabs(z_rtmp - z_itmp + real);
		iter++;
	}
	return (iter);
}

void	render_burning(t_fract *f)
{
	double	real;
	double	imaginary;
	int		x;
	int		y;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = f->min_r + (double)x / WIDTH * (f->max_r
					- f->min_r) + f->offset_x;
			imaginary = f->max_i - (double)y / HEIGHT * (f->max_i
					- f->min_i) + f->offset_y;
			iter = burning_ship(real, imaginary, f->max_iter);
			put_pixel(&f->img, x, y, get_color(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
