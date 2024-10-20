/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:59:37 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 14:35:15 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**copy_str_array(char **str)
{
	int		i;
	int		array_len;
	char	**copy;

	array_len = ft_strlen_char(str);
	copy = malloc((array_len + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < array_len)
	{
		copy[i] = malloc((strlen(str[i]) + 1) * sizeof(char));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		strcpy(copy[i], str[i]);
		i++;
	}
	copy[array_len] = NULL;
	return (copy);
}

void	error_occuredd(char **str, char *msg, char **tmp)
{
	lets_free(tmp);
	lets_free(str);
	ft_printf("%s\n", msg);
	exit(1);
}

int	find_x(char **str)
{
	int	x;

	x = 0;
	while (str[1][x])
		x++;
	return (x);
}

int	find_y(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
