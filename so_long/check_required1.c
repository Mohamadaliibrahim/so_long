/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_required1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:57:34 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 10:57:37 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_middle(char **str)
{
	int	i;
	int	j;
	int	end_of_the_stack;

	i = 1;
	end_of_the_stack = 0;
	while (str[end_of_the_stack])
		end_of_the_stack++;
	end_of_the_stack--;
	while (i < end_of_the_stack)
	{
		j = 1;
		while (j < ft_strlen(str[i]) - 1)
		{
			if (str[i][j] != 'E' && str[i][j] != 'C' && str[i][j] != '1'
				&& str[i][j] != '0' && str[i][j] != 'P' && str[i][j] != 'F')
				error_occured(str, "error in the middle of the map");
			j++;
		}
		i++;
	}
}

t_node	*creat_node(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_occured(NULL, "Error: Memory allocation failed");
	node->c = 0;
	node->e = 0;
	node->p = 0;
	return (node);
}

void	error_occured_node(char **str, char *msg, t_node *node)
{
	free(node);
	lets_free(str);
	ft_printf("%s\n", msg);
	exit(1);
}

void	check_for_doubles(t_node *node, char **str)
{
	if (node->c < 1)
		error_occured_node(str, "There should be at least 1 colacteble", node);
	if (node->e != 1)
		error_occured_node(str, "THere should be 1 exit", node);
	if (node->p != 1)
		error_occured_node(str, "There should be 1 player", node);
	free(node);
}

void	check_for_least_amount_of_requirments(char **str)
{
	t_node	*node;
	int		i;
	int		j;
	int		end_of_the_stack;

	i = 0;
	node = creat_node();
	end_of_the_stack = 0;
	while (str[end_of_the_stack] != NULL)
		end_of_the_stack++;
	while (str[++i] != NULL)
	{
		j = 1;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == 'E')
				node->e++;
			if (str[i][j] == 'P')
				node->p++;
			if (str[i][j] == 'C')
				node->c++;
			j++;
		}
	}
	check_for_doubles(node, str);
}
//stop!!
