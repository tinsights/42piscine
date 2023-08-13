/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:58:18 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/13 10:58:19 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		num_len(char *str);
int		check_all_keys(char *dict, char *input, int len);
int		check_key(char *dict, char *input, int len);
void	print_words(char *dict, char *input, int len);
void	print_line(char *dict, char *input, int len);
int		pow_ten(char *str, int len);
int		ft_isnumeric(char c);
char	*clean_num(char *str, int len);
int		valid_input(char *str);
void	skip(int fd, char *buff);
int		exact_num_found(int fd, char *buff);
int		check_tens(char *dict, char *input);
int		check_hundreds(char *dict, char *input, int len);
int		check_thousands(char *dict, char *input, int len);
int		recurse_thousands(char *dict, char *input, int len);
void	skipline(int fd, char *buff);
void	skip(int fd, char *buff);
int		exact_num_found(int fd, char *buff);
void	printzero(int fd, char *buff);
void	printline(int fd, char *buff);
void	recurse_print(char *dict, char *input, int len);
void	print_hundreds(char *dict, char *input, int len);
void	print_doubles(char *dict, char *input);

#endif
