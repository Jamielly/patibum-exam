#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	flag = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			else
			{
				if (flag)
					write(1, " ", 1);
				while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				{
					write(1, &av[1][i], 1);
					i++;
				}
				flag = 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
