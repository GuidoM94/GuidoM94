/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:18:29 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/22 15:28:37 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	guido;

	if (ac == 2)
	{
		ft_fill_matrix(av[1], &guido);
		ft_print_struct(&guido);
		guido.mlx = mlx_init();
		ft_open_images(&guido);
		guido.win = mlx_new_window(guido.mlx, guido.width * 64, \
			guido.height * 64, "Play your game !");
		mlx_do_key_autorepeaton(guido.mlx);
		mlx_loop(guido.mlx);
	}
	write(0, "ERROR!\nNumber of invalid arguments\n", 36);
	exit(0);
}
