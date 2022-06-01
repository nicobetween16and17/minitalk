#include "Libft/libft.h"
#include <signal.h>
#include <zconf.h>

int	get_scale(int i)
{
	if (i == 0)
		return (1);
	if (i == 1)
		return (2);
	if (i == 2)
		return (4);
	if (i == 3)
		return (8);
	if (i == 4)
		return (16);
	if (i == 5)
		return (32);
	if (i == 6)
		return (64);
	return (128);
}

void	transform(int *bits, int i, int total)
{
	while (i <= 7)
	{
		total += bits[i] * get_scale(i);
		i++;
	}
	ft_putchar_fd(total, 0);
}

void	handle(int num)
{
	static int	bit;
	static int	break_i;
	static int	bits[8];

	if (num == 10)
		num = 0;
	else
		num = 1;
	bits[7 - bit] = num;
	bit++;
	if (bit > 7)
		transform(bits, 0, 0);
	if (bit > 7)
		bit = 0;
}

int	main(void)
{
	while (1)
	{
		signal(SIGUSR1, handle);
		signal(SIGUSR2, handle);
	}
	ft_putchar_fd('\n', 0);
}
