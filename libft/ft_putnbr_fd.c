/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:50:42 by tnantaki          #+#    #+#             */
/*   Updated: 2022/09/13 17:42:54 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	nbr[12];

	i = -1;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		nbr[++i] = (n % 10) + '0';
		n /= 10;
	}
	while (i >= 0)
		write(fd, &nbr[i--], 1);
}
