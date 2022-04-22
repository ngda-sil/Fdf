/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:50:29 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/22 12:26:52 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../Libft/incl/libft.h"
# include <math.h>

# define MENU_WIDTH 300
# define WIN_WIDTH 1920
# define WIN_HEIGTH 1080

# define EXIT_BUTTON 17
# define ESC 53

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*i_addr;
	int		i_bpp;
	int		i_size_line;
	int		i_endian;
}				t_fdf;

void	deal_hook(t_fdf *a);
void	menu(t_fdf *a);
void	image(t_fdf *a);
void	put_pixel(t_fdf *a, int x, int y, int color);
void	draw_line(int x1, int y1, int x2, int y2, int color, t_fdf *a);

#endif
