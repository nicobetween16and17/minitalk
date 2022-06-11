/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:07:15 by niespana          #+#    #+#             */
/*   Updated: 2022/06/11 17:07:17 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <zconf.h>
#include <stdio.h>

void	free_all(char **message, int i)
{
	i = -1;
	while (message[++i])
		free(message[i]);
}

int	char_tobinary(unsigned char a, int bit)
{
	int	chari;
	int	limit;

	chari = a;
	limit = 7;
	while (limit-- > bit)
		chari /= 2;
	return (chari % 2);
}

char	**send_message(unsigned char *av)
{
	int		i;
	int		j;
	char	**binary;

	binary = malloc(sizeof(unsigned char *) * (ft_strlen((char *)av) + 1));
	i = -1;
	while (av[++i])
		binary[i] = malloc(sizeof(unsigned char) * 9);
	binary[i] = 0;
	i = -1;
	while (binary[++i])
	{
		j = 0;
		while (j < 8)
		{
			binary[i][j] = (char_tobinary(av[i], j) + 48);
			j++;
		}
	}
	binary[i] = 0;
	return (binary);
}

int	main(int ac, char **av)
{
	char	**message;
	int		i;
	int		j;
	int		serv;

	serv = ft_atoi(av[1]);
	i = -1;
	if (ac != 3)
		return (0);
	message = send_message((unsigned char *)av[2]);
	while (message[++i])
	{
		j = -1;
		while (message[i][++j])
		{
			if (message[i][j] == '0')
				kill(serv, SIGUSR1);
			else
				kill(serv, SIGUSR2);
			usleep(200);
		}
	}
	free_all(message, -1);
}
