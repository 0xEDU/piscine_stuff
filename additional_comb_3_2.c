/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_comb_3_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:55:50 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:55:51 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	answer_v_3_2_additionals_1_2_3(int v[4][2], int a[4][4], int i);
void	answer_h_3_2_additionals_1_2_3(int h[4][2], int a[4][4], int i);

// verifica as combinações adicionais possíveis de 3 e 2 vertical
// 1, 2 e 3 na última casa
// 2 na primeira ou segunda casa
// -----------------------------
//3, 2:  [1, 2, 4, 3]
//3, 2:  [1, 3, 4, 2]
//3, 2:  [2, 3, 4, 1] 
void	answer_v_3_2_additionals(int v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{	
		answer_v_3_2_additionals_1_2_3(v, a, i);
		if ((v[i][0] == 3 && v[i][1] == 2) && a[0][i] == 2)
		{
			a[1][i] = 3;
			a[3][i] = 1;
		}
		if ((v[i][0] == 3 && v[i][1] == 2) && a[1][i] == 2)
		{
			a[0][i] = 1;
			a[3][i] = 3;
		}
		i++;
	}
}

void	answer_v_3_2_additionals_1_2_3(int v[4][2], int a[4][4], int i)
{
	if ((v[i][0] == 3 && v[i][1] == 2) && a[3][i] == 1)
	{
		a[0][i] = 2;
		a[1][i] = 3;
	}
	if ((v[i][0] == 3 && v[i][1] == 2) && a[3][i] == 2)
	{
		a[0][i] = 1;
		a[1][i] = 3;
	}
	if ((v[i][0] == 3 && v[i][1] == 2) && a[3][i] == 3)
	{
		a[0][i] = 1;
		a[1][i] = 2;
	}
}

// verifica as combinações adicionais possíveis de 3 e 2 horizontal
// 1, 2 e 3 na última casa
// 2 na primeira ou segunda casa
// -----------------------------
//3, 2:  [1, 2, 4, 3]
//3, 2:  [1, 3, 4, 2]
//3, 2:  [2, 3, 4, 1]

void	answer_h_3_2_additionals(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_h_3_2_additionals_1_2_3(h, a, i);
		if ((h[i][0] == 3 && h[i][1] == 2) && a[i][0] == 2)
		{
			a[i][1] = 3;
			a[i][3] = 1;
		}
		if ((h[i][0] == 3 && h[i][1] == 2) && a[i][1] == 2)
		{
			a[i][0] = 1;
			a[i][3] = 3;
		}
		i++;
	}
}

void	answer_h_3_2_additionals_1_2_3(int h[4][2], int a[4][4], int i)
{
	if ((h[i][0] == 3 && h[i][1] == 2) && a[i][3] == 1)
	{
		a[i][0] = 2;
		a[i][1] = 3;
	}
	if ((h[i][0] == 3 && h[i][1] == 2) && a[i][3] == 2)
	{
		a[i][0] = 1;
		a[i][1] = 3;
	}
	if ((h[i][0] == 3 && h[i][1] == 2) && a[i][3] == 3)
	{
		a[i][0] = 1;
		a[i][1] = 2;
	}
}
