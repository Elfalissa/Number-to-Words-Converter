/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisamanukhova <alisamanukhova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:23:46 by alisamanukh       #+#    #+#             */
/*   Updated: 2025/09/17 11:59:37 by alisamanukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/**
 * Display the leading (head) part of a number that is not a full 3-digit block.
 *
 * For numbers with more than 3 digits, the head contains the first 1 or 2 digits
 * before the 3-digit grouping starts. This function handles and displays them,
 * then appends the corresponding order (e.g., thousand, million).
 *
 * @param str  Pointer to the full number string.
 */
void	display_head(char *str)
{
	int		n_head;

	if (ft_strlen(str) < 4)
		return ;
	n_head = ft_strlen(str) % 3;
	if (n_head != 0)
	{
		if (n_head == 1)
			display_unit(str, 0);
		else
			handle_2digit_number(str, 0);
		display_the_order(str, 0);
	}
}

/**
 * Display the middle (body) blocks of the number.
 *
 * Iterates over each complete 3-digit block
 * in the number (excluding head and tail),
 * converts it into words,
 * and prints its corresponding order (thousand, million, etc.).
 *
 * @param str  Pointer to the full number string.
 */
void	display_body(char *str)
{
	int		start;
	int		k;

	if (ft_strlen(str) < 4)
		return ;
	start = ft_strlen(str) % 3;
	k = 1;
	while (start < ft_strlen(str) - 4)
	{
		if (start == 0)
			body(str, start, k, 0);
		else
			body(str, start, k, 1);
		start = start + 3;
		k++;
	}
}

/**
 * Display the final (tail) part of the number.
 *
 * Depending on the number of digits:
 * - 3 or more → process the last 3 digits,
 * - 2 digits  → handle as a two-digit number,
 * - 1 digit   → handle as a single-digit number.
 *
 * @param str  Pointer to the full number string.
 */
void	display_tail(char *str)
{
	int		end;
	int		is_space;

	is_space = 0;
	if (ft_strlen(str) >= 4)
		is_space = 1;
	end = ft_strlen(str) - 1;
	if (ft_strlen(str) >= 3)
		handle_3digits_number(str + end - 2, is_space);
	if (ft_strlen(str) == 2)
		handle_2digit_number(str, is_space);
	if (ft_strlen(str) == 1)
		handle_1digit_number(str);
}

/**
 * Display the order of magnitude for a digit block.
 *
 * Looks up the dictionary entry for the block's order
 * (e.g., thousand, million, billion) and prints it.
 *
 * @param str  Pointer to the full number string.
 * @param i    Index of the current 3-digit block (used to compute order).
 */
void	display_the_order(char *str, int i)
{
	char	*line;

	line = NULL;
	line = get_line_by_num("numbers.dict", ft_strlen(str) / 3 - i + 28);
	write(1, " ", 1);
	ft_putstr(line);
	free(line);
}
