/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:07:26 by niespana          #+#    #+#             */
/*   Updated: 2022/06/11 17:07:28 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <zconf.h>
#include "ft_printf/ft_printf.h"

int	g_time;

int	get_scale(int i)
{
	int	res;

	res = 1;
	if (i == 0)
		return (1);
	while (i)
	{
		res *= 2;
		i--;
	}
	return (res);
}

unsigned char	transform(int *bits, int i, int total)
{
	while (i <= 7)
	{
		total += bits[i] * get_scale(i);
		i++;
	}
	return ((unsigned char)total);
}

void	display(unsigned char message[100000][5], int *j, int *k)
{
	int	i;

	i = -1;
	message[*j][*k] = 0;
	while (message[++i][0])
		ft_printf("%s", message[i]);
	*j = 0;
	*k = 0;
}

void	handle(int num)
{
	static int				bit;
	static int				bits[8];
	static unsigned char	message[100000][5];
	static int				j[2];

	g_time = 1;
	if (num == SIGUSR1)
		num = 0;
	else if (num == SIGUSR2)
		num = 1;
	if (num == 0 || num == 1)
	{
		bits[7 - bit] = num;
		bit++;
		if (bit > 7)
			message[j[0]][j[1]++] = transform(bits, 0, 0);
		message[j[0]][j[1]] = 0;
		message[j[0] + 1][0] = 0;
		if (j[1] == 4 && ++j[0])
			j[1] = 0;
		if (bit > 7)
			bit = 0;
	}
	if (j[0] == 99998 || (num == -1 && message[0][0] != 0))
		display(message, &j[0], &j[1]);
}

int	main(void)
{
	g_time = 0;
	ft_putnbr_fd(getpid(), 0);
	write(0, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handle);
		signal(SIGUSR2, handle);
		usleep(10);
		g_time++;
		if (g_time > 10000)
			handle(-1);
	}
}
