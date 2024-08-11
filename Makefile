CC = g++
SRCs := $(wildcard *.cpp)

OBJs := $(SRCs:.cpp=.o)

.PHONY: all clean
.DEFAULT_GOAL: all

all: main.out

main.out: $(OBJs)
	$(CC) -o $@ $^

%.o: %.cu
	$(CC) -o $@ -c $^ 

clean:
	rm *.o main.out
