/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:45:49 by acousini          #+#    #+#             */
/*   Updated: 2022/03/28 18:22:48 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int 	ft_chrcmp(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

void	add_floor(t_base *base, t_text *text, char *needle, int *i)
{
	char	*raw_map;

	raw_map = base->game->raw_map;
	while (ft_chrcmp(raw_map[*i], WHITESPACES))
		*i++;
	if (ft_strncmp(needle, raw_map + *i, 2))
		destroybase(base, "texture problem.\n Abort\n");
	*i += 2;
	while (ft_chrcmp(raw_map[*i], WHITESPACES))
		*i++;
}

void	add_textures(t_base *base, t_text *text, char *needle, int *i)
{
	char	*raw_map;

	raw_map = base->game->raw_map;
	while (ft_chrcmp(raw_map[*i], WHITESPACES))
		*i++;
	if (ft_strncmp(needle, raw_map + *i, 2))
		destroybase(base, "texture problem.\n Abort\n");
	*i += 2;
	while (ft_chrcmp(raw_map[*i], WHITESPACES))
		*i++;
	
}

int	init_textures(t_base *base, char *raw_map)
{
	int		i;

	i = 0;
	add_textures(base, base->no, "NO", &i);
	add_textures(base, base->so, "SO", &i);
	add_textures(base, base->we, "WE", &i);
	add_textures(base, base->ea, "EA", &i);
	add_floor(base, base->no, "F", &i);
	add_floor(base, base->no, "C", &i);
}