/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:58:55 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 14:35:14 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->data->map[new_y][new_x] == 'E')
	{
		if (game->node->c == 0)
		{
			ft_printf("\033[1;32mYou won!\n\033[0m");
			free(game->node);
			close_game(game, 0);
		}
		else
		{
			ft_printf("\033[1;31mCollect all the items before exiting!\033[0m\n");
			return ;
		}
	}
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->data->map[new_y][new_x] != '1')
	{
		game->data->map[game->data->player_y][game->data->player_x] = '0';
		game->data->map[new_y][new_x] = 'P';
		game->data->player_x = new_x;
		game->data->player_y = new_y;
		fill_window(game->data->map, *(game->data));
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	static int	move_count = 0;

	if (game->data->map[new_y][new_x] != '1')
	{
		handle_move(game, new_x, new_y, &move_count);
		check_exit(game, new_x, new_y);
		if (game->data->map[new_y][new_x] != 'E')
			update_player_position(game, new_x, new_y);
	}
}

int	key_handler(int keycode, t_game *game)
{
	t_data	*data;

	data = game->data;
	if (keycode == A_KEY || keycode == LEFT_KEY)
		move_player(game, data->player_x - 1, data->player_y);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		move_player(game, data->player_x + 1, data->player_y);
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_player(game, data->player_x, data->player_y - 1);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_player(game, data->player_x, data->player_y + 1);
	else if (keycode == EXIT || keycode == Q_KEY)
		close_game(game, 1);
	return (0);
}

void	so_long(char *filename)
{
	char	**str;
	char	**tmp;
	char	**tmp1;

	more_than_3(filename);
	str = creat_the_array(filename);
	check_required(str);
	tmp = copy_str_array(str);
	tmp1 = copy_str_array(str);
	find_player(tmp1, tmp, str);
	lets_free(str);
	lets_free(tmp1);
	lets_free(tmp);
}
// stop!
