#include "Libft/libft.h"
#include <signal.h>
#include <zconf.h>
#include <stdio.h>

void	free_all(char **message, int i)
{
	i = -1;
	while (message[++i])
		free(message[i]);
}

int	char_tobinary(char a, int bit)
{
	int	chari;
	int	limit;

	chari = a;
	limit = 7;
	while (limit-- > bit)
		chari /= 2;
	return (chari % 2);
}

char	**send_message(char *av)
{
	int		i;
	int		j;
	char	**binary;

	binary = malloc(sizeof(char *) * (ft_strlen(av) + 1));
	i = -1;
	while (av[++i])
		binary[i] = malloc(sizeof(char) * 9);
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

	serv = ft_atoi(av[2]);
	i = -1;
	if (ac != 3)
		return (0);
	message = send_message(av[1]);
	while (message[++i])
	{
		j = -1;
		while (message[i][++j])
		{
			if (message[i][j] == '0')
				kill(serv, SIGUSR1);
			else
				kill(serv, SIGUSR2);
			usleep(40);
		}
	}
	free_all(message, -1);
}
