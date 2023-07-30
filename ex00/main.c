/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:54:22 by tjegades          #+#    #+#             */
/*   Updated: 2023/07/29 12:58:28 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		atoi(char *str);

/**
* Defining main like this allows
* the compiled program to take in
* input from the command line when run.
* argc is an integer that contains the number of
* commands typed into the terminal,
* and argv is an array of strings, containing the commands typed in.
* i.e. if the program is run with ./a.out 5 3,
* then argc = 3, and argv = ["a.out", "5", "3"]
**/
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	rush (atoi(argv[1]), atoi(argv[2]));
}

int	atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

/*
* Defining main like this allows
* the compiled program to take in
* input from the command line when run.
* argc is an integer that contains the number of
* commands typed into the terminal,
* and argv is an array of strings, containing the commands typed in.
* i.e. if the program is run with ./a.out 5 3,
* then argc = 3, and argv = ["a.out", "5", "3"]
*
int	main(int argc, char **argv)
{	
	// here we check that the right
	// number of arguments were entered.
	// if the user didn't input a length and width, the program ends.
	if (argc != 3)
		return (-1);
	
	// else, the rush function is called using the numbers passed in
	rush (atoi(argv[1]), atoi(argv[2]));
}

* This function converts the string "5" into the integer 5
* Because rush() expects input of type int, but main()
* receives input from the terminal of type char*.
* It does basic ASCII conversion: looks for digits between '0' and '9'
* and subtracts the ASCII value to get back the integer digits.

int	atoi(char *str)						
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}
*/