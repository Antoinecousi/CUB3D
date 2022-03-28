/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:54:24 by acousini          #+#    #+#             */
/*   Updated: 2022/03/28 18:23:04 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoin_doublefree(char *s1, char *s2, int i, int j)
{
	char	*new;
	int		size;

	size = 0;
	size = ft_strlen(s1);
	if (!s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s2) + size + 1));
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	if (s1)
		free(s1);
	return (new);
}

char	*read_file(t_base *base, char buf[], int fd, char *file)
{
	int				reader;

	reader = 1;
	while (reader != 0)
	{
		reader = read(fd, buf, 512);
		if (reader == -1)
		{
			free(file);
			close(fd);
			destroybase(base, "problem with read in read_file. Abort.");
		}
		else
		{
			buf[reader] = '\0';
			file = ft_strjoin_doublefree(file, buf, 0, -1);
			if (file == NULL)
			{
				close(fd);
				destroybase(base,
					"problem with malloc in read_file. Abort.");
			}
		}
	}
	return (file);
}

void	init_raw_map(t_base *base, char *path_map)
{
	int 	ret;
	int		fd;
	char	*file;
	char	buf[512];

	ret = 0;
	fd = open(path_map, O_RDONLY | O_NOFOLLOW);
	if (fd == -1)
		destroybase(base, "Open issues.\nExit\n");
	file = malloc(1);
	*file = "\0";
	file = read_file(base, buf, fd, file);
	close(fd);
	base->game->raw_map = file;
}

int	initialise_base(char *path_map)
{
	t_base base;

	ft_bzero(&base, 8);
	// base.mlx = NULL;
	// base.win = NULL;
	// base.no = NULL;
	// base.so = NULL;
	// base.we = NULL;
	// base.ea = NULL;
	// base.floor = NULL;
	// base.sky = NULL;
	init_raw_map(&base, path_map);
	init_textures(&base, &base.game->raw_map);
}
