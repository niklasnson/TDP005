CC=g++
SRC_DIR=src

CFLAGS=-g -c -std=c++11 -Wall -Wextra -Wpedantic -ggdb -Wno-unused-parameter -I$(SRC_DIR)
LFLAGS=-lSDL2main -lSDL2 -lSDL2_image

all: komradcommand 

komradcommand: game_object.o collisionable.o rotatable.o aabb.o main.o
			$(CC) *.o  $(LFLAGS) -o komradcommand

main.o: $(SRC_DIR)/main.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/main.cc

game_object.o: $(SRC_DIR)/game_object.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/game_object.cc

collisionable.o: $(SRC_DIR)/collisionable.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/collisionable.cc

rotatable.o: $(SRC_DIR)/rotatable.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/rotatable.cc

aabb.o: $(SRC_DIR)/aabb.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/aabb.cc

clean: 
				rm -rf *.o komradcommand

run: 
			./komradcommand
