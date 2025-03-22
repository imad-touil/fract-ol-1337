/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:11:06 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:14:12 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burning_ship(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		temp;

	z.real = 0.0;
	z.imag = 0.0;
	iter = 0;
	while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4.0)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = fabs(2.0 * z.real * z.imag) + c.imag;
		z.real = fabs(temp);
		iter++;
	}
	return (iter);
}
