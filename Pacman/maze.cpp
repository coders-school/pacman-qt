#include "maze.h"

const int TILE_SIZE = 20; // Replace 20 with the actual size of a tile

Maze::Maze() {
  char tempMap[20][28] = {
      "111111111111111111111111111", "140000000000000000000000041",
      "101111110111111111110111101", "100000410000000000000140001",
      "101111010111110111110101101", "100001010000000000000101001",
      "101101010111110111110101101", "100001000000000000000001001",
      "101101010101112111010101101", "100000010101g333g1010101011",
      "101101010101g333g1010100001", "101101010101111111010101101",
      "100001000000000000000001001", "101101010111110111110101101",
      "100001010000000000000101001", "101111010111110111110101101",
      "100000410000000000000140001", "101111110111111111110111101",
      "14000000000000p000000000041", "111111111111111111111111111"};

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 28; j++) {
      gameMap[i][j] = tempMap[i][j];
    }
  }
}

bool Maze::isPelletAt(int, int) {
  // Your code here
}

void Maze::removePelletAt(int x, int y) {
  // Your code here
}

void Maze::removePowerUpAt(int x, int y) {
  // Your code here
}

bool Maze::isWallAt(int x, int y) {
  // Implement your logic here to check if there's a wall at the given
  // coordinates Return true if there's a wall, false otherwise
  // Convert the position to gameMap coordinates
  int mapX = x / TILE_SIZE;
  int mapY = y / TILE_SIZE;

  // Check if the position is a wall
  return gameMap[mapY][mapX] == '1';
}

bool Maze::isGhostAt(int x, int y) {
  // Implement your logic here to check if there's a ghost at the given
  // coordinates Return true if there's a ghost, false otherwise
}
