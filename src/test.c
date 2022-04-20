/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:29:04 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/20 16:22:21 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

int	deal_key(int key, void *param)
{
	(void) param;
	//(void) key;printf("%d \n", key);
	if (key == 53)
		exit(1);
	return (0);
}

int	deal_mouse(int mouse, void *param)
{
	(void) param;
	if (mouse == 5)
		printf("Salut\n");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
   *(unsigned int*)dst = color;
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		x;
	int		y;

	x = 0;
	y = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 700, "yoyoyooyoyoyo");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_mouse, (void *)0);
	img.img_ptr = mlx_new_image(mlx_ptr, 700, 600);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
	while (x < 701)
	{
		my_mlx_pixel_put(&img, x, y, 0xE3E2B5);
		x++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
