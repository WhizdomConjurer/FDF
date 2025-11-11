/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:04:45 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 13:04:50 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	x;

	x = 0;
	if (fd >= 0 && s)
	{
		while (s[x] != '\0')
		{
			ft_putchar_fd(s[x], fd);
			x++;
		}
	}
}