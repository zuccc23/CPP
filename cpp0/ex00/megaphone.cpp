#include <iostream>
#include <stdio.h>

int main(int argc, char **argv) {
	(void)argv;
	int	i = 1;
	int	j = 0;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				argv[i][j] -= 32;
			}
			j++;
		}
		i++;
	}
	std::cout << argv[1] << "\n";
	return 0;
}