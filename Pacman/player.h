#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "maze.h" // Assuming you have a Maze class
#include "ghosts.h" // Assuming you have a Ghost class

enum Direction { UP, DOWN, LEFT, RIGHT };

class Player : public QObject {
    Q_OBJECT

public:
  Player(Maze *maze);
  void move(int direction); // Implement Pac-Man's movement logic. Direction
                            // could be an enum with UP, DOWN, LEFT, RIGHT
  void animate();           // Implement Pac-Man's animation
  void collectPoint();      // Handle point collection
  void usePowerUp();        // Implement power-up effects
  void checkCollision(
      Maze &maze); // Check if the player has collided with a wall or a ghost
  int getScore();  // Get the current score
  void reset();    // Reset the player's state
  void loseLife(); // Handle life loss
  void gainLife(); // Handle life gain
  void endGame(); // Handle game over (no lives left)

private:
    void updatePosition(int direction); // Update the player's position based on the direction
    void eatPellet(Maze *maze); // Check if the player is on a pellet and eat it
    void eatPowerUp(Maze *maze); // Check if the player is on a power-up and eat it
    void eatGhost(Ghosts *ghost); // Check if the player is on a ghost and eat it
    void updateScore(int points); // Update the score based on eaten pellets and ghosts
    void handleGhostCollision();  // handle collision with ghost
    void handleCoinCollision();   // handle collision with coin
    void handleWallCollision();   // handle collision with wall
    // TODO: Private member variables for position, score, etc.
    Maze *maze;

    int x;             // Current x position
    int y;             // Current y position
    int nextX;         // Next x position
    int nextY;         // Next y position
    int startX;        // Starting x position
    int startY;        // Starting y position
    int score;         // Player's score
    int lives;         // Player's lives
    int pelletValue;   // Value of a pellet
    bool canEatGhosts; // Whether the player can eat ghosts

    const int POWER_UP_VALUE = 50; // Replace 50 with the actual value of a power-up
    const int GHOST_VALUE = 200; // Replace 200 with the actual value of a ghost
};

#endif // PLAYER_H
