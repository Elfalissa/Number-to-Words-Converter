/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helpers1_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisamanukhova <alisamanukhova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:21:28 by alisamanukh       #+#    #+#             */
/*   Updated: 2025/09/17 11:46:57 by alisamanukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/**
 * Display a single-digit unit (1–9) from the dictionary file.
 *
 * @param str       Pointer to the string containing the digit character.
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	display_unit(char *str, int is_space)
{
	char	n;
	char	*line;

	n = str[0];
	line = NULL;
	line = get_line_by_num("numbers.dict", ft_atoi(&n));
	if (is_space == 1)
		write(1, " ", 1);
	ft_putstr(line);
	free(line);
}

/**
 * Display a "teen" number (10–19) from the dictionary file.
 *
 * @param str       Pointer to the string containing the two-digit number.
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	display_teen(char *str, int is_space)
{
	char	m[3];
	char	*line;

	m[0] = str[0];
	m[1] = str[1];
	m[2] = '\0';
	line = NULL;
	line = get_line_by_num("numbers.dict", ft_atoi(m));
	if (is_space == 1)
		write(1, " ", 1);
	ft_putstr(line);
	free(line);
}

/**
 * Display a two-digit number (20–99) from the dictionary file.
 *
 * Handles both the tens part (e.g., "twenty") and the optional units
 * part if the number is not a multiple of 10.
 *
 * @param str       Pointer to the string containing the two-digit number.
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	display_tens(char *str, int is_space)
{
	char	m[3];
	char	*line;

	m[0] = str[0];
	m[1] = str[1];
	m[2] = '\0';
	line = NULL;
	line = get_line_by_num("numbers.dict", ft_atoi(m) / 10 + 18);
	if (is_space == 1)
		write(1, " ", 1);
	ft_putstr(line);
	free(line);
	if (ft_atoi(m) % 10 != 0)
	{
		line = get_line_by_num("numbers.dict", ft_atoi(m) % 10);
		write(1, " ", 1);
		ft_putstr(line);
		free(line);
	}
}

/**
 * Display a three-digit number's hundreds part (100, 200, ... 900).
 *
 * Prints the unit (e.g., "one") followed by "hundred"
 * if the first character is not '0'.
 *
 * @param str       Pointer to the string containing the three-digit number.
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	display_hundreds(char *str, int is_space)
{
	char	*line;

	line = NULL;
	if (str[0] != '0')
	{
		line = get_line_by_num("numbers.dict", str[0] - '0');
		if (is_space == 1)
			write(1, " ", 1);
		ft_putstr(line);
		free(line);
		line = get_line_by_num("numbers.dict", 28);
		write(1, " ", 1);
		ft_putstr(line);
		free(line);
	}
}
