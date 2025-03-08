/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:41:21 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/23 16:52:19 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
// # define MAX_ITER 100
# define ERROR_MSG "Please Enter\n./fractol <Mandelbrot>\n\
or\n./fractol <Julia> <value1> <value2>\n"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	char	*title;
}			t_data;

void	ft_putendl_fd(const char *str, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	fractol_init(t_data *f);

#endif
