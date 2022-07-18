/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotwo_combinations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrangio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:27:46 by efrangio          #+#    #+#             */
/*   Updated: 2022/07/17 21:31:51 by efrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	answer_h_to_one_at_first_or_last(int h[4][2], int a[4][4]);
void	answer_v_to_one_at_first_or_last(int v[4][2], int a[4][4]);
void	answer_h_for_2_in_first_or_last_position(int h[4][2], int a[4][4]);
void	answer_v_for_2_in_first_or_last_position(int h[4][2], int a[4][4]);
void	answer_h_for_4_and_1_in_the_middle(int h[4][2], int a[4][4]);
void	answer_h_for_3_and_4_in_the_beggining_or_end(int h[4][2], int a[4][4]);
void	answer_v_for_3_and_4_in_the_beggining_or_end(int v[4][2], int a[4][4]);
int		try_h_in_the_edges(int a[4][4], int l, int n1, int n2);
int		try_h_in_the_middle(int a[4][4], int l, int n1, int n2);
int		try_v_in_the_middle(int a[4][4], int c, int n1, int n2);
void	print_answer(int a[4][4]);
int		has_repetitions(int a[4][4]);
int		has_v_repetition(int a[4][4]);
int		column_has_repetition(int a[4][4], int column);
int		has_h_repetition(int a[4][4]);
int		line_has_repetition(int a[4][4], int line);

void	answer_two_two(int h[4][2], int v[4][2], int a[4][4])
{	
	answer_h_to_one_at_first_or_last(h, a);
	answer_v_to_one_at_first_or_last(v, a);
	answer_h_for_2_in_first_or_last_position(h, a);
	answer_v_for_2_in_first_or_last_position(h, a);
	answer_h_for_4_and_1_in_the_middle(h, a);
	answer_h_for_3_and_4_in_the_beggining_or_end(h, a);
	answer_v_for_3_and_4_in_the_beggining_or_end(v, a);
}

void	answer_h_for_3_and_4_in_the_beggining_or_end(int h[4][2], int a[4][4])
{
	int	l;

	l = 0;
	while (l < 4)
	{
		if (h[l][0] == 2 && h[l][1] == 2)
		{
			if (a[l][0] == 3 && a[l][1] == 4)
			{
				a[l][2] = 1;
				a[l][3] = 2;
			}
			if (a[l][2] == 4 && a[l][3] == 3)
			{
				a[l][0] = 2;
				a[l][1] = 1;
			}
		}
		l++;
	}
}

void	answer_v_for_3_and_4_in_the_beggining_or_end(int v[4][2], int a[4][4])
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (v[c][0] == 2 && v[c][1] == 2)
		{
			if (a[0][c] == 3 && a[1][c] == 4)
			{
				a[2][c] = 1;
				a[3][c] = 2;
			}
			if (a[2][c] == 4 && a[3][c] == 3)
			{
				a[0][c] = 2;
				a[1][c] = 1;
			}
		}
		c++;
	}
}

void	answer_h_to_one_at_first_or_last(int h[4][2], int a[4][4])
{
	int	l;

	l = 0;
	while (l < 4)
	{
		if (h[l][0] == 2 && h[l][1] == 2)
		{
			if (a[l][0] == 1)
			{
				a[l][1] = 4;
				a[l][2] = 2;
				a[l][3] = 3;
			}
			if (a[l][3] == 1)
			{
				a[l][0] = 3;
				a[l][1] = 2;
				a[l][2] = 4;
			}
		}	
		l++;
	}
}

void	answer_v_to_one_at_first_or_last(int v[4][2], int a[4][4])
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (v[c][0] == 2 && v[c][1] == 2)
		{
			if (a[0][c] == 1)
			{
				a[1][c] = 4;
				a[2][c] = 2;
				a[3][c] = 3;
			}
			if (a[3][c] == 1)
			{
				a[0][c] = 3;
				a[1][c] = 2;
				a[2][c] = 4;
			}
		}
		c++;
	}
}

void	answer_h_for_2_in_first_or_last_position(int h[4][2], int a[4][4])
{
	int	l;

	l = 0;
	while (l < 4)
	{
		if (a[l][1] == 0 && a[l][2] == 0)
		{
			if (h[l][0] == 2 && h[l][1] == 2)
			{
				if (a[l][0] == 2 || a[l][3] == 2)
				{
					if (try_h_in_the_middle(a, l, 1, 4) == 0)
						try_h_in_the_middle(a, l, 4, 1);
				}
			}
		}
		l++;
	}
}

int	try_h_in_the_middle(int a[4][4], int l, int n1, int n2)
{
	a[l][1] = n1;
	a[l][2] = n2;
	if (has_repetitions(a) != 0)
	{
		a[l][1] = n2;
		a[l][2] = n1;
	}
	else
	{
		return (1);
	}
	if (has_repetitions(a) != 0)
	{
		a[l][1] = 0;
		a[l][2] = 0;
		return (0);
	}
	else
	{
		return (1);
	}
}

void	answer_v_for_2_in_first_or_last_position(int v[4][2], int a[4][4])
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (a[1][c] == 0 && a[2][c] == 0)
		{
			if (v[c][0] == 2 && v[c][1] == 2)
			{
				if (a[0][c] == 2 || a[3][c] == 2)
				{
					if (try_v_in_the_middle (a, c, 1, 4) == 0)
						try_v_in_the_middle (a, c, 4, 1);
				}
			}
		}
		c++;
	}
}

int	try_v_in_the_middle(int a[4][4], int c, int n1, int n2)
{
	a[1][c] = n1;
	a[2][c] = n2;
	if (has_repetitions(a) != 0)
	{
		a[1][c] = n2;
		a[2][c] = n1;
	}
	else
	{
		return (1);
	}
	if (has_repetitions(a) != 0)
	{
		a[1][c] = 0;
		a[2][c] = 0;
		return (0);
	}
	else
	{
		return (1);
	}
}

void	answer_h_for_4_and_1_in_the_middle(int h[4][2], int a[4][4])
{
	int	l;

	l = 0;
	while (l < 4)
	{
		if (h[l][0] == 2 && h[l][1] == 2)
		{
			if (a[l][1] == 4 && a[l][2] == 1)
				if (a[l][0] == 0 && a[l][3] == 0)
					if (try_h_in_the_edges (a, l, 2, 3) == 0)
						try_h_in_the_edges (a, l, 3, 2);
			if (a[l][1] == 1 && a[l][2] == 4)
				if (a[l][0] == 0 && a[l][3] == 0)
					if (try_h_in_the_edges (a, l, 2, 3) == 0)
						try_h_in_the_edges (a, l, 3, 2);
		}
		l++;
	}
}

int	try_h_in_the_edges(int a[4][4], int l, int n1, int n2)
{
	a[l][0] = n1;
	a[l][3] = n2;
	if (has_repetitions(a) != 0)
	{
		a[l][0] = n2;
		a[l][3] = n1;
	}
	else
	{
		return (1);
	}
	if (has_repetitions(a) != 0)
	{
		a[l][0] = 0;
		a[l][3] = 0;
		return (0);
	}
	else
	{
		return (1);
	}
}

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
