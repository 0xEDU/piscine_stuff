/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varejao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:15:24 by etachott          #+#    #+#             */
/*   Updated: 2022/07/17 20:21:59 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	fill_columns_by_varejao(int a[4][4]);
void	fill_lines_by_varejao(int a[4][4]);
void	fill_line_by_varejao(int l[4]);

void	fill_varejao(int a[4][4])
{
	fill_lines_by_varejao(a);
	fill_columns_by_varejao(a);
}

void	fill_lines_by_varejao(int a[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		fill_line_by_varejao(a[i]);
		i++;
	}
}

void	fill_columns_by_varejao(int a[4][4])
{
	int	c;
	int	l;
	int	soma;
	int	zerados;

	c = 0;
	while (c < 4)
	{
		l = 0;
		zerados = 0;
		soma = 0;
		while (l < 4)
		{
			soma += a[l][c];
			if (a[l][c] == 0)
				zerados++;
			l++;
		}
		l = 0;
		while (l < 4)
		{
			if (zerados == 1 && a[l][c] == 0)
				a[l][c] = 10 - soma;
			l++;
		}
		c++;
	}
}

void	fill_line_by_varejao(int l[4])
{
	int	i;
	int	soma;
	int	zerados;

	i = 0;
	soma = 0;
	zerados = 0;
	while (i < 4)
	{
		soma += l[i];
		if (l[i] == 0)
			zerados ++;
		i++;
	}
	if (zerados == 1)
	{
		i = 0;
		while (i < 4)
		{
			if (l[i] == 0)
				l[i] = 10 - soma;
			i++;
		}
	}
}
