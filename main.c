/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:27:57 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/16 20:13:57 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_answer(int a[4][4]);
void	convert_argv_to_char_array(char *argv[], char p[16]);
void	assign_parameters(int h[4][2], int v[4][2], char p[16]);
void	clean_matrix(int a[4][4]);
void	play(int h[4][2], int v[4][2], int a[4][4]);
void	answer_h_1_4_or_4_1(int h[4][2],int a[4][4]);
void	answer_v_1_4_or_4_1(int v[4][2], int a[4][4]);
void	answer_h_1_2_or_2_1(int h[4][2], int a[4][4]);
void	answer_v_1_2_or_2_1(int	v[4][2], int a[4][4]);
void	answer_h_1_3_or_3_1(int h[4][2], int a[4][4]);
void	answer_v_1_3_or_3_1(int	v[4][2], int a[4][4]);
void	answer_h_2_3_or_3_2(int h[4][2], int a[4][4]);
void	answer_v_2_3_or_3_2(int v[4][2], int a[4][4]);

int main(int argc, char *argv[])
{
	int 	h[4][2];
	int 	v[4][2];
	char	p[16];
	int		a[4][4];

	convert_argv_to_char_array(argv, p);
	assign_parameters(h, v, p);
	clean_matrix(a);
	play(h, v, a);
	print_answer(a);
}

void	play(int h[4][2], int v[4][2], int a[4][4])
{
	answer_h_1_4_or_4_1(h, a);
	answer_v_1_4_or_4_1(v, a);
	answer_h_1_2_or_2_1(h, a);
	answer_v_1_2_or_2_1(v, a);
	answer_h_1_3_or_3_1(h, a);
	answer_v_1_3_or_3_1(v, a);
	answer_h_2_3_or_3_2(h, a);
	answer_v_2_3_or_3_2(v, a);
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
		}
		if (h[i][0] == 1 && h[i][1] == 4)
		{
			a[i][0] = 4;
			a[i][1] = 3;
			a[i][2] = 2;
			a[i][3] = 1;
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
		if (v[i][0] == 4 && v[i][1] == 1)
		{
			a[0][i] = 1;
			a[1][i] = 2;
			a[2][i] = 3;
			a[3][i] = 4;
		}
		if (v[i][0] == 1 && v[i][1] == 4)
		{
			a[0][i] = 4;
			a[1][i] = 3;
			a[2][i] = 2;
			a[3][i] = 1;
		}
		i++;
	}
}

void	answer_h_1_2_or_2_1(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (h[i][0] == 2 && h[i][1] == 1)
		{
			a[i][0] = 3;
			a[i][3] = 4;
		}
		if (h[i][0] == 1 && h[i][1] == 2)
		{
			a[i][0] = 4;
			a[i][3] = 3;
		}
		i++;
	}
}

void	answer_v_1_2_or_2_1(int	v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{	
		if (v[i][0] == 2 && v[i][1] == 1)
		{
			a[0][i] = 3;
			a[3][i] = 4;
		}
		if (v[i][0] == 1 && v[i][1] == 2)
		{
			a[0][i] = 4;
			a[3][i] = 3;
		}
		i++;
	}
}

void	answer_h_1_3_or_3_1(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (h[i][0] == 1 && h[i][1] == 3)
			a[i][0] = 4;
		if (h[i][0] == 3 && h[i][1] == 1)
			a[i][3] = 4;
		i++;
	}
}

void	answer_v_1_3_or_3_1(int	v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{	
		if (v[i][0] == 1 && v[i][1] == 3)
			a[0][i] = 4;
		if (v[i][0] == 3 && v[i][1] == 1)
			a[3][i] = 4;
		i++;
	}
}

void	answer_h_2_3_or_3_2(int h[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (h[i][0] == 2 && h[i][1] == 3)
			a[i][1] = 4;
		if (h[i][0] == 3 && h[i][1] == 2)
			a[i][2] = 4;
		i++;
	}
}

void	answer_v_2_3_or_3_2(int	v[4][2], int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{	
		if (v[i][0] == 2 && v[i][1] == 3)
			a[1][i] = 4;
		if (v[i][0] == 3 && v[i][1] == 2)
			a[2][i] = 4;
		i++;
	}
}

