/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:50:29 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/10 20:59:26 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../Libft/incl/libft.h"
# include <math.h>

# define BLUE 0x81D2C7
# define DEG 0.5239877
# define WIN_HEIGTH 1080 // 800
# define WIN_WIDTH  1920 // 1280

# define DOWN 124
# define ESC 53
# define EXIT_BUTTON 17
# define LEFT 126
# define RIGHT 125
# define SCROLL_DWN 4
# define SCROLL_UP 5
# define UP 123
# define Z_DWN 78
# define Z_UP 69

typedef struct s_p
{
	int	x;
	int	y;
	int	z;
}	t_p;

typedef struct s_draw
{
	int	x;
	int	y;
	int	sx;
	int	sy;
	int	counter;
	int	e;
}	t_draw;

typedef struct s_map
{
	t_p		**coord;
	t_p		**iso;
	int		x;
	int		y;
	int		z;
	int		x0;
	int		y0;
	int		z_unit;
	int		unit;
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
	t_map	map;
}				t_fdf;

void	deal_hook(t_fdf *a);
void	draw_line(t_p p1, t_p p2, t_fdf *a);
void	ft_double_free_tp(t_p **tab);
void	ft_exit_free(char *s, t_fdf *a);
void	ft_exit_simple(char *s);
void	image(t_fdf *a);
void	init_map(t_fdf *a, char *f_path);

#endif
