/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varejao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efrangio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:49:07 by efrangio          #+#    #+#             */
/*   Updated: 2022/07/17 18:00:12 by efrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		//printf("Verificando coluna %d\n", i);
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

// verifica as combinações adicionais possíveis de 3 e 2 vertical
// 1, 2 e 3 na última casa
// 2 na primeira ou segunda casa
// -----------------------------
//3, 2:  [1, 2, 4, 3]
//3, 2:  [1, 3, 4, 2]
//3, 2:  [2, 3, 4, 1] 
void	answer_v_3_2_additionals(int v[4][2], int a[4][4])
{
	int i;

	i = 0;
	while (i < 4)
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

// verifica as combinações adicionais possíveis de 3 e 2 horizontal
// 1, 2 e 3 na última casa
// 2 na primeira ou segunda casa
// -----------------------------
//3, 2:  [1, 2, 4, 3]
//3, 2:  [1, 3, 4, 2]
//3, 2:  [2, 3, 4, 1]
void	answer_h_3_2_additionals(int h[4][2], int a[4][4])
{
	int i;

	i = 0;
	while (i < 4)
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
