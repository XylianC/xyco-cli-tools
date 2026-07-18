CC = gcc
CFLAGS = -Wall -Wextra -g -Iutils

# Paths to shared utility file
UTILS_SRC = utils/xcutils.c
UTILS_DEPS = utils/xcutils.h

# Final binary names
PROGRAMS = xcuecho xculs xcupwd

all: $(PROGRAMS)

%: src/%.c $(UTILS_SRC) $(UTILS_DEPS)
	$(CC) $(CFLAGS) $< $(UTILS_SRC) -o $@

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
