/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:58:48 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 11:10:01 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*init_image(void)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->x = 0;
	image->y = 0;
	image->image_ptr = NULL;
	image->img_width = 0;
	image->img_height = 0;
	image->image_file = NULL;
	return (image);
}

void	there_is_an_error(char **str, t_data data, t_image *image)
{
	lets_free(str);
	ft_printf("Error: Failed to load image '%s'.\n", (image->image_file));
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(image);
	exit(1);
}

void	continue_filling_window(t_data data, t_image *image)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, (image->image_ptr),
		(image->x) * (image->img_width), (image->y) * (image->img_height));
	mlx_destroy_image(data.mlx_ptr, image->image_ptr);
}

void	fill_window(char **str, t_data data)
{
	t_image	*image;

	image = init_image();
	while (str && str[image->y])
	{
		image->x = 0;
		while (str[image->y] && str[image->y][image->x])
		{
			image->image_file = get_image_file(str[image->y][image->x]);
			if (image->image_file)
			{
				image->image_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
						image->image_file, &(image->img_width),
						&(image->img_height));
				if (!(image->image_ptr))
					there_is_an_error(str, data, image);
				continue_filling_window(data, image);
			}
			image->x++;
		}
		image->y++;
	}
	free(image);
}

void	handle_move(t_game *game, int new_x, int new_y, int *move_count)
{
	if (game->data->map[new_y][new_x] != '1')
	{
		if (game->data->map[new_y][new_x] != 'E')
		{
			if (game->data->map[new_y][new_x] == 'C')
			{
				game->data->map[new_y][new_x] = '0';
				game->node->c--;
			}
			ft_printf("number of moves : %d\n", *move_count);
			(*move_count)++;
		}
	}
}
// stop!
