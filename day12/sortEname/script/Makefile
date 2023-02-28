CC = gcc
CFLAGS = -Wall -c -g
LDFLAGS = -o

INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin


IFLAGS = -I $(INC)


main: $(OBJ)/main.o $(OBJ)/myFunctions.o
	$(CC) $(LDFLAGS) $(BIN)/main $(OBJ)/main.o $(OBJ)/myFunctions.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/myFunctions.o: $(SRC)/myFunctions.c
	$(CC) $(CFLAGS) $(SRC)/myFunctions.c $(IFLAGS)
	mv myFunctions.o $(OBJ)/

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"


