/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotwo_repetitions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:43:08 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:43:09 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		has_v_repetition(int a[4][4]);
int		column_has_repetition(int a[4][4], int column);
int		has_h_repetition(int a[4][4]);
int		line_has_repetition(int a[4][4], int line);

int	has_repetitions(int a[4][4])
{
	int	it_has;

	it_has = 0;
	it_has += has_h_repetition(a);
	it_has += has_v_repetition(a);
	return (it_has);
}

int	has_v_repetition(int a[4][4])
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (column_has_repetition(a, c) != 0)
			return (1);
		c++;
	}
	return (0);
}

int	column_has_repetition(int a[4][4], int column)
{
	int	l;
	int	i;
	int	counter;

	i = 1;
	while (i <= 4)
	{
		l = 0;
		counter = 0;
		while (l < 4)
		{
			if (a[l][column] == i)
				counter++;
			l++;
		}
		if (counter > 1)
			return (1);
		i++;
	}
	return (0);
}

int	has_h_repetition(int a[4][4])
{
	int	l;
	int	c;
	int	i;
	int	counter;

	l = 0;
	while (l < 4)
	{
		if (line_has_repetition(a, l) != 0)
			return (1);
		l++;
	}
	return (0);
}

int	line_has_repetition(int a[4][4], int line)
{
	int	c;
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (i <= 4)
	{
		c = 0;
		counter = 0;
		while (c < 4)
		{
			if (a[line][c] == i)
				counter++;
			c++;
		}
		if (counter > 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
