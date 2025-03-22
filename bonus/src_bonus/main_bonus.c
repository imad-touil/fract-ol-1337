/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:13:49 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/22 01:08:43 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

// static int	handel_args(int ac, char **av, t_fract *f)
// {
// 	if (ac != 2)
// 	{
// 		ft_putstr("./fractol burning_ship\n");
// 		return (0);
// 	}
// 	if (!ft_strcmp(av[1], "burning_ship"))
// 	{
// 		f->f_type = av[1];
// 		render_burning(f);
// 	}
// 	else
// 	{
// 		ft_putstr("./fractol burning_ship\n");
// 		return (0);
// 	}
// 	return (1);
// }

void	init_fractol(t_fract *f, char *str)
{
	f->max_i = 2;
	f->max_r = 2.0;
	f->min_i = -2;
	f->min_r = -2.0;
	f->max_iter = MAX_ITER;
	f->f_type = str;
	f->mlx = mlx_init();
	if (!f->mlx)
		print_error_exit(MLX_FAILED);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		print_error_exit(WIN_FAILED);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
		print_error_exit(IMG_FAILED);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.l_len,
			&f->img.endian);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
}
void ll(void)
{
	system("leaks fractol");
}
int	main(int ac, char **av)
{
	t_fract	f;

	atexit(ll);
	if (ac != 2 || ft_strcmp(av[1], "burning_ship"))
	{
		ft_putstr("Usage: ./fractol burning_ship\n");
		return (0);
	}
	init_fractol(&f, av[1]);
	render_burning(&f);
	mlx_key_hook(f.win, keys_handler, &f);
	mlx_mouse_hook(f.win, mouse_scroll, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
