/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:50:29 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 16:24:01 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../Libft/incl/libft.h"
# include <math.h>

# define MENU_WIDTH 300
# define WIN_WIDTH  1920 // 1280
# define WIN_HEIGTH 1080 // 800
# define DEG 0.5239877
# define Z_H 10

# define EXIT_BUTTON 17
# define ESC 53

# define WHITE 0xFFFFFF

typedef struct s_p
{
	int	x;
	int	y;
	int	z;
}	t_p;

typedef struct s_map
{
	t_p	**coord;
	int	x;
	int	y;
	int	z;
}				t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*i_addr;
	int		i_bpp;
	int		i_size_line;
	int		i_endian;
	t_map	*map;
}				t_fdf;

void	deal_hook(t_fdf *a);
void	menu(t_fdf *a);
void	image(t_fdf *a);
void	put_pixel(t_fdf *a, int x, int y, int color);
void	draw_line(t_p p1, t_p p2, int color, t_fdf *a);
void	init_map(t_fdf *a, char *f_path);

#endif
