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
	if (!ptr)
		return (NULL);
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
	if (!ptr)
		return ;
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
		ft_putstr_fd(ERR_ARG, 1);
	else if (err == 2)
		ft_putstr_fd(ERR_FLE, 1);
	else if (err == 3)
		ft_putstr_fd(ERR_MAP_OPN, 1);
	else if (err == 4)
		ft_putstr_fd(ERR_MAP_REC, 1);
	else if (err == 5)
		ft_putstr_fd(ERR_MAP_WAL, 1);
	else if (err == 6)
		ft_putstr_fd(ERR_MAP_COM, 1);
	else if (err == 7)
		ft_putstr_fd(ERR_MAP_PATH, 1);
	exit (0);
}
