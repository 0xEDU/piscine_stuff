/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varejao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrangio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:49:07 by efrangio          #+#    #+#             */
/*   Updated: 2022/07/17 21:37:06 by efrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	answer_h_3_1_additionals_1_2_3(int h[4][2], int a[4][4], int i);
void	answer_v_3_1_additionals_1_2_3(int v[4][2], int a[4][4], int i);

// verifica as combinações adicionais possíveis de 3 e 1 horizontal
// 1, 2 e 3 na terceira casa
// 1 na primeira ou segunda casa
// -----------------------------
//3, 1:  [1, 3, 2, 4]
//3, 1:  [2, 1, 3, 4]
//3, 1:  [2, 3, 1, 4]
void	answer_h_3_1_additionals(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_h_3_1_additionals_1_2_3(h, a, i);
		if ((h[i][0] == 3 && h[i][1] == 1) && a[i][0] == 1)
		{
			a[i][1] = 3;
			a[i][2] = 2;
		}
		if ((h[i][0] == 3 && h[i][1] == 1) && a[i][1] == 1)
		{
			a[i][0] = 2;
			a[i][2] = 3;
		}
		i++;
	}
}

void	answer_h_3_1_additionals_1_2_3(int h[4][2], int a[4][4], int i)
{
	if ((h[i][0] == 3 && h[i][1] == 1) && a[i][2] == 1)
	{
		a[i][0] = 2;
		a[i][1] = 3;
	}
	if ((h[i][0] == 3 && h[i][1] == 1) && a[i][2] == 2)
	{
		a[i][0] = 1;
		a[i][1] = 3;
	}
	if ((h[i][0] == 3 && h[i][1] == 1) && a[i][2] == 3)
	{
		a[i][0] = 2;
		a[i][1] = 1;
	}
}

// check combinations for 3 and 1 vertical question
//1, 2, 3 in the third position
//or 1 in the first and second positions
//---------
//3, 1:  [1, 3, 2, 4]
//3, 1:  [2, 1, 3, 4]
//3, 1:  [2, 3, 1, 4]
void	answer_v_3_1_additionals(int v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_v_3_1_additionals_1_2_3(v, a, i);
		if ((v[i][0] == 3 && v[i][1] == 1) && a[0][i] == 1)
		{
			a[1][i] = 3;
			a[2][i] = 2;
		}
		if ((v[i][0] == 3 && v[i][1] == 1) && a[1][i] == 1)
		{
			a[0][i] = 2;
			a[2][i] = 3;
		}
		i++;
	}
}

void	answer_v_3_1_additionals_1_2_3(int v[4][2], int a[4][4], int i)
{
	if ((v[i][0] == 3 && v[i][1] == 1) && a[2][i] == 1)
	{
		a[0][i] = 2;
		a[1][i] = 3;
	}
	if ((v[i][0] == 3 && v[i][1] == 1) && a[2][i] == 2)
	{
		a[0][i] = 1;
		a[1][i] = 3;
	}
	if ((v[i][0] == 3 && v[i][1] == 1) && a[2][i] == 3)
	{
		a[0][i] = 2;
		a[1][i] = 1;
	}
}
