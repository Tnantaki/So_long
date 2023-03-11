#include "../includes/solong.h"

// void	set_image(t_param *par)
// {
// 	par->img.o_exit = my_put_xpm2img(par, IMG_O_EXT);
// 	par->img.c_exit = my_put_xpm2img(par, IMG_C_EXT);
// 	par->img.ply_dor = my_put_xpm2img(par, IMG_PLY_DOR);
// 	par->img.player = my_put_xpm2img(par, IMG_PLY);
// 	par->img.collec = my_put_xpm2img(par, IMG_COL);
// 	par->img.space = my_put_xpm2img(par, IMG_SPC);
// }

void	*my_put_xpm2img(t_param *par, char *filename)
{
	return (mlx_xpm_file_to_image(par->mlx, filename, &par->w, &par->h));
}

void	my_put_img2win(t_param *par, void *img, int y, int x)
{
	mlx_put_image_to_window(par->mlx, par->win, img, x * IMG_PIX, y * IMG_PIX);
}

int	close_win(t_param *par)
{
	mlx_destroy_image(par->mlx, par->img.wall);
	mlx_destroy_image(par->mlx, par->img.space);
	mlx_destroy_window(par->mlx, par->win);
	mlx_destroy_display(par->mlx);
	free(par->mlx);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		close_win(par);
	return (0);
}

void	init_window(t_param *par)
{
	par->mlx = mlx_init();
	if (par->mlx == NULL)
		exit(1);
	par->win = mlx_new_window(par->mlx, 1000,
			1000, "Solong");
	if (par->win == NULL)
	{
		mlx_destroy_display(par->mlx);
		free(par->mlx);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_param	par;

	init_window(&par);
	mlx_key_hook(par.win, key_hook, &par);
	par.img.wall = my_put_xpm2img(&par, IMG_WAL);
	par.img.space = my_put_xpm2img(&par, IMG_SPC);
	my_put_img2win(&par, par.img.wall, 0, 0);
	my_put_img2win(&par, par.img.wall, 1, 1);
	my_put_img2win(&par, par.img.space, 1, 1);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
	// free(par.mlx);
}
	// mlx_loop_hook(par.mlx, render_next_frame, &par);
