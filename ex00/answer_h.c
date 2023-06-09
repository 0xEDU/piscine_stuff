/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:35:55 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:36:03 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
