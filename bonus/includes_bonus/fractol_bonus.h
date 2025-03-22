/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:20:22 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/22 01:08:16 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define ZOOM_FACTOR 1.1

# define MLX_FAILED "MiniLibX initialization failed\n"
# define WIN_FAILED "Windows creation failed\n"
# define IMG_FAILED "image initializeed failed\n"
# define USAGE_MSGE "Usage: ./fractol Mandelbrot\n\
./fractol Julia [width] [height]\n"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;	
	int		endian;
}			t_data;

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	t_data	img;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	int		max_iter;
	double	zoom;
	double	offset_x;
	double	offset_y;
	char	*f_type;
	double	c_real;
	double	c_imaginary;
}			t_fract;

void	ft_putstr(char *str);
void	print_error_exit(char *msg);
void	init_fractol(t_fract *f, char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	render_burning(t_fract *f);
int		burning_ship(double real, double imaginary, int max_iter);
int		get_color(int iteration, int max_iter);
void	put_pixel(t_data *img, int x, int y, int color);

double	ft_atof(char *str);
int		keys_handler(int key_code, t_fract *f);
int		mouse_scroll(int button, int x, int y, t_fract *f);
int		close_window(t_fract *f);

#endif