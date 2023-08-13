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
int		check_if_key_exists(char *dict, char *input, int len);
void	print_words(char *dict, char *input, int len);
void	print_line(char *dict, char *input, int len);
int		pow_ten(char *str, int len);
int		ft_isnumeric(char c);
char	*clean_num(char *str, int len);
int		valid_input(char *str);

#endif
