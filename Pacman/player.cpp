#include "player.h"

const int TILE_SIZE = 20; // Replace 20 with the actual size of a tile

Player::Player() {
  // initializeGameMap();
}

void Player::initializeGameMap() {
  // Initialize all cells to 0 (wall)
  //  for (int i = 0; i < 60; ++i) {
  //    for (int j = 0; j < 80; ++j) {
  //    //  gameMap[i][j] = 1;
  //    }
  //  }
}
// // Set the cells in the middle of the map to 1 (open space)
// for (int i = 10; i < 50; ++i) {
//   for (int j = 10; j < 70; ++j) {
//     gameMap[i][j] = 1;
//   }
// }
//}

void Player::move(int direction) {
  // Calculate the next position based on the direction
  int nextX = QGraphicsItem::x(), nextY = QGraphicsItem::y();
  switch (direction) {
  case LEFT:
    nextX -= 10;
    break;
  case RIGHT:
    nextX += 10;
    break;
  case UP:
    nextY -= 10;
    break;
  case DOWN:
    nextY += 10;
    break;
  }

  // Check if the new position is a wall
  // if (!maze->isWallAt(nextX, nextY)) {
  // No collision, move the player to the new position
  setPos(nextX, nextY);
  // }

  // If there's no collision, move the player
  // setPos(nextX, nextY);
}

//   // Check for collision with a wall
//   if (maze->isWallAt(nextX, nextY)) {
//     handleWallCollision();
//     return;
//   }

//   // Check for collision with a ghost
//   if (maze->isGhostAt(nextX, nextY)) {
//     handleGhostCollision();
//     return;
//   }

//   // Check for collision with a pellet
//   if (maze->isPelletAt(nextX, nextY)) {
//     eatPellet(maze);
//   }

//   // If there's no collision, move the player
//   x = nextX;
//   y = nextY;
// }

void Player::focusOutEvent(QFocusEvent *event) {
  Q_UNUSED(event);
  setFocus();
}

bool Player::handleWallCollision(int nextX, int nextY) {
  // Convert the player's position to gameMap coordinates
  int mapX = nextX / TILE_SIZE;
  int mapY = nextY / TILE_SIZE;

  // Check if the new position is a wall
  // if (gameMap[mapY][mapX] == '1') {
  //     // Collision with a wall, don't move the player
  //     return true;
  // }

  // No collision, move the player to the new position
  setPos(nextX, nextY);
  return false;
}

void Player::handleGhostCollision() {
  // When Pac-Man collides with a ghost, he loses a life.
  loseLife();

  // If Pac-Man has no lives left, end the game.
  if (lives == 0) {
    endGame();
  } else {
    // Otherwise, reset Pac-Man's position to the starting position.
    x = startX;
    y = startY;
  }
}

void Player::eatPellet(Maze *maze) {
  // When Pac-Man eats a pellet, increase the score.
  score += pelletValue;

  // Remove the pellet from the maze.
  maze->removePelletAt(x, y);
}

void Player::eatPowerUp(Maze *maze) {
  // When Pac-Man eats a power-up, increase the score.
  score += POWER_UP_VALUE;

  // Remove the power-up from the maze.
  maze->removePowerUpAt(x, y);

  // Enable Pac-Man to eat ghosts.
  canEatGhosts = true;
}

void Player::eatGhost(Ghosts *ghost) {
  // When Pac-Man eats a ghost, increase the score.
  if (canEatGhosts) {
    score += GHOST_VALUE;

    // Send the ghost back to the ghost house.
    ghost->resetPosition();
  } else {
    // If Pac-Man can't eat ghosts, he loses a life.
    loseLife();
  }
}

void Player::endGame() {
  // Implement your logic here to end the game
}

void Player::loseLife() {
  // Your code here
}
