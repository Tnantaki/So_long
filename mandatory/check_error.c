/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:46:32 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:46:37 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_files(char *mapfile)
{
	int	i;
	int	j;

	if (!mapfile)
		return (0);
	i = 0;
	j = (int)ft_strlen(mapfile) - 4;
	if (j < 0)
		return (0);
	while (mapfile[j])
	{
		if (mapfile[j++] != ".ber"[i++])
			return (0);
	}
	if (mapfile[j] == '\0')
		return (1);
	return (0);
}

int	check_rectangular(t_param *par, char *mapfile, int fd)
{
	par->map.height = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		ft_prterr(3);
	while (1)
	{
		par->map.line = get_next_line(fd);
		if (!par->map.line)
		{
			close(fd);
			return (1);
		}
		if (par->map.height == 0)
			par->map.width = ft_gnl_len(par->map.line);
		else if (par->map.width != ft_gnl_len(par->map.line))
			break ;
		free(par->map.line);
		par->map.height++;
	}
	free(par->map.line);
	close(fd);
	return (0);
}

int	load_map(t_param *par, char *mapfile, int fd, int i)
{
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		ft_prterr(3);
	par->map.cor = malloc(sizeof(char *) * (par->map.height + 1));
	if (!par->map.cor)
		return (0);
	while (i < par->map.height)
	{
		par->map.line = get_next_line(fd);
		if (!par->map.line)
			break ;
		par->map.line[par->map.width] = '\0';
		par->map.cor[i] = ft_strdup(par->map.line);
		free(par->map.line);
		if (!(par->map.cor[i]))
			break ;
		i++;
	}
	if (i == par->map.height)
		return (par->map.cor[i] = NULL, 1);
	close(fd);
	ft_free_err_doubleptr(par->map.cor, i);
	return (0);
}

void	check_error(t_param *par, int ac, char **av)
{
	int		fd;
	char	*mapfile;

	fd = 0;
	if (ac != 2)
		ft_prterr(1);
	mapfile = av[1];
	if (check_files(mapfile) != 1)
		ft_prterr(2);
	if (check_rectangular(par, mapfile, fd) != 1)
		ft_prterr(4);
	if (load_map(par, mapfile, fd, 0) != 1)
		exit(1);
	if (check_surrounding_wall(par) != 1)
		ft_prterr(5);
	if (check_components(par, 0, 0) != 1)
		ft_prterr(6);
	if (check_valid_path(par) != 1)
		ft_prterr(7);
}
