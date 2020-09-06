#include "minishell.h"

static int check_env(char *var)
{
	if (var[0] == '$')
	{
		ft_putstr((char *)getenv(var[0]));
		return (1);
	}
	return (0);
}

static void putecho(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			i++;
			continue ;
		}
		ft_putchar(s[i]);
		i++;
	}
}

void 	cmd_echo(char **argv, char **env)
{
	size_t i;

	i = 1;
	while (argv[i])
	{
		if (!check_env(argv[i]))	
			putecho(argv[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
