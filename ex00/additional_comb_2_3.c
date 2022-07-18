/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_comb_2_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:53:32 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:53:35 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	answer_v_2_3_additionals_1_2_3(int v[4][2], int a[4][4], int i);
void	answer_h_2_3_additionals_1_2_3(int h[4][2], int a[4][4], int i);

// verifica as combinações adicionais possíveis de 2 e 3 vertical
// 1, 2 e 3 na primeira casa
// 2 na terceira ou última casa
// -----------------------------
// 2, 3:  [1, 4, 3, 2]
// 2, 3:  [2, 4, 3, 1]
// 2, 3:  [3, 4, 2, 1]
void	answer_v_2_3_additionals(int v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_v_2_3_additionals_1_2_3(v, a, i);
		if ((v[i][0] == 2 && v[i][1] == 3) && a[3][i] == 2)
		{
			a[2][i] = 3;
			a[0][i] = 1;
		}
		if ((v[i][0] == 2 && v[i][1] == 3) && a[2][i] == 2)
		{
			a[0][i] = 3;
			a[3][i] = 1;
		}
		i++;
	}
}

void	answer_v_2_3_additionals_1_2_3(int v[4][2], int a[4][4], int i)
{
	if ((v[i][0] == 2 && v[i][1] == 3) && a[0][i] == 1)
	{
		a[2][i] = 3;
		a[3][i] = 2;
	}
	if ((v[i][0] == 2 && v[i][1] == 3) && a[0][i] == 2)
	{
		a[2][i] = 3;
		a[3][i] = 1;
	}
	if ((v[i][0] == 2 && v[i][1] == 3) && a[0][i] == 3)
	{
		a[2][i] = 2;
		a[3][i] = 1;
	}	
}

// verifica as combinações adicionais possíveis de 2 e 3 horizontal
// 1, 2 e 3 na primeira
// 2 na terceira ou última casa
// -----------------------------
//2, 3:  [1, 4, 3, 2]
//2, 3:  [2, 4, 3, 1]
//2, 3:  [3, 4, 2, 1]
void	answer_h_2_3_additionals(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		answer_h_2_3_additionals_1_2_3(h, a, i);
		if ((h[i][0] == 2 && h[i][1] == 3) && a[i][2] == 2)
		{
			a[i][0] = 3;
			a[i][3] = 1;
		}
		if ((h[i][0] == 2 && h[i][1] == 3) && a[i][3] == 2)
		{
			a[i][0] = 1;
			a[i][2] = 3;
		}
		i++;
	}
}

void	answer_h_2_3_additionals_1_2_3(int h[4][2], int a[4][4], int i)
{
	if ((h[i][0] == 2 && h[i][1] == 3) && a[i][0] == 1)
	{
		a[i][2] = 3;
		a[i][3] = 2;
	}
	if ((h[i][0] == 2 && h[i][1] == 3) && a[i][0] == 2)
	{
		a[i][2] = 3;
		a[i][3] = 1;
	}
	if ((h[i][0] == 2 && h[i][1] == 3) && a[i][0] == 3)
	{
		a[i][2] = 2;
		a[i][3] = 1;
	}
}
