#include <iostream>
#include <cctype>

int			main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (++i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
				std::cout << char(std::toupper(argv[i][j++]));
		}
	}
	std::cout << std::endl;
	return (0);
}
