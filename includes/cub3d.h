/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:04:12 by acousini          #+#    #+#             */
/*   Updated: 2022/03/28 18:07:43 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// LIBRARIES
# include "../libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// MACROS
# define ERROR				1
# define FALSE				1
# define TRUE				0
# define WHITESPACES		"\t\n\r\v\f "


// STRUCTS
typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_text
{
	void	*img;
	char	*addr;
	int		init;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_text;

typedef struct s_game
{
	char			**map;
	char			*raw_map;
	int				height;
	int				width;
	int				collected;
	int				player_move;
}				t_game;

typedef struct s_base
{
	void	*mlx;
	void	*win;
	t_text	*no;
	t_text	*so;
	t_text	*ea;
	t_text	*we;
	t_text	*floor;
	t_text	*sky;
	t_game	*game;
}				t_base;

// FUNCTIONS
int	initialise_base(char *path_map);
int	destroybase(t_base *base, char *error)


#endif