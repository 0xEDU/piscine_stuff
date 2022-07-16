/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_argv_to_char_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:51:44 by etachott          #+#    #+#             */
/*   Updated: 2022/07/16 20:00:09 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	convert_argv_to_char_array(char *argv[], char p[16]);

void	convert_argv_to_char_array(char *argv[], char p[16])
{
	char	*arg;
	int		i;

	arg = argv[1];
	i = 0;
	while (i < 16)
	{
		p[i] = *arg;
		arg = arg + 2;
		i++;
	}
}
