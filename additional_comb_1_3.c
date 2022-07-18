/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_comb_1_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:58:13 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:58:14 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	answer_h_1_3_additionals_1_2_3(int h[4][2], int a[4][4], int i);
void	answer_v_1_3_additionals_1_2_3(int v[4][2], int a[4][4], int i);

// verifica as combinações adicionais possíveis de 1 e 3 horizontal
// 1, 2 e 3 na segunda casa
// 1 na última ou penúltima casa
// -----------------------------
//1, 3:  [4, 1, 3, 2]
//1, 3:  [4, 2, 3, 1]
//1, 3:  [4, 3, 1, 2]
void	answer_h_1_3_additionals(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_h_1_3_additionals_1_2_3(h, a, i);
		if ((h[i][0] == 1 && h[i][1] == 3) && a[i][2] == 1)
		{
			a[i][1] = 3;
			a[i][3] = 2;
		}
		if ((h[i][0] == 1 && h[i][1] == 3) && a[i][3] == 1)
		{
			a[i][1] = 2;
			a[i][2] = 3;
		}
		i++;
	}
}

void	answer_h_1_3_additionals_1_2_3(int h[4][2], int a[4][4], int i)
{
	if ((h[i][0] == 1 && h[i][1] == 3) && a[i][1] == 1)
	{
		a[i][2] = 3;
		a[i][3] = 2;
	}
	if ((h[i][0] == 1 && h[i][1] == 3) && a[i][1] == 2)
	{
		a[i][2] = 3;
		a[i][3] = 1;
	}
	if ((h[i][0] == 1 && h[i][1] == 3) && a[i][1] == 3)
	{
		a[i][2] = 1;
		a[i][3] = 2;
	}
}

// check combinations for 1 and 3 vertical question
//1, 2, 3 in the second position
//or 1 in the third and fourth positions
//---------
//1, 3:  [4, 1, 3, 2]
//1, 3:  [4, 2, 3, 1]
//1, 3:  [4, 3, 1, 2]
void	answer_v_1_3_additionals(int v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_v_1_3_additionals_1_2_3(v, a, i);
		if ((v[i][0] == 1 && v[i][1] == 3) && a[2][i] == 1)
		{
			a[1][i] = 3;
			a[3][i] = 2;
		}
		if ((v[i][0] == 1 && v[i][1] == 3) && a[3][i] == 1)
		{
			a[1][i] = 2;
			a[2][i] = 3;
		}
		i++;
	}
}

void	answer_v_1_3_additionals_1_2_3(int v[4][2], int a[4][4], int i)
{
	if ((v[i][0] == 1 && v[i][1] == 3) && a[1][i] == 1)
	{
		a[2][i] = 3;
		a[3][i] = 2;
	}
	if ((v[i][0] == 1 && v[i][1] == 3) && a[1][i] == 2)
	{
		a[2][i] = 3;
		a[3][i] = 1;
	}
	if ((v[i][0] == 1 && v[i][1] == 3) && a[1][i] == 3)
	{
		a[2][i] = 1;
		a[3][i] = 2;
	}
}
