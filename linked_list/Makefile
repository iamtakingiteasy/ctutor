.PHONY: clean

all: clean linked_list_example

CFLAGS = -I../linked_list

SRCS = $(wildcard *c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

linked_list_example: $(OBJS)
	gcc $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) linked_list_example

test: linked_list_example
	valgrind ./linked_list_example

