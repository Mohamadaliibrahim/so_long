/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:58:39 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 14:35:08 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	setup(int ac, char *av[], char ***stx, t_node **node)
{
	if (ac != 2)
	{
		ft_printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	check_for_the_name_of_file(av[1]);
	so_long(av[1]);
	*stx = creat_the_array(av[1]);
	*node = creat_node();
	*node = count_c(*node, *stx);
	return (0);
}

int	allocate_memory(t_data **data, t_game **game, char **stx, t_node *node)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
	{
		ft_printf("Error: Failed to allocate memory for data.\n");
		lets_free(stx);
		free(node);
		return (1);
	}
	*game = malloc(sizeof(t_game));
	if (!(*game))
	{
		ft_printf("Error: Failed to allocate memory for game.\n");
		lets_free(stx);
		free(node);
		free(*data);
		return (1);
	}
	return (0);
}

int	initialize_mlx(t_data *data, char **stx)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error: Failed to initialize MLX.\n");
		lets_free(stx);
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, 40 * find_x(stx), 40
			* find_y(stx), "so_long");
	if (!data->win_ptr)
	{
		ft_printf("Error: Failed to create window.\n");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		lets_free(stx);
		return (1);
	}
	return (0);
}

void	setup_and_run_game(t_data *data, t_game *game, char **stx, t_node *node)
{
	data->map = stx;
	data->map_width = find_x(stx);
	data->map_height = find_y(stx);
	find_initial_player_position(data);
	fill_window(stx, *data);
	game->data = data;
	game->node = node;
	mlx_hook(data->win_ptr, X_EVENT_KEY_PRESS, 0, key_handler, game);
	mlx_hook(data->win_ptr, X_EVENT_KEY_EXIT, 1L << 0, close_game, game);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char *av[])
{
	t_data	*data;
	t_node	*node;
	t_game	*game;
	char	**stx;

	if (setup(ac, av, &stx, &node) || allocate_memory(&data, &game, stx, node)
		|| initialize_mlx(data, stx))
	{
		return (1);
	}
	setup_and_run_game(data, game, stx, node);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	lets_free(stx);
	free(node);
	free(data);
	free(game);
	return (0);
}
