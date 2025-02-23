/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:27:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/23 13:12:29 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_error(void)
{
	perror("malloc eroor\n");
	exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *f)
{
	f -> mlx = mlx_init();
	if (f -> mlx == NULL)
		print_error();
	f -> mlx_win = mlx_new_window(f -> mlx, WIDTH, HEIGHT, f -> name);
	if (f -> mlx_win == NULL)
	{
		mlx_destroy_window(f -> mlx, f -> mlx_win);
		free(f -> mlx);
		print_error();
	}
	f -> img.img_p = mlx_new_image(f -> mlx, WIDTH, HEIGHT);
	if (f -> img.img_p == NULL)
	{
		mlx_destroy_image(f ->mlx, f -> img.img_p);
		mlx_destroy_window(f -> mlx, f -> mlx_win);
		free(f -> mlx);
		print_error();
	}
	f -> img.pix_p = mlx_get_data_addr(f->img.img_p, &f->img.bit_per_pix,
			&f->img.line_len, &f->img.endian);
	mlx_loop(f -> mlx);
}
