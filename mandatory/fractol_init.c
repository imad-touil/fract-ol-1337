/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:27:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/24 15:19:54 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractol_init(t_data *f)
{
	f->mlx = mlx_init();
	if (!f-> mlx)
		write(1, "TODO: write faunction that handle this", 37); // Free windo and images and exit 
	f -> win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->title);
	if (!f->win)
		write(1, "TODO: write faunction that handle this\n", 37);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		write(1, "TODO: write faunction that handle this\n", 37);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->l_len, &f->endian);
	// event_init(f); //TODO
	// data_init(f); //TODO
}
