/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:44:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/06 17:09:21 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_char(t_game *guido)
{
	int	x;
	int	y;

	y = 0;
	while (y < guido->height)
	{
		x = 0;
		while (x < guido->width)
		{
			if (guido->matrix[y][x] != '0' && \
				guido->matrix[y][x] != '1' && \
				guido->matrix[y][x] != 'C' && \
				guido->matrix[y][x] != 'E' && \
				guido->matrix[y][x] != 'P')
			{
				ft_error("--> Invalid map <--");
				end_game(guido);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_perimeter(t_game *guido)
{
	int	x;
	int	y;

	y = 0;
	while (y < guido->height)
	{
		x = 0;
		while (x < guido->width)
		{
			if (guido->matrix[y][x] != '1' && \
				((x == 0 || x == guido->width - 1) || \
				(y == 0 || y == guido->height - 1)))
			{
				ft_error("--> Invalid map <--");
				end_game(guido);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_uieeeesy(t_game *guido, int x, int y)
{
	if (guido->matrix[y][x] == 'C')
		guido->c++;
	else if (guido->matrix[y][x] == 'E')
		guido->e++;
	else if (guido->matrix[y][x] == 'P')
	{
		guido->x_player = x;
		guido->y_player = y;
		guido->p++;
	}
}

int	ft_check_inside(t_game *guido)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < guido->height - 1)
	{
		x = 0;
		while (x++ < guido->width - 1)
			ft_uieeeesy(guido, x, y);
	}
	if (guido->c == 0 || guido->e == 0 || guido->p == 0 || guido->p > 1)
	{
		ft_error("--> Invalid map <--");
		end_game(guido);
		return (0);
	}
	return (1);
}

int	ft_check_map(t_game *guido)
{
	if (ft_check_char(guido) == 0)
		return (0);
	else if (ft_check_perimeter(guido) == 0)
		return (0);
	else if (ft_check_inside(guido) == 0)
		return (0);
	return (1);
}
