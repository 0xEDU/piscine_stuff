/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:40:29 by lphelipe          #+#    #+#             */
/*   Updated: 2022/07/17 21:40:31 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		has_repetitions(int a[4][4]);

int	try_h_in_the_middle(int a[4][4], int l, int n1, int n2)
{
	a[l][1] = n1;
	a[l][2] = n2;
	if (has_repetitions(a) != 0)
	{
		a[l][1] = n2;
		a[l][2] = n1;
	}
	else
	{
		return (1);
	}
	if (has_repetitions(a) != 0)
	{
		a[l][1] = 0;
		a[l][2] = 0;
		return (0);
	}
	else
	{
		return (1);
	}
}

int	try_v_in_the_middle(int a[4][4], int c, int n1, int n2)
{
	a[1][c] = n1;
	a[2][c] = n2;
	if (has_repetitions(a) != 0)
	{
		a[1][c] = n2;
		a[2][c] = n1;
	}
	else
	{
		return (1);
	}
	if (has_repetitions(a) != 0)
	{
		a[1][c] = 0;
		a[2][c] = 0;
		return (0);
	}
	else
	{
		return (1);
	}
}

int	try_h_in_the_edges(int a[4][4], int l, int n1, int n2)
{
	a[l][0] = n1;
	a[l][3] = n2;
	if (has_repetitions(a) != 0)
	{
		a[l][0] = n2;
		a[l][3] = n1;
	}
	else
	{
		return (1);
	}
	if (has_repetitions(a) != 0)
	{
		a[l][0] = 0;
		a[l][3] = 0;
		return (0);
	}
	else
	{
		return (1);
	}
}
