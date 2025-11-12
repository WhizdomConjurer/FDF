/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:48 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 21:58:20 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>


static int32_t	get_tokrn(char *path)
{
	int		fd;
	char	*line;
	int		tokrn;
	char	**tokens;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	tokrn = 0;
	while (line)
	{
		tokens = ft_split(line, ' ');
		i = -1;
		while (tokens[i++])
			++tokrn;
		if (!tokens)
			return (-1);
		free_token(tokens);
		free(line);
		line = get_next_line(fd);
	}
	return (tokrn);
}

static int32_t	set_value(t_coords *coords, int col, int row, char *arr)
{
	static int		idx = 0;
	char			**values;

	coords->x[idx] = col;
	coords->y[idx] = row;
	values = ft_split(arr, ',');
	if (!values)
		return (-1);
	coords->z[idx] = ft_atoi(values[0]);
	coords->color[idx] = convert_color(values[1]);
	free_token(values);
	idx++;
	return (1);
}

static int32_t	fill_coords(char *path, t_coords *coords)
{
	int		fd;
	char	*line;
	int		row;
	char	**tokens;
	int		col;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	row = 0;
	while (line)
	{
		tokens = ft_split(line, ' ');
		col = -1;
		while (tokens[++col])
			if (set_value(coords, row, col, tokens[col]) == -1)
				return (-1);
		free_token(tokens);
		coords -> height++;
		coords -> width = col;
		free(line);
		line = get_next_line(fd);
		++row;
	}
	coords -> size = row * col;
	return (1);
}

t_coords	*parse_input(char *file_path)
{
	int32_t		token_count;
	t_coords	*cords;

	token_count = get_tokrn(file_path);
	if (!token_count)
		return (NULL);
	cords = init_coords(token_count);
	fill_coords(file_path, cords);
	return (cords);
}
