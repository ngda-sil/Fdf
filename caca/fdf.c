/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:29:57 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/21 19:16:19 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
   *(unsigned int*)dst = color;
}

void	tracer_segment(int x1, int y1, int x2, int y2, t_data *data)
{
	int	dx;
	int	dy;
	int	e;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx)
	{
		if (dx > 0)
		{
			if (dy)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							x1++;
							if (x1 == x2)
								break; 
							e -= dy;
							if (e < 0)
							{
								y1++;;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							y1++;
							if (y1 == y2)
								break;
							e -= dx;
							if (e < 0)
							{
								x1++;;
								e += dy;
							}
						}
					}
				}
				else 
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * dx;
						dy *= 2;
						while (1)
						{	
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							x1++;
							if (x1 == x2)
								break;
							e += dy;
							if (e < 0)
							{
								y1--;;
								e += dx;
							}	
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							y1++;
							if (y1 == y2)
								break;
							e +=dx;
							if (e > 0)
							{
								x1++;
								e += dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1 != x2)
				{
					my_mlx_pixel_put(data, x1, y1, 0x741b47);
					x1++;
				}
			}
		}
		else
		{
			if (dy)
			{
				if (dy > 0)
				{
					if ( -dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							x1--;
							if (x1 == x2)
								break;
							e += dy;
							if (e >= 0)
							{
								y1++;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							y1++;
							if (y1 == y2)
								break;
							e += dx;
							if (e <= 0)
							{
								x1--;
								e += dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							x1--;
							if (x1 == x2)
								break;
							e -= dy;
							if (e >= 0)
							{
								y1--;
								e += dx;
							}
						}
					}
					else 
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							my_mlx_pixel_put(data, x1, y1, 0x741b47);
							y1--;
							if (y1 == y2)
								break;
							e -= dx;
							if (e >= 0)
							{
								x1--;
								e += dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1 != x2)
				{
					my_mlx_pixel_put(data, x1, y1, 0x741b47);
					x1--;
				}
			}
		}
	}	
	else 
	{
		if (dy)
		{
			if (dy > 0)
			{
				while (y1 != y2)
				{
					my_mlx_pixel_put(data, x1, y1, 0x741b47);
					y1++;
				}
			}
			else 
			{
				while (y1 != y2)
				{
					my_mlx_pixel_put(data, x1, y1, 0x741b47);
					y1--;
				}
			}
		}
	}
}

void draw_line(t_data *data, int x1, int y1, int x2, int y2)
{
	double	dx;
	double	dy;
	int		pixel;
	double	pixel_x;
	double	pixel_y;

	dx = x2 - x1;
	dy = y2 - y1;
	pixel = sqrt((dx * dx) + (dy * dy));
	pixel_x = x1;
	pixel_y = y1;
	while (pixel)
	{
		my_mlx_pixel_put(data, pixel_x, pixel_y, 0x741b47);
		pixel_x += dx;
		pixel_y += dy;
		pixel--;
	}
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	char 	**split;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		temp_x;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		if (line)
		{
			y = 0;
			x = 0;
			split = ft_split(line, ' ');
			while (split[x])
				x++;
		}
		while (line)
		{
			line = get_next_line(fd);
			y++;
		}
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1500, 800, "Puis-je afficher un qudrillage ???");
		img.img_ptr = mlx_new_image(mlx_ptr, 1500, 800);
		img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
		temp_x = x;
	/*	while (x > 0)
		{
			y = temp_y;
			while (y > 0)
			{
				tracer_segment(10, 10, x * 60, y * 60, &img);
				y--;
			}
			x--;
		}	
		while (x >= 0)
		{
			tracer_segment(10 + (x * 60), 10, 10 + (x * 60) , 10 + (y * 60), &img);
			x--;
			printf("x = %d, y = %d \n", x, y);	
		}
		while (y >= 0)
		{
			tracer_segment(10 , 10 + (y * 60), 10 + (temp_x * 60), 10 + (y * 60), &img);
			y--;
		}*/
		draw_line(&img, 0, 0, 26, 26);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
		mlx_loop(mlx_ptr);
	}
	return (0);
}
