CC=g++
SRC_DIR=src

CFLAGS=-g -c -std=c++11 -Wall -Wextra -Wpedantic -ggdb -Wno-unused-parameter -I$(SRC_DIR)
LFLAGS=-lSDL2main -lSDL2 -lSDL2_image

all: komradcommand 

komradcommand: game_object.o collisionable.o rotatable.o player.o aabb.o main.o missile.o friendly_missile.o house.o static.o
			$(CC) *.o  $(LFLAGS) -o komradcommand

main.o: $(SRC_DIR)/main.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/main.cc

game_object.o: $(SRC_DIR)/game_object.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/game_object.cc

collisionable.o: $(SRC_DIR)/collisionable.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/collisionable.cc

rotatable.o: $(SRC_DIR)/rotatable.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/rotatable.cc

player.o: $(SRC_DIR)/player.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/player.cc

missile.o: $(SRC_DIR)/missile.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/missile.cc

friendly_missile.o: $(SRC_DIR)/friendly_missile.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/friendly_missile.cc

aabb.o: $(SRC_DIR)/aabb.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/aabb.cc

house.o: $(SRC_DIR)/house.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/house.cc

static.o: $(SRC_DIR)/static.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/static.cc

clean: 
				rm -rf *.o komradcommand

run: 
			./komradcommand
