CC = gcc
CFLAGS = -Wall -c -g 
LDFLAGS = -o

INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin

IFLAGS = -I $(INC)


prg03: $(OBJ)/prg03.o $(OBJ)/myFunctions.o
	$(CC) $(LDFLAGS) $(BIN)/prg03 $(OBJ)/prg03.o $(OBJ)/myFunctions.o

$(OBJ)/prg03.o: $(SRC)/prg03.c
	$(CC) $(CFLAGS) $(SRC)/prg03.c $(IFLAGS)
	mv prg03.o $(OBJ)/

$(OBJ)/myFunctions.o: $(SRC)/myFunctions.c
	$(CC) $(CFLAGS) $(SRC)/myFunctions.c $(IFLAGS)
	mv myFunctions.o $(OBJ)/

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"



