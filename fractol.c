/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:46:10 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/23 12:37:01 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*f;

	if ((ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "Julia", 5)))
	{
		f = malloc(sizeof(t_fractol));
		if (!f)
			print_error();
		f -> name = av[1];
		fractol_init(f);
		// fractol_events(&f);
		// fractol_life(&f);
		write(1, "Funny\n", 5);
	}
	else
	{
		ft_putendl_fd("Make Sure To Enter A valid Args", 1);
		exit(EXIT_FAILURE);
	}
}
// TODO recode ft_putstr with putendl_fd()