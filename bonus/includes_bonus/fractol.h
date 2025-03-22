/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:33:37 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:38:20 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define ZOOM 1.0
# define ERROR_MSSG "Invalid fractal type. Use:\
 mandelbrot, julia, burning_ship\n"

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			fractal_type;
	t_complex	julia_c;
}				t_fractal;

// Function prototypes
int		mandelbrot(t_complex c, int max_iter);
int		julia(t_complex z, t_complex c, int max_iter);
int		burning_ship(t_complex c, int max_iter);
void	draw_fractal(t_fractal *f);
void	init_fractal(t_fractal *f, char *fractal_type);
int		handle_key(int keycode, t_fractal *f);
int		handle_mouse(int button, int x, int y, t_fractal *f);
void	put_pixel(t_fractal *f, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

#endif