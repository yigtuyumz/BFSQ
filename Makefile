CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCDIR := srcs
OUTDIR := out
OBJS = $(shell find -name '*.o')

PROG_NAME := BFSQ

all: $(OUTDIR) $(PROG_NAME)
	@echo "asdas >> $(OBJS)"
	@printf "Building %s..\n" $(PROG_NAME)
	$(CC) $(OBJS) -o $(PROG_NAME)

$(PROG_NAME): utils
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.c -o $(OUTDIR)/main.o

$(OUTDIR):
	@mkdir $(OUTDIR)

utils:
	@printf "Building utils..\n"
	$(CC) $(CFLAGS) -c $(SRCDIR)/utils/utils.c -o $(OUTDIR)/utils.o

re: clean all

clean:
	@rm -rf $(PROG_NAME)
	@rm -rf $(OUTDIR)