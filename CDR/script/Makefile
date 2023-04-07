CC = gcc
CFLAGS = -Wall -c -g 
LDFLAGS = -o


INC = ./inc/
SRC = ./src
OBJ = ./obj
BIN = ./bin

IFLAGS = -I $(INC)


all: client CDR 

CDR: $(OBJ)/server.o $(OBJ)/myFunction.o 
	$(CC) $(LDFLAGS) $(BIN)/CDR $(OBJ)/server.o $(OBJ)/myFunction.o -pthread


$(OBJ)/server.o: $(SRC)/server.c 
	$(CC) $(CFLAGS) $(SRC)/server.c -pthread $(IFLAGS)
	mv *.o $(OBJ)/

$(OBJ)/myFunction.o: $(SRC)/myFunction.c
	$(CC) $(CFLAGS) $(SRC)/myFunction.c -pthread $(IFLAGS)
	mv *.o $(OBJ)/

client: $(OBJ)/client.o
	$(CC) $(LDFLAGS) $(BIN)/client $(OBJ)/client.o 

$(OBJ)/client.o: $(SRC)/client.c
	$(CC) $(CFLAGS) $(SRC)/client.c 
	mv *.o $(OBJ)/

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
