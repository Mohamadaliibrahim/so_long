/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:59:30 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 10:59:33 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lets_print(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			ft_printf("%c", str[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	check_reachable(t_args *args, t_node *node)
{
	t_args	new_args;

	if (args->tmp[args->y][args->x] == '1'
		|| args->tmp[args->y][args->x] == 'E')
		return ;
	else if (args->tmp[args->y][args->x] == 'C')
		node->c++;
	args->tmp[args->y][args->x] = '1';
	new_args = *args;
	new_args.x = args->x + 1;
	check_reachable(&new_args, node);
	new_args.x = args->x - 1;
	check_reachable(&new_args, node);
	new_args.x = args->x;
	new_args.y = args->y + 1;
	check_reachable(&new_args, node);
	new_args.y = args->y - 1;
	check_reachable(&new_args, node);
}

void	check_for_exit(t_args *args, t_node *node)
{
	t_args	new_args;

	if (args->tmp[args->y][args->x] == '1')
		return ;
	else if (args->tmp[args->y][args->x] == 'E')
		node->e++;
	args->tmp[args->y][args->x] = '1';
	new_args = *args;
	new_args.x = args->x + 1;
	check_for_exit(&new_args, node);
	new_args.x = args->x - 1;
	check_for_exit(&new_args, node);
	new_args.x = args->x;
	new_args.y = args->y + 1;
	check_for_exit(&new_args, node);
	new_args.y = args->y - 1;
	check_for_exit(&new_args, node);
}

t_node	*count_c(t_node *count, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				count->c++;
			j++;
		}
		i++;
	}
	return (count);
}

void	there_is_an_error1(t_node *count, t_node *node, char **all)
{
	free(count);
	free(node);
	lets_free(all);
}
//stop!
