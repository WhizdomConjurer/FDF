/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:48 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 14:06:06 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int32_t get_tokrn(char *path)
{
	int		fd;
	char	*line;
	int		tokrn;
	char	**tokens;
	int		i;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	line = get_next_line(fd);
	tokrn = 0;
	while (line)
	{
		tokens = ft_split(line, " ");
		i = 0;
		while (++tokens)
			++tokrn;
		if (!tokens)
			return (-1);
		free_token(tokens);
		free(line);
		get_next_line(fd);
	}
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
	split_free(values);
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
		tokens = ft_split(line, " ");
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
	return (1);
}

t_coords	*parse_input(char *file_path)
{
	int32_t		token_count;
	int			fd;
	char		*str;
	t_coords	*cords;
	uint32_t	row;

	token_count = get_tokrn(file_path);
	if (!token_count)
		return (NULL);
	cords = init_coords(token_count);
	fill_coords(file_path, cords);
	return (cords);
}