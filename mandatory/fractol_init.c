/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:27:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/08 02:47:24 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	malloc_error(void)
{
	perror("Problems With malloc");
	exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		malloc_error(); // TODO
	f->mlx_wind = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->title);
	if (!f->mlx_wind)
	{
		mlx_destroy_window(f->mlx, f->mlx_wind);
		free(f->mlx);
		malloc_error();
	}
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
	{
		mlx_destroy_image(f->mlx, f->img.img);
		mlx_destroy_window(f->mlx, f->mlx_wind);
		free(f->mlx);
		malloc_error();
	}
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.l_len, &f->img.endian);
	// event_init(f); // TODO
	// data_init(f); // TODO
}
