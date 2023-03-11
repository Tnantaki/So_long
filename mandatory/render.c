/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:05 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_map(t_param *par, int y, int x)
{
	while (y < par->map.height)
	{
		x = 0;
		while (x < par->map.width)
		{
			if (par->map.cor[y][x] == '1')
				my_put_img2win(par, par->img.wall, y, x);
			else if (par->map.cor[y][x] == 'F' || par->map.cor[y][x] == '0')
				my_put_img2win(par, par->img.space, y, x);
			else if (par->map.cor[y][x] == 'e')
				my_put_img2win(par, par->img.c_exit, y, x);
			else if (par->map.cor[y][x] == 'c' || par->map.cor[y][x] == 'C')
				my_put_img2win(par, par->img.collec, y, x);
			else if (par->map.cor[y][x] == 'p')
				my_put_img2win(par, par->img.player, y, x);
			x++;
		}
		y++;
	}
	par->map.cor[par->ply.y][par->ply.x] = 'F';
}

static void	replace_past(t_param *par)
{
	if (par->map.cor[par->ply.y][par->ply.x] == 'e')
		my_put_img2win(par, par->img.c_exit, par->ply.y, par->ply.x);
	else
		my_put_img2win(par, par->img.space, par->ply.y, par->ply.x);
}

static void	move_forward(t_param *par)
{
	if (par->map.cor[par->ply.y][par->ply.x] == 'F')
		my_put_img2win(par, par->img.player, par->ply.y, par->ply.x);
	else if (par->map.cor[par->ply.y][par->ply.x] == 'c')
	{
		par->obj.c--;
		par->map.cor[par->ply.y][par->ply.x] = 'F';
		my_put_img2win(par, par->img.player, par->ply.y, par->ply.x);
	}
	else if (par->map.cor[par->ply.y][par->ply.x] == 'e' && par->obj.c)
		my_put_img2win(par, par->img.ply_dor, par->ply.y, par->ply.x);
	else if (par->map.cor[par->ply.y][par->ply.x] == 'e' && !(par->obj.c))
		close_win(par);
	if (par->obj.c == 0)
		my_put_img2win(par, par->img.o_exit, par->ext.y, par->ext.x);
	par->move++;
}

void	move_player(t_param *par, int y, int x)
{
	if (par->map.cor[par->ply.y + y][par->ply.x + x] == '1')
		return ;
	replace_past(par);
	par->ply.y += y;
	par->ply.x += x;
	move_forward(par);
	ft_putstr_fd("Movment:", 1);
	ft_putnbr_fd(par->move, 1);
	ft_putstr_fd("\n", 1);
}
