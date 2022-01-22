CC = gcc
ARG = -O0
OBJ = main.o table.o
BIN = main

all: $(BIN)

main: $(OBJ)
	$(CC) $(ARG) $(OBJ) -o $(BIN)

*.o: *.o
	$(CC) $(ARG) -c $< -o $@

clean:
	$(RM) main *.o $(BIN).exe