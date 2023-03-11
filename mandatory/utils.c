/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:14 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:15 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	ft_strlenchr(const char *str, int c)
{
	int		i;
	char	care;

	if (!str)
		return (0);
	i = 0;
	care = (char)c;
	while (str[i] == care)
		i++;
	return (i);
}

int	ft_gnl_len(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\r' || str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	**ft_free_err_doubleptr(char **ptr, int i)
{
	i--;
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

void	ft_double_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
}

void	ft_prterr(int err)
{
	if (err == 1)
		ft_putstr_fd("The Program take only one map file argument.\n", 1);
	else if (err == 2)
		ft_putstr_fd("Filename extension of map must be \".ber\".\n", 1);
	else if (err == 3)
		ft_putstr_fd("Can't open map file.\n", 1);
	else if (err == 4)
		ft_putstr_fd("The map must be rectangular.\n", 1);
	else if (err == 5)
		ft_putstr_fd("The map must be closed/surounding by walls.\n", 1);
	else if (err == 6)
		ft_putstr_fd("The map must contain 1 player, 1 exit and \
		at least 1 collectible.\n", 1);
	else if (err == 7)
		ft_putstr_fd("It's not valid path in the map\n", 1);
	exit (0);
}
