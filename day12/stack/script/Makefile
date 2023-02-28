
CC = gcc
CFLAGS = -Wall -g -c
LDFLAGS = -o

INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin

IFLAGS = -I $(INC) 
prg1: $(OBJ)/prg1.o $(OBJ)/myFunctions.o
	$(CC) $(LDFLAGS) $(BIN)/prg1 $(OBJ)/prg1.o $(OBJ)/myFunctions.o
$(OBJ)/prg1.o: $(SRC)/prg1.c
	$(CC) $(CFLAGS) $(SRC)/prg1.c $(IFLAGS)
	mv *.o $(OBJ)/
$(OBJ)/myFunctions.o: $(SRC)/myFunctions.c
	$(CC) $(CFLAGS) $(SRC)/myFunctions.c $(IFLAGS)
	mv *.o $(OBJ)/
clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"


