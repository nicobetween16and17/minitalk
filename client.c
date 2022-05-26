#include "Libft/libft.h"

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

int main(int ac, char **av)
{
	int	i;
	int	j;
	char **binary;

	if (ac != 2)
		return (0);
	binary = malloc(sizeof(char *) * (ft_strlen(av[1]) + 1));
	i = -1;
	while (av[1][++i])
		binary[i] = malloc(sizeof(char) * 9);
	binary[i] = 0;
	i = -1;
	while (binary[++i] )
	{
		j = 0;
		while (j < 8)
		{
			binary[i][j] = (char_tobinary(av[1][i], j) + 48);
			j++;
		}
	}
}