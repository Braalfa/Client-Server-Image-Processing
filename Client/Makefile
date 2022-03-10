CC		= gcc
CFLAGS	= -lulfius -ljansson
RM		= rm -f

all: main

main: main.c
	$(CC) main.c client/client.c -o main  $(CFLAGS)

clean veryclean:
	$(RM) main