/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:03:42 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/11 21:04:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# if defined(__linux__)
#  include "keycode_linux.h"
# else
#  include "keycode_macos.h"
# endif

//image resolution
# define IMG_PIX 128
//image path
# define IMG_O_EXT "textures/exit/open_door0.xpm"
# define IMG_C_EXT "textures/exit/close_door0.xpm"
# define IMG_PLY_DOR "textures/player/cat_on_door0.xpm"
# define IMG_PLY "textures/player/cat_on_grass0.xpm"
# define IMG_SPC "textures/space/grass0.xpm"
# define IMG_WAL "textures/wall/wall0.xpm"
# define IMG_COL "textures/collectible/fish_on_grass0.xpm"
//error message
# define ERR_ARG "The Program take only one map file argument.\n"
# define ERR_FLE "Filename extension of map must be \".ber\".\n"
# define ERR_MAP_OPN "Can't open map file.\n"
# define ERR_MAP_REC "The map must be rectangular.\n"
# define ERR_MAP_WAL "The map must be closed/surounding by walls.\n"
# define ERR_MAP_COM "The map must contain 1 player, 1 exit, 1 collectible.\n"
# define ERR_MAP_PATH "It's not valid path in the map\n"

//flood fill
typedef struct s_point
{
	int	y;
	int	x;
}	t_point;
//image
typedef struct s_img
{
	void	*o_exit;
	void	*c_exit;
	void	*ply_dor;
	void	*collec;
	void	*player;
	void	*wall;
	void	*space;
}	t_img;
//map
typedef struct s_map
{
	char	*line;
	char	**cor;
	int		width;
	int		height;
}	t_map;
//obj
typedef struct s_obj
{
	int	c;
	int	p;
	int	e;
}	t_obj;
//mlx
typedef struct s_param
{
	t_img	img;
	t_map	map;
	t_obj	obj;
	t_point	ply;
	t_point	ext;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		w;
	int		h;
	int		move;
}	t_param;

//check error
int		check_files(char *mapfile);
int		check_rectangular(t_param *par, char *mapfile, int fd);
int		load_map(t_param *par, char *mapfile, int fd, int i);
void	check_error(t_param *par, int ac, char **av);
//check map
int		check_surrounding_wall(t_param *par);
int		check_components(t_param *par, int y, int x);
int		check_valid_path(t_param *par);
//render
void	render_map(t_param *par, int y, int x);
void	move_player(t_param *par, int y, int x);
//my mlx
void	*my_put_xpm2img(t_param *par, char *filename);
void	my_put_img2win(t_param *par, void *img, int y, int x);
int		key_hook(int keycode, t_param *par);
//utils
int		ft_strlenchr(const char *str, int c);
int		ft_gnl_len(const char *str);
void	ft_double_free(char **ptr);
char	**ft_free_err_doubleptr(char **ptr, int i);
void	ft_prterr(int err);
//mlx os
void	init_window(t_param *par);
int		close_win(t_param *par);

#endif
