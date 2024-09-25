WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = a4.c
OBJS = $(SRCS:%.c=%.o)

a4: $(OBJS)
	$(GCC) $(OBJS) -o a4

run: a4
	./a4

clean:
	rm -f *.o a4

