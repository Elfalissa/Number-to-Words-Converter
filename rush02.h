/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisamanukhova <alisamanukhova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:03:49 by alisamanukh       #+#    #+#             */
/*   Updated: 2025/09/17 16:03:56 by alisamanukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

////
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
void		ft_putstr(char *str);
////
char		*get_next_line(int fd);
char		*get_line_by_num(char *fname, int line_num);
////
void		display_unit(char *str, int is_space);
void		display_teen(char *str, int is_space);
void		display_tens(char *str, int is_space);
void		display_hundreds(char *str, int is_space);
////
void		handle_1digit_number(char *str);
void		handle_2digit_number(char *str, int is_space);
void		handle_3digits_number(char *str, int is_space);
////
void		display_head(char *str);
void		display_body(char *str);
void		display_tail(char *str);
////
void		body(char *str, int start, int i, int is_space);
void		display_the_order(char *str, int i);

#endif
