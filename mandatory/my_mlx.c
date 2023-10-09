/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:31 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:33 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	*my_put_xpm2img(t_param *par, char *filename)
{
	return (mlx_xpm_file_to_image(par->mlx, filename, &par->w, &par->h));
}

void	my_put_img2win(t_param *par, void *img, int y, int x)
{
	mlx_put_image_to_window(par->mlx, par->win, img, x * IMG_PIX, y * IMG_PIX);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		close_win(par);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(par, -1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(par, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(par, 1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(par, 0, 1);
	return (0);
}
