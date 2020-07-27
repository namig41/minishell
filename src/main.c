#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	minishell(argv, env);
	return (0);
}
