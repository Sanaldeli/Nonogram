CC = gcc
ARG = -O0
OBJ = main.o tableOps.o gameOps.o dev.o
BIN = game

all: $(BIN)

game: $(OBJ)
	$(CC) $(ARG) $(OBJ) -o $(BIN)

*.o: *.o
	$(CC) $(ARG) -c $< -o $@

clean:
	$(RM) main *.o $(BIN).exe
