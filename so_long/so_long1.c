/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:58:29 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 12:37:59 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		lets_free(data->map);
	free(data);
	return (0);
}

int	close_game(t_game *game, int flag)
{
	if (game)
	{
		if (game->data)
			close_window(game->data);
		if (flag)
			if (game->node)
				free(game->node);
		free(game);
	}
	exit(0);
	return (0);
}

void	find_initial_player_position(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

char	*get_image_file(char c)
{
	if (c == '1')
		return ("images/vertopal.com_images (1) (1).xpm");
	else if (c == '0')
		return ("images/empty.xpm");
	else if (c == 'P')
		return ("images/helo.xpm");
	else if (c == 'C')
		return ("images/images-_1_-_1_.xpm");
	else if (c == 'E')
		return ("images/doors.xpm");
	return (NULL);
}

//stop!
