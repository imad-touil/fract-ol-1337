/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:51:32 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/21 03:00:13 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	render_fractol(t_fract *f)
{
	if (!ft_strcmp(f->f_type, "burning_ship"))
		render_burning(f);
}

int	close_window(t_fract *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
}

int	keys_handler(int key_code, t_fract *f)
{
	if (key_code == 53)
		close_window(f);
	else if (key_code == 69)
		f->max_iter += 10;
	else if (key_code == 78)
	{
		f->max_iter -= 10;
		if (f->max_iter < 10)
			f->max_iter = 10;
	}
	else if (key_code == 124)
		f->offset_x -= 0.05 * f->zoom;
	else if (key_code == 126)
		f->offset_y -= 0.05 * f->zoom;
	else if (key_code == 123)
		f->offset_x += 0.05 * f->zoom;
	else if (key_code == 125)
		f->offset_y += 0.05 * f->zoom;
	render_fractol(f);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_fract *f)
{
	double	zoom_factor;
	double	center_r;
	double	center_i;

	// y = (double)x;
	if (button == 5)
		zoom_factor = 1.0 / ZOOM_FACTOR;
	else if (button == 4)
		zoom_factor = ZOOM_FACTOR;
	else
		return (0);
	center_r = f->min_r + (double)x / WIDTH * (f->max_r - f->min_r);
	center_i = f->max_i - (double)y / HEIGHT * (f->max_i - f->min_i);
	f->min_r = center_r + (f->min_r - center_r) * zoom_factor;
	f->max_r = center_r + (f->max_r - center_r) * zoom_factor;
	f->min_i = center_i + (f->min_i - center_i) * zoom_factor;
	f->max_i = center_i + (f->max_i - center_i) * zoom_factor;
	f->zoom *= zoom_factor;
	render_fractol(f);
	return (0);
}
