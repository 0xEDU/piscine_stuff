/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotwo_combinations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrangio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:27:46 by efrangio          #+#    #+#             */
/*   Updated: 2022/07/17 21:48:45 by lphelipe         ###   ########.fr       */
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
int		try_v_in_the_middle(int a[4][4], int c, int n1, int n2);
void	print_answer(int a[4][4]);

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
