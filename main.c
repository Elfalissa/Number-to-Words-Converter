/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisamanukhova <alisamanukhova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:18:08 by adgomez           #+#    #+#             */
/*   Updated: 2025/09/17 12:23:03 by alisamanukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/**
 * Validate the input number string.
 *
 * Checks if the string is:
 * - non-empty,
 * - contains only digits,
 * - does not start with '0' (unless it is just "0"),
 * - does not exceed the maximum supported length (37 digits).
 *   (the numbers.dict is not large enough to display larger numbers)
 *
 * @param str  Pointer to the input string.
 * @return 1 if the string is valid, 0 otherwise.
 */
int	validation(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		if (str[0] == '0' && i > 0)
			return (0);
		i++;
	}
	if (ft_strlen(str) > 37)
		return (0);
	return (1);
}

/**
 * Program entry point.
 *
 * Accepts a single command-line argument (a number as a string),
 * validates it, and if correct, prints its word representation
 * by invoking display_head(), display_body(), and display_tail().
 * Prints "Error" if the input is invalid or arguments are incorrect.
 *
 * @param argc  Argument count.
 * @param argv  Argument vector.
 * @return 0 on success, non-zero on error.
 */
int	main(int argc, char *argv[])
{
	if (argc == 2 && validation(argv[1]) == 1)
	{
		display_head(argv[1]);
		display_body(argv[1]);
		display_tail(argv[1]);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
