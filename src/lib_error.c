#include "ftls.h"
#include <stdio.h>

void	ft_error_option(char c)
{
	ft_printf("warning option '%c' is unsupported\n", c);
}

void	ft_error_dir(char *s)
{
	ft_printf("ls: %s: no such file or directory\n", s);
}
