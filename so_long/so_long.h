/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:59:15 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 18:43:55 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "lib_ft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Key codes
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define EXIT 65307
# define Q_KEY 113

// Player dimensions
# define PLAYER_WIDTH 64
# define PLAYER_HEIGHT 64

// MLX events
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

// Struct definitions
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
}			t_data;

typedef struct s_node
{
	int		c;
	int		p;
	int		e;
}			t_node;

typedef struct s_game
{
	t_data	*data;
	t_node	*node;
}			t_game;

typedef struct s_args
{
	char	**str;
	char	**tmp;
	int		x;
	int		y;
}			t_args;

typedef struct s_error_args
{
	t_node	*count;
	t_node	*node;
	char	**str;
	char	**tmp;
	char	**all;
}			t_error_args;

typedef struct s_image
{
	int		x;
	int		y;
	void	*image_ptr;
	int		img_width;
	int		img_height;
	char	*image_file;
}			t_image;

// Function prototypes
void		lets_print(char **str);
void		so_long(char *filename);
int			main(int ac, char *av[]);
void		pre_error(char *msg);
void		check_for_the_name_of_file(char *str);
int			how_many_lines(char *filename);
void		more_than_3(char *filename);
void		test_fd(int fd);
void		lets_free(char **str);
void		test_str_array(char **str, int fd, char *x);
char		**continue_creating_the_array(char **str, int fd);
char		**creat_the_array(char *filename);
void		check_required(char **str);
void		check_for_equal_lines(char **str);
void		error_occuredd(char **str, char *msg, char **tmp);
char		**copy_str_array(char **str);
int			key_handler(int keycode, t_game *game);
int			close_window(t_data *data);
t_node		*creat_node(void);
int			find_y(char **str);
int			find_x(char **str);
void		find_player(char **tmp, char **str, char **all);
void		check_reachable(t_args *args, t_node *node);
void		check_for_exit(t_args *args, t_node *node);
t_node		*count_c(t_node *count, char **str);
int			close_game(t_game *game, int flag);
int			ft_strlen_char(char **str);
void		check_for_spaces(char **str);
void		check_for_edges(char **str);
void		check_for_middle(char **str);
void		check_for_least_amount_of_requirments(char **str);
void		error_occured(char **str, char *msg);
int			close_window(t_data *data);
void		there_is_an_error1(t_node *count, t_node *node, char **all);
void		check_paths(t_args *args, t_node *node);
void		find_player_position(char **tmp, char **str, t_node *node);
void		handle_errors(t_error_args *args);
t_image		*init_image(void);
void		there_is_an_error(char **str, t_data data, t_image *image);
void		continue_filling_window(t_data data, t_image *image);
void		fill_window(char **str, t_data data);
void		handle_move(t_game *game, int new_x, int new_y, int *move_count);
void		check_exit(t_game *game, int new_x, int new_y);
void		update_player_position(t_game *game, int new_x, int new_y);
void		move_player(t_game *game, int new_x, int new_y);
void		find_initial_player_position(t_data *data);
char		*get_image_file(char c);

#endif
