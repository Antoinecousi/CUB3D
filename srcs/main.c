/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:00:57 by acousini          #+#    #+#             */
/*   Updated: 2022/03/28 17:12:04 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	check_cub(char *map)
{
	int		size;

	size = ft_strlen(map);
	if (ft_strncmp(map + size - 4, ".cub", 4) != 0)
		return (FALSE);
	if (size < 5)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_cub(argv[1]))
	{
		write(1, "usage: ./CUB3D [map.cub]", 25);
		return (FALSE);
	}
	if (initialise_t_root(argv[1]))
		return (FALSE);
	return (TRUE);
}
