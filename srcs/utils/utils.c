#include <unistd.h>

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

void	ft_putstr_fd(int fd, char *s)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

void	ft_putstr(char *s)
{
	ft_putstr_fd(STDOUT_FILENO, s);
}
