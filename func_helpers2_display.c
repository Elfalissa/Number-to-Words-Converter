/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helpers2_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisamanukhova <alisamanukhova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:23:28 by alisamanukh       #+#    #+#             */
/*   Updated: 2025/09/17 11:56:09 by alisamanukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/**
 * Handle and display a one-digit number.
 *
 * Special case: if the digit is '0', "zero" is printed from the dictionary;
 * otherwise the digit is passed to display_unit() (where zero is ignored).
 *
 * @param str  Pointer to the string containing the digit character.
 */
void	handle_1digit_number(char *str)
{
	char	*line;

	line = NULL;
	if (str[0] == '0')
	{
		line = get_line_by_num("numbers.dict", 0);
		ft_putstr(line);
	}
	else
		display_unit(str, 0);
	free(line);
}

/**
 * Handle and display a two-digit number.
 *
 * - If the first digit is '0', only the unit is displayed.
 * - If the first digit is '1', the number is treated as a "teen" (10–19).
 * - Otherwise, the tens (20, 30, …) and optional unit are displayed.
 *
 * @param str       Pointer to the string containing two digit characters.
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	handle_2digit_number(char *str, int is_space)
{
	if (str[0] == '0')
		display_unit(str + 1, is_space);
	else if (str[0] == '1')
		display_teen(str, is_space);
	else
		display_tens(str, is_space);
}

/**
 * Handle and display a three-digit number.
 *
 * - If the entire number is "000", nothing is printed.
 * - Otherwise, the hundreds digit (if nonzero) is displayed,
 *   followed by the tens and units if they are not both zero.
 *
 * @param str       Pointer to the string containing three digit characters.
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	handle_3digits_number(char *str, int is_space)
{
	if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		return ;
	display_hundreds(str, is_space);
	if (!(str[1] == '0' && str[2] == '0'))
		handle_2digit_number(str + 1, 1);
}

/**
 * Process and display a 3-digit block of the full number string,
 * then optionally display its corresponding order (thousand, million, …).
 *
 * Skips blocks that are exactly "000".
 *
 * @param str       Pointer to the full number string.
 * @param start     Index of the first character of the 3-digit block.
 * @param i         Order index (e.g., 1 for thousand, 2 for million).
 * @param is_space  If nonzero, a leading space is printed before the output.
 */
void	body(char *str, int start, int i, int is_space)
{
	handle_3digits_number(str + start, is_space);
	if (!(str[start] == '0' && str[start + 1] == '0' && str[start + 2] == '0'))
		display_the_order(str, i);
}
