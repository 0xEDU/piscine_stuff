/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotwo_answers_h.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:45:51 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:46:17 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		try_h_in_the_edges(int a[4][4], int l, int n1, int n2);
int		try_h_in_the_middle(int a[4][4], int l, int n1, int n2);

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
