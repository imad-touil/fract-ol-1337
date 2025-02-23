/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:09:56 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/22 19:39:30 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putendl_fd(const char *str, int fd)
{
	int	i;

	if (!str || fd < 0)
		return ;
	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
	write(fd, "\n", 1);
}
