/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_completed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:32:39 by etachott          #+#    #+#             */
/*   Updated: 2022/07/17 19:44:43 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_complete(int a[4][4]);

int	is_complete(int a[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a[i][j] == 0)
			{
				return (0);
			}
			else
			{
				j++;
				continue ;
			}
		}
		i++;
	}
	return (1);
}
