/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:27:57 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/16 18:08:19 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	assign_parameters(int h[4][2], int v[4][2], char *argv[]);
void	play(int h[4][2], int v[4][2]);
void	answer_h_1_4_or_4_1(int h[4][2],int a[4][4]);
void	answer_v_1_4_or_4_1(int v[4][2], int a[4][4]);
void	define_h_answer(int a[4], int p1, int p2, int p3, int p4);

int main(int argc, char *argv[])
{
	int h[4][2];
	int v[4][2];

	assign_parameters(h, v, argv);

	play(h, v);
}

void	assign_parameters(int h[4][2], int v[4][2], char *argv[])
{
	v[0][0] = *argv[1] - '0';
	v[1][0] = *argv[2] - '0';
	v[2][0] = *argv[3] - '0';
	v[3][0] = *argv[4] - '0';
	v[0][1] = *argv[5] - '0';
	v[1][1] = *argv[6] - '0';
	v[2][1] = *argv[7] - '0';
	v[3][1] = *argv[8] - '0';
	h[0][0] = *argv[9] - '0';
	h[1][0] = *argv[10] - '0';
	h[2][0] = *argv[11] - '0';
	h[3][0] = *argv[12] - '0';
	h[0][1] = *argv[13] - '0';
	h[1][1] = *argv[14] - '0';
	h[2][1] = *argv[15] - '0';
	h[3][1] = *argv[16] - '0';
}

void	play(int h[4][2], int v[4][2])
{
	int	a[4][4];
	int	i;

	printf("iniciando jogo\n");

	answer_h_1_4_or_4_1(h, a);
	answer_v_1_4_or_4_1(v, a);
}

void	answer_h_1_4_or_4_1(int h[4][2],int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (h[i][0] == 4 && h[i][1] == 1)
		{
			a[i][0] = 1;
			a[i][1] = 2;
			a[i][2] = 3;
			a[i][3] = 4;
			printf("Definiu a linha %d como 1 2 3 4\n", i);
		}
		if (h[i][0] == 1 && h[i][1] == 4)
		{
			a[i][0] = 4;
			a[i][1] = 3;
			a[i][2] = 2;
			a[i][3] = 1;
			printf("Definiu a linha %d como 4 3 2 1\n", i);
		}
		i++;
	}
}

void	answer_v_1_4_or_4_1(int v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if(v[i][0] == 4 && v[i][1] == 1)
		{
			a[0][i] = 1;
			a[1][i] = 2;
			a[2][i] = 3;
			a[3][i] = 4;
			printf("Definiu a coluna %d como 1 2 3 4\n", i);
		}
		if(v[i][0] == 1 && v[i][1] == 4)
		{
			a[0][i] = 4;
			a[1][i] = 3;
			a[2][i] = 2;
			a[3][i] = 1;
			printf("Definiu a coluna %d como 4 3 2 1\n", i);
		}
		i++;
	}
}

