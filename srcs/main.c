

#include <unistd.h>
#include <fcntl.h>
#include "./utils/utils.h"

int	main(int argc __attribute__((unused)), char *argv[])
{
#if __DEBUG__
	testargs(1);
#else
	if (!argv[1]) {
		return (1);
	}
#endif
	int fildes = open(argv[1], O_RDONLY);

	if (fildes == -1) {
#if __DEBUG__
		swrite(_STREAM_STDERR, "Something went wrong while opening '%s'\n", argv[1]);
#else
		ft_putstr_fd(STDERR_FILENO, "Something went wrong while opening '");
		ft_putstr_fd(STDERR_FILENO, argv[1]);
		ft_putstr_fd(STDERR_FILENO, "'\n");
#endif
		return (1);
	}


	char temp[1];
	ssize_t read_val = read(fildes, temp, 1);
	if (read_val == -1) {
#if __DEBUG__
		swrite(_STREAM_STDERR, "Something went wrong while reading '%s'\n", argv[1]);
#else
		ft_putstr_fd(STDERR_FILENO, "Something went wrong while reading '");
		ft_putstr_fd(STDERR_FILENO, argv[1]);
		ft_putstr_fd(STDERR_FILENO, "'\n");
#endif
		return (2);
	}
#if __DEBUG__
	swrite(_STREAM_STDOUT, "%c", temp[0]);
#else
	ft_putstr_fd(STDOUT_FILENO, &temp[0]);
#endif

	int close_res = close(fildes);
	if (close_res == -1) {
#if __DEBUG__
		swrite(_STREAM_STDERR, "Something went wrong while closing '%s'\n", argv[1]);
#else
		ft_putstr_fd(STDERR_FILENO, "Something went wrong while closing '");
		ft_putstr_fd(STDERR_FILENO, argv[1]);
		ft_putstr_fd(STDERR_FILENO, "'\n");
#endif
		return (3);
	}
	return (0);
}
