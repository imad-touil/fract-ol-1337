/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:52:53 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/19 15:58:08 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_fract *f, double real, double imaginary)
{
	double	z_real;
	double	z_imaginary;
	double	z_rtmp;
	double	z_itmp;
	int		iter;

	z_real = real;
	z_imaginary = imaginary;
	iter = 0;
	while (iter < f->max_iter)
	{
		z_rtmp = z_real * z_real;
		z_itmp = z_imaginary * z_imaginary;
		if (z_rtmp + z_itmp > 4.0)
			break ;
		z_imaginary = 2 * z_real * z_imaginary + f->c_imaginary;
		z_real = z_rtmp - z_itmp + f->c_real;
		iter++;
	}
	return (iter);
}

void	render_julia(t_fract *f)
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
			imaginary = f->max_i - (double)y / HEIGHT
				* (f->max_i - f->min_i) - f->offset_y;
			iter = julia(f, real, imaginary);
			put_pixel(&f->img, x, y, get_color(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
