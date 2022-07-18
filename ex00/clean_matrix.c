/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:42:45 by etachott          #+#    #+#             */
/*   Updated: 2022/07/16 19:45:54 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	clean_matrix(int a[4][4]);

void	clean_matrix(int a[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a[i][j] = 0;
			j++;
		}
		i++;
	}
}