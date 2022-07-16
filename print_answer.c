/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:36:34 by etachott          #+#    #+#             */
/*   Updated: 2022/07/16 19:00:36 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	colocar_linha(char a, char b, char c, char d);

void	conversor_de_matriz(int p[4][4], char c[4][4]);

void	print_answer(int a[4][4]);

void	print_answer(int a[4][4])
{
	char	c[4][4];

	conversor_de_matriz(a, c);
	colocar_linha(c[0][0], c[0][1], c[0][2], c[0][3]);
	colocar_linha(c[1][0], c[1][1], c[1][2], c[2][3]);
	colocar_linha(c[2][0], c[2][1], c[2][2], c[1][3]);
	colocar_linha(c[3][0], c[3][1], c[3][2], c[3][3]);
}

void	colocar_linha(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, " ", 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, " ", 1);
	write(1, &d, 1);
	write(1, "\n", 1);
}

void	conversor_de_matriz(int p[4][4], char c[4][4])
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			n = p[i][j];
			if (n >= 1 && n <= 4)
				c[i][j] = n + '0';
			else
				c[i][j] = 'x';
			j++;
		}
		i++;
	}
}
