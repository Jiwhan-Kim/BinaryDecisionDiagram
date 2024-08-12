CC = gcc
SRCs := $(wildcard *.c)

OBJs := $(SRCs:.c=.o)

.PHONY: all clean
.DEFAULT_GOAL: all

all: main.out

main.out: $(OBJs)
	$(CC) -o $@ $^

%.o: %.cu
	$(CC) -o $@ -c $^ 

clean:
	rm *.o main.out
