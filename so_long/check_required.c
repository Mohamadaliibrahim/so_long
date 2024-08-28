/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_required.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:57:46 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 10:57:47 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_occured(char **str, char *msg)
{
	lets_free(str);
	ft_printf("%s\n", msg);
	exit(1);
}

void	check_for_equal_lines(char **str)
{
	int	i;
	int	j;
	int	prev;

	i = 0;
	prev = ft_strlen(str[i]);
	i++;
	while (str[i])
	{
		j = ft_strlen(str[i]);
		if (prev != j)
			error_occured(str, "lines of the matrix do not have equal width!");
		prev = j;
		i++;
	}
}

int	ft_strlen_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_for_edges(char **str)
{
	int	i;
	int	j;
	int	x;

	x = ft_strlen_char(str) - 1;
	j = 0;
	while (str[0][j] != '\0')
	{
		if (str[0][j] != '1')
			error_occured(str, "The top row is not all 1");
		if (str[x][j] != '1')
			error_occured(str, "The bottom row is not all 1");
		j++;
	}
	i = 0;
	while (str[i])
	{
		j = ft_strlen(str[i]) - 1;
		if (str[i][0] != '1')
			error_occured(str, "The left column is not 1");
		if (str[i][j] != '1')
			error_occured(str, "The right column is not 1");
		i++;
	}
}

void	check_for_spaces(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][0] == '\0' || str[i][0] == '\n' || str[i][0] == ' ')
				error_occured(str, "Empty space in the middle of the matrix");
			j++;
		}
		i++;
	}
}
//stop!
