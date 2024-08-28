/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:57:58 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/28 10:58:00 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pre_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	check_for_the_name_of_file(char *str)
{
	if (!str || ft_strlen(str) < 4 || ft_strncmp(str + ft_strlen(str) - 4,
			".ber", 4) != 0)
		pre_error("Error: Invalid file extension. Expected '.ber'");
}

int	how_many_lines(char *filename)
{
	int		lines;
	int		fd;
	char	*str;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pre_error("Error: Could not open file");
	str = get_next_line(fd);
	while (str)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	more_than_3(char *filename)
{
	int	matrix_lines;

	matrix_lines = how_many_lines(filename);
	if (matrix_lines < 3)
		pre_error("Lines are less than 3");
}

void	test_fd(int fd)
{
	if (fd == -1)
	{
		close(fd);
		ft_printf("Error");
		exit(1);
	}
}
// stop!
