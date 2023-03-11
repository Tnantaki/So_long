/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:46:43 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:46:51 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static t_point	find_position(t_param *par, char character)
{
	t_point	point;

	par->y = 0;
	while (par->y < par->map.height)
	{
		par->x = 0;
		while (par->x < par->map.width)
		{
			if (par->map.cor[par->y][par->x] == character)
			{
				point.y = par->y;
				point.x = par->x;
				return (point);
			}
			par->x++;
		}
		par->y++;
	}
	return ((t_point){0, 0});
}

static void	flood_fill(char **arr, t_point size, t_point codn, t_obj *obj)
{
	if (codn.y >= size.y || codn.y < 0 || codn.x >= size.x || codn.x < 0
		|| (arr[codn.y][codn.x] != '0' && arr[codn.y][codn.x] != 'P'
		&& arr[codn.y][codn.x] != 'C' && arr[codn.y][codn.x] != 'E'))
		return ;
	if (arr[codn.y][codn.x] == '0')
		arr[codn.y][codn.x] = 'F';
	else if (arr[codn.y][codn.x] == 'C')
	{
		obj->c++;
		arr[codn.y][codn.x] = 'c';
	}
	else if (arr[codn.y][codn.x] == 'E')
	{
		obj->e++;
		arr[codn.y][codn.x] = 'e';
	}
	else if (arr[codn.y][codn.x] == 'P')
		arr[codn.y][codn.x] = 'p';
	flood_fill(arr, size, (t_point){codn.y, codn.x + 1}, obj);
	flood_fill(arr, size, (t_point){codn.y, codn.x - 1}, obj);
	flood_fill(arr, size, (t_point){codn.y + 1, codn.x}, obj);
	flood_fill(arr, size, (t_point){codn.y - 1, codn.x}, obj);
}

int	check_surrounding_wall(t_param *par)
{
	int	y;
	int	last_x;
	int	last_y;

	y = 0;
	last_x = par->map.width - 1;
	last_y = par->map.height - 1;
	while (y < par->map.height)
	{
		if (y == 0 || y == last_y)
		{
			if (ft_strlenchr(par->map.cor[y], '1') != par->map.width)
				break ;
		}
		else
		{
			if (par->map.cor[y][0] != '1' || par->map.cor[y][last_x] != '1')
				break ;
		}
		y++;
	}
	if (y == par->map.height)
		return (1);
	return (ft_double_free(par->map.cor), 0);
}

int	check_components(t_param *par, int y, int x)
{
	par->obj = (t_obj){0, 0, 0};
	while (y < par->map.height)
	{
		x = 0;
		while (x < par->map.width)
		{
			if (par->map.cor[y][x] == 'C')
				par->obj.c++;
			else if (par->map.cor[y][x] == 'P')
				par->obj.p++;
			else if (par->map.cor[y][x] == 'E')
				par->obj.e++;
			else if (par->map.cor[y][x] != '1' && par->map.cor[y][x] != '0')
				return (ft_double_free(par->map.cor), 0);
			x++;
		}
		y++;
	}
	if (y == par->map.height && par->obj.c != 0
		&& par->obj.p == 1 && par->obj.e == 1)
		return (1);
	return (ft_double_free(par->map.cor), 0);
}

int	check_valid_path(t_param *par)
{
	t_point	size;

	par->ply = find_position(par, 'P');
	par->ext = find_position(par, 'E');
	size = (t_point){par->map.height, par->map.width};
	par->move = 0;
	par->obj.c = 0;
	par->obj.e = 0;
	flood_fill(par->map.cor, size, par->ply, &par->obj);
	if (par->obj.c > 0 && par->obj.e == 1)
		return (1);
	return (0);
}
