#include "player.h"

Player::Player(Maze *maze) : maze(maze) {}

void Player::move(int direction) {
  // Calculate the next position based on the direction
  int nextX = x, nextY = y;
  switch (direction) {
  case UP:
    nextY--;
    break;
  case DOWN:
    nextY++;
    break;
  case LEFT:
    nextX--;
    break;
  case RIGHT:
    nextX++;
    break;
  }

  // Check for collision with a wall
  if (maze->isWallAt(nextX, nextY)) {
    handleWallCollision();
    return;
  }

  // Check for collision with a ghost
  if (maze->isGhostAt(nextX, nextY)) {
    handleGhostCollision();
    return;
  }

  // Check for collision with a pellet
  if (maze->isPelletAt(nextX, nextY)) {
    eatPellet(maze);
  }

  // If there's no collision, move the player
  x = nextX;
  y = nextY;
}

void Player::handleWallCollision() {
  // In Pac-Man, the player simply can't move into a wall, so you might not need
  // to do anything here. Alternatively, you could play a sound effect, show an
  // animation, etc.
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
