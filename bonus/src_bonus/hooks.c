/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:14:36 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:16:34 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == 124)
		f->offset_x += 0.1 / f->zoom;
	else if (keycode == 125)
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == 126)
		f->offset_y -= 0.1 / f->zoom;
	draw_fractal(f);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *f)
{
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom /= 1.1;
	draw_fractal(f);
	x = x + y;
	return (0);
}
