.PHONY: clean

all: clean linked_list_example

CFLAGS = -I../common -I.

SRCS = $(wildcard *.c ../common/*.c) ${REFSRC}

OBJS = $(patsubst %.c, %.o, $(SRCS))

linked_list_example: $(OBJS)
	gcc $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) linked_list_example

test: linked_list_example
	valgrind ./linked_list_example
