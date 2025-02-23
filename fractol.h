/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:41:21 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/23 12:37:27 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_complex
{
	double	real;
	double	imagi;
}	t_complex;

// typedef struct s_mlx
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*mlx_img;
// }	t_mlx;

typedef struct s_img
{
	void	*img_p;
	char	*pix_p;
	int		bit_per_pix;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	// MLX
	void	*mlx;
	void	*mlx_win;
	char	*name;
	// IMAGE
	t_img	img;
	// Hooks
	
}			t_fractol;

t_complex	complex_square(t_complex z);
t_complex	complex_add(t_complex z1, t_complex z2);
double		complex_magnitude(t_complex z);
// **************************************************
void		ft_putendl_fd(const char *str, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *str);
void		fractol_init(t_fractol *f);
void		print_error(void);

#endif
