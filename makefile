CC=g++
SRC_DIR=src

CFLAGS=-g -c -std=c++11 -Wall -Wextra -Wpedantic -ggdb -Wno-unused-parameter -I$(SRC_DIR)
LFLAGS=-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

all: komradcommand 

komradcommand: game_object.o game_state.o start.o game.o endgame.o level.o collisionable.o rotatable.o player.o aabb.o main.o missile.o friendly_missile.o house.o static.o marker.o enemy_missile.o sprite.o explosion.o powerup.o text.o
			$(CC) *.o  $(LFLAGS) -o komradcommand

main.o: $(SRC_DIR)/main.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/main.cc

game_state.o: $(SRC_DIR)/game_state.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/game_state.cc

start.o: $(SRC_DIR)/start.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/start.cc
			
game.o: $(SRC_DIR)/game.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/game.cc

endgame.o: $(SRC_DIR)/endgame.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/endgame.cc

level.o: $(SRC_DIR)/level.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/level.cc

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

enemy_missile.o: $(SRC_DIR)/enemy_missile.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/enemy_missile.cc

aabb.o: $(SRC_DIR)/aabb.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/aabb.cc

house.o: $(SRC_DIR)/house.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/house.cc

static.o: $(SRC_DIR)/static.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/static.cc

marker.o: $(SRC_DIR)/marker.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/marker.cc

sprite.o: $(SRC_DIR)/sprite.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/sprite.cc

explosion.o: $(SRC_DIR)/explosion.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/explosion.cc
 
powerup.o: $(SRC_DIR)/powerup.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/powerup.cc

text.o: $(SRC_DIR)/text.cc
				$(CC) $(CFLAGS) $(SRC_DIR)/text.cc



clean: 
				rm -rf *.o komradcommand

run: 
			./komradcommand
