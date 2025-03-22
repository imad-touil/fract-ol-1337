/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:17:04 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/09 03:19:15 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4.0)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		iter++;
	}
	return (iter);
}
