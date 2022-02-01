CC = gcc
ARG = -O2
OBJ = main.o tableOps.o gameOps.o dev.o
BIN = game

all: $(BIN)

game: $(OBJ)
	$(CC) $(ARG) $(OBJ) -o $(BIN)

*.o: *.c
	$(CC) $(ARG) -c $< -o $@

clean:
	$(RM) main *.o $(BIN).exe
