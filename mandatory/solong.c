/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:47:09 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 18:47:11 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	set_image(t_param *par)
{
	par->img.player = my_put_xpm2img(par, IMG_PLY);
	par->img.wall = my_put_xpm2img(par, IMG_WAL);
	par->img.space = my_put_xpm2img(par, IMG_SPC);
	par->img.collec = my_put_xpm2img(par, IMG_COL);
	par->img.o_exit = my_put_xpm2img(par, IMG_O_EXT);
	par->img.c_exit = my_put_xpm2img(par, IMG_C_EXT);
	par->img.ply_dor = my_put_xpm2img(par, IMG_PLY_DOR);
}

int	main(int ac, char **av)
{
	t_param	par;

	check_error(&par, ac, av);
	init_window(&par);
	set_image(&par);
	render_map(&par, 0, 0);
	mlx_key_hook(par.win, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
}
