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

void	reset(unsigned char *message, int *j)
{
	*message = 0;
	*j = 0;
}

void	handle(int num)
{
	static int				bit;
	static int				bits[8];
	static unsigned char	message[5];
	static int				j;

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
			message[j++] = transform(bits, 0, 0);
		message[j] = 0;
		if (bit > 7)
			bit = 0;
		if (j == 4 && ft_printf("%s", message))
			reset(&message[0], &j);
	}
	if (num == -1 && message[0] != 0 && ft_printf("%s", message))
		reset(&message[0], &j);
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
		usleep(1);
		g_time++;
		if (g_time > 100000)
			handle(-1);
	}
}
