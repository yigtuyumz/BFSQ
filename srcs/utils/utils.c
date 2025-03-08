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

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		if (nb == -2147483648)
		{
			write(STDOUT_FILENO, "2", 1);
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(STDOUT_FILENO, &"0123456789"[nb % 10], 1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}