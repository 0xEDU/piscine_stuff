/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:06:48 by etachott          #+#    #+#             */
/*   Updated: 2022/07/17 19:57:17 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	detect_error(char p[16]);

int	count_args(char *argv[]);

int	count_argc(int argc);

int	check_errors(char p[16], char *argv[], int argc);

int	check_errors(char p[16], char *argv[], int argc)
{
	if (detect_error(p) == 0)
		return (0);
	if (count_argc(argc) == 0)
		return (0);
	if (count_args(argv) == 0)
		return (0);
	else
		return (1);
}

int	count_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	count_args(char *argv[])
{
	int		j;
	char	*arg;

	j = 0;
	arg = argv[1];
	while (*arg != '\0')
	{
		j += 1;
		arg++;
	}
	if (j != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	detect_error(char p[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (p[i] == '1' || p[i] == '2' || p[i] == '3' || p[i] == '4')
		{
			i++;
			continue ;
		}
		else
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
