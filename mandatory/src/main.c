/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:30:03 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/21 03:52:26 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_fract *f)
{
	f->max_r = 2.0;
	f->max_i = 2.0;
	f->min_r = -2.0;
	f->min_i = -2.0;
	f->max_iter = MAX_ITER;
	f->mlx = mlx_init();
	if (!f->mlx)
		print_error_exit(MLX_FAILED, 0, f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		print_error_exit(WIN_FAILED, 1, f);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
	{
		mlx_destroy_window(f->mlx, f->win);
		print_error_exit(IMG_FAILED, 1, f);
	}
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.l_len, &f->img.endian);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
}

static int	valid_julia_args(int ac, char **av, t_fract *f)
{
	if (ac == 4)
	{
		f->c_real = ft_atof(av[2]);
		f->c_imaginary = ft_atof(av[3]);
		if (f->c_imaginary < -2.0 || f->c_imaginary > 2.0
			|| f->c_real < -2.0 || f->c_real > 2.0)
		{
			ft_putstr("Invalid Args\n");
			return (0);
		}
		return (1);
	}
	ft_putstr(USAGE_MSGE);
	return (0);
}

static int	valid_args(int ac, char **av, t_fract *f)
{
	if (ac < 2)
	{
		ft_putstr(USAGE_MSGE);
		return (0);
	}
	if (!ft_strcmp(av[1], "Mandelbrot") && ac == 2)
		return (1);
	else if (!ft_strcmp(av[1], "Julia"))
	{
		if (!valid_julia_args(ac, av, f))
			return (0);
		return (1);
	}
	else
	{
		ft_putstr(USAGE_MSGE);
		return (0);
	}
	return (1);
}
void ll(void)
{
	system("leaks fractol");
}
int	main(int ac, char **av)
{
	t_fract	f;

	atexit(ll);
	if (!valid_args(ac, av, &f))
		return (0);
	init_fractol(&f);
	if (!ft_strcmp(av[1], "Mandelbrot"))
		render_mandel(&f);
	else if (!ft_strcmp(av[1], "Julia"))
		render_julia(&f);
	mlx_key_hook(f.win, keys_handler, &f);
	mlx_mouse_hook(f.win, mouse_scroll, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
}




// leaks ; bonus ; atof  == >> 12abc