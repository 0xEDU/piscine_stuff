/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:27:57 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 20:36:00 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_answer(int a[4][4]);
void	convert_argv_to_char_array(char *argv[], char p[16]);
void	assign_parameters(int h[4][2], int v[4][2], char p[16]);
void	clean_matrix(int a[4][4]);
void	play(int h[4][2], int v[4][2], int a[4][4]);
void	answer_h_1_4_or_4_1(int h[4][2], int a[4][4]);
void	answer_v_1_4_or_4_1(int v[4][2], int a[4][4]);
void	answer_h_1_2_or_2_1(int h[4][2], int a[4][4]);
void	answer_v_1_2_or_2_1(int v[4][2], int a[4][4]);
void	answer_h_1_3_or_3_1(int h[4][2], int a[4][4]);
void	answer_v_1_3_or_3_1(int v[4][2], int a[4][4]);
void	answer_h_2_3_or_3_2(int h[4][2], int a[4][4]);
void	answer_v_2_3_or_3_2(int v[4][2], int a[4][4]);
void	answer_v_2_3_additionals(int v[4][2], int a[4][4]);
void	answer_v_3_2_additionals(int v[4][2], int a[4][4]);
void	answer_h_2_3_additionals(int h[4][2], int a[4][4]);
void	answer_h_3_2_additionals(int h[4][2], int a[4][4]);
void	answer_h_1_3_additionals(int h[4][2], int a[4][4]);
void	answer_h_3_1_additionals(int h[4][2], int a[4][4]);
void	answer_v_1_3_additionals(int v[4][2], int a[4][4]);
void	answer_v_3_1_additionals(int v[4][2], int a[4][4]);
void	answer_additional_combinations(int h[4][2], int v[4][2], int a[4][4]);
void	answer_two_two(int h[4][2], int v[4][2], int a[4][4]);
void	fill_varejao(int a[4][4]);
int		check_errors(char p[16], char *argv[], int argc);
int		is_complete(int a[4][4]);

int	main(int argc, char *argv[])
{
	int		h[4][2];
	int		v[4][2];
	char	p[16];
	int		a[4][4];

	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	convert_argv_to_char_array(argv, p);
	if (check_errors(p, argv, argc) == 0)
		return (0);
	assign_parameters(h, v, p);
	clean_matrix(a);
	play(h, v, a);
	if (is_complete(a) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_answer(a);
}

void	play(int h[4][2], int v[4][2], int a[4][4])
{
	int	brutal_iterations;

	brutal_iterations = 0;
	answer_h_1_4_or_4_1(h, a);
	answer_v_1_4_or_4_1(v, a);
	answer_h_1_2_or_2_1(h, a);
	answer_v_1_2_or_2_1(v, a);
	answer_h_1_3_or_3_1(h, a);
	answer_v_1_3_or_3_1(v, a);
	answer_h_2_3_or_3_2(h, a);
	answer_v_2_3_or_3_2(v, a);
	while (brutal_iterations < 5)
	{
		answer_additional_combinations(h, v, a);
		answer_two_two(h, v, a);
		fill_varejao(a);
		if (is_complete(a) != 0)
			return ;
		brutal_iterations++;
	}
}

void	answer_additional_combinations(int h[4][2], int v[4][2], int a[4][4])
{
	answer_v_2_3_additionals(v, a);
	answer_v_3_2_additionals(v, a);
	answer_h_2_3_additionals(h, a);
	answer_h_3_2_additionals(h, a);
	answer_h_1_3_additionals(h, a);
	answer_h_3_1_additionals(h, a);
	answer_v_1_3_additionals(v, a);
	answer_v_3_1_additionals(v, a);
}

void	answer_h_1_4_or_4_1(int h[4][2], int a[4][4])
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

void	answer_v_1_2_or_2_1(int v[4][2], int a[4][4])
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

void	answer_v_1_3_or_3_1(int v[4][2], int a[4][4])
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

void	answer_v_2_3_or_3_2(int v[4][2], int a[4][4])
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
