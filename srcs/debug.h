#ifndef DEBUG_HEADER
# define DEBUG_HEADER

# include <stdio.h>
# include <stdarg.h>

# define __DEBUG__ 1
# define __ARGC__ 1

# define _STREAM_STDERR "/dev/stderr"
# define _STREAM_STDOUT "/dev/stdout"
# define _STREAM_STDIN "/dev/stdin"
# define _STREAM_NULL "/dev/null"
# define _u __attribute__((unused))


# if __ARGC__
#  define testargs(count) do {													\
	int iter = 0;																\
	while (iter <= count) {														\
		if (argv[iter] == NULL) {												\
			(void) swrite(_STREAM_STDERR,										\
				"argv[%d] must not be NULL! expected argc: %d\n", iter, count);	\
			return (iter);														\
		}																		\
		iter++;																	\
	}																			\
} while (0)
# else //% __ARGC__ == 0
#  define testargs(count)
# endif //% __ARGC__ == 1

int	swrite(const char *file_path, const char *fmt, ...)
	__attribute__((nonnull(1, 2)));

int	swrite(const char *file_path, const char *fmt, ...)
{
	FILE *stream;
	stream = fopen(file_path, "w");
	if (stream == NULL)
		return (-1);
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	int bytes_written = vfprintf(stream, fmt, arg_ptr);
	va_end(arg_ptr);
	fclose(stream);
	return (bytes_written);
}


#endif /* DEBUG_HEADER */