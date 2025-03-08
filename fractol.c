/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:46:10 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/23 16:49:01 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*f;

	f = malloc(sizeof(t_data));
	if (!f)
		ft_putendl_fd("Write Some Code here", 1);
	if ((ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "Julia", 5)))
	{
		f->title = av[1];
		fractol_init(f);
		write(1, "Well Done!\n", 10);
		mlx_loop(f->mlx);
	}
	else
	{
		ft_putendl_fd(ERROR_MSG, 1);
		exit(EXIT_FAILURE);
	}
}
