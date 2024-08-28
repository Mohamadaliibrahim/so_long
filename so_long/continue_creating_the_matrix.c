/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_creating_the_matrix.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:58:10 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 10:58:12 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lets_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	test_str_array(char **str, int fd, char *x)
{
	if (!str)
	{
		free(x);
		lets_free(str);
		close(fd);
		ft_printf("Error: Memory allocation failed");
		exit(1);
	}
}

char	**continue_creating_the_array(char **str, int fd)
{
	char	*x;
	int		i;
	int		len;

	i = 0;
	x = get_next_line(fd);
	while (x)
	{
		len = ft_strlen(x);
		if (x[len - 1] == '\n')
			x[len - 1] = '\0';
		str[i] = malloc(sizeof(char) * (len + 1));
		test_str_array(str, fd, x);
		ft_strlcpy(str[i], x, len + 1);
		free(x);
		x = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}

char	**creat_the_array(char *filename)
{
	int		fd;
	char	**str;
	int		lines;
	int		i;

	lines = how_many_lines(filename);
	fd = open(filename, O_RDONLY);
	test_fd(fd);
	str = malloc(sizeof(char *) * (lines + 1));
	if (str == NULL)
		pre_error("Error: Memory allocation failed");
	i = 0;
	while (i <= lines)
	{
		str[i] = NULL;
		i++;
	}
	test_str_array(str, fd, NULL);
	str = continue_creating_the_array(str, fd);
	return (str);
}

void	check_required(char **str)
{
	check_for_spaces(str);
	check_for_equal_lines(str);
	check_for_edges(str);
	check_for_middle(str);
	check_for_least_amount_of_requirments(str);
}
//stop!
