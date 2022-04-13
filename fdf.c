/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:25:20 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/13 16:44:53 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char* get_next_line(int fd);
char	**ft_split(char const *s, char c);

int	main(int ac, char **av)
{
	(void)	ac;
	int		fd;
	char	*line;
	int		i;
	int		line_len;

	i = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	line_len = strlen(ft_split(line, ' '));
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
		i++;
	}
	printf("x : %d \n y : %d", line_len, i);

}
