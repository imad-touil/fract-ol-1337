/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:53:16 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/20 02:15:13 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == max_iter)
		return (0x000000);
	t = (double)iteration / max_iter;
	r = (int)(6 * (1 - t) * t * t * t * 255);
	g = (int)(12 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r * 65536 + g * 256 + b);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	print_error_exit(char *msg, int key, t_fract *f)
{
	ft_putstr(msg);
	if (key)
		free(f->mlx);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
