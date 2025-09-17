/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisamanukhova <alisamanukhova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:22:39 by alisamanukh       #+#    #+#             */
/*   Updated: 2025/09/17 16:03:24 by alisamanukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
/**
 * Reads characters from a file descriptor until a newline ('\n') or
 * EOF is encountered.
 * Only lowercase letters (a–z) and newline characters
 * (i.e. NAMES, like "ten", "thirteen", "billion" etc. )
 * are stored in the output string.
 *
 * @param fd  File descriptor to read from.
 * @return    A dynamically allocated null-terminated string containing the line.
 *            The caller is responsible for freeing the returned string.
 */
char	*get_next_line(int fd)
{
	char	*line;
	int		bytes;
	char	c;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * 1000);
	bytes = read(fd, &c, 1);
	while (bytes > 0 && c != '\n')
	{
		if ((c >= 'a' && c <= 'z') || c == '\n')
		{
			line[i++] = c;
		}
		bytes = read(fd, &c, 1);
	}
	line[i] = '\0';
	return (line);
}

/**
 * Opens a file and retrieves the content of the specified line number.
 * Lines are counted starting from 0. Internally uses get_next_line().
 *
 * @param fname      Path to the file.
 * @param line_num   Zero-based index of the line to retrieve.
 * @return           A dynamically allocated str. containing the requested line.
 *                   The caller is responsible for freeing the returned string.
 */
char	*get_line_by_num(char *fname, int line_num)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(fname, O_RDONLY);
	i = 0;
	while (i < line_num)
	{
		get_next_line(fd);
		i++;
	}
	line = get_next_line(fd);
	close(fd);
	return (line);
}
