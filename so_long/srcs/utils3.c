/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:59:53 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 14:35:19 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_paths(t_args *args, t_node *node)
{
	args->tmp = copy_str_array(args->str);
	check_reachable(args, node);
	lets_free(args->tmp);
	args->tmp = copy_str_array(args->str);
	check_for_exit(args, node);
	lets_free(args->tmp);
}

void	find_player_position(char **tmp, char **str, t_node *node)
{
	int		x;
	int		y;
	t_args	args;

	y = 0;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'P')
			{
				args.str = str;
				args.tmp = tmp;
				args.x = x;
				args.y = y;
				check_paths(&args, node);
				break ;
			}
			x++;
		}
		y++;
	}
}

void	handle_errors(t_error_args *args)
{
	if (args->node->c == 0 || args->node->c != args->count->c)
	{
		there_is_an_error1(args->count, args->node, args->all);
		error_occuredd(args->str, "Did not find a way to all collectables",
			args->tmp);
	}
	else if (args->node->e == 0)
	{
		there_is_an_error1(args->count, args->node, args->all);
		error_occuredd(args->str, "Did not find a way to the exit", args->tmp);
	}
}

void	find_player(char **tmp, char **str, char **all)
{
	t_node			*node;
	t_node			*count;
	t_error_args	args;

	node = creat_node();
	count = creat_node();
	count = count_c(count, tmp);
	find_player_position(tmp, str, node);
	args.count = count;
	args.node = node;
	args.str = str;
	args.tmp = tmp;
	args.all = all;
	handle_errors(&args);
	free(node);
	free(count);
}
