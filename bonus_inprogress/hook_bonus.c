#include "../includes/solong.h"

int	close_win(t_param *par)
{
	mlx_destroy_window(par->mlx, par->win);
	free(par->mlx);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		close_win(par);
	// else if (keycode == KEY_W || keycode == KEY_UP)
	// 	move_player(par, -1, 0);
	// else if (keycode == KEY_A || keycode == KEY_LEFT)
	// 	move_player(par, 0, -1);
	// else if (keycode == KEY_S || keycode == KEY_DOWN)
	// 	move_player(par, 1, 0);
	// else if (keycode == KEY_D || keycode == KEY_RIGHT)
	// 	move_player(par, 0, 1);
	return (0);
}

// int	mouse_hook(int keycode, t_param *par)
// {
// 	(void)par;
// 	printf("%d\n", keycode);
// 	return (0);
// }
