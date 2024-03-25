#ifndef PLAYER_H
#define PLAYER_H

#include "ghosts.h" // Assuming you have a Ghost class
#include "maze.h"   // Assuming you have a Maze class
#include "wall.h"   // Assuming you have a Wall class
#include <QEvent>   // Include the QEvent header file
#include <QGraphicsPixmapItem>
#include <QKeyEvent> // Include the QKeyEvent header file
#include <QObject>
#include <QPainter> // Include the QPainter header file

enum Direction { UP, DOWN, LEFT, RIGHT };

class Player : public QGraphicsPixmapItem {
  // Q_OBJECT

public:
  Player();
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
  void endGame();  // Handle game over (no lives left)

  QRectF boundingRect() const override {
    return QRectF(0, 0, 30, 30); // Set the size of the player
  }

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override {
    painter->drawEllipse(boundingRect()); // Draw the player as a circle
  }

  void focusOutEvent(QFocusEvent *event) override;

protected:
  void keyPressEvent(QKeyEvent *event) override {
    switch (event->key()) {
    case Qt::Key_Left:
      move(LEFT);
      break;
    case Qt::Key_Right:
      move(RIGHT);
      break;
    case Qt::Key_Up:
      move(UP);
      break;
    case Qt::Key_Down:
      move(DOWN);
      break;
    default:
      QGraphicsPixmapItem::keyPressEvent(event);
    }
  }

private:
  void updatePosition(
      int direction); // Update the player's position based on the direction
  void eatPellet(Maze *maze); // Check if the player is on a pellet and eat it
  void
  eatPowerUp(Maze *maze); // Check if the player is on a power-up and eat it
  void eatGhost(Ghosts *ghost); // Check if the player is on a ghost and eat it
  void
  updateScore(int points); // Update the score based on eaten pellets and ghosts
  void handleGhostCollision();                    // handle collision with ghost
  void handleCoinCollision();                     // handle collision with coin
  bool handleWallCollision(int prevX, int prevY); // handle collision with wall
  void initializeGameMap();                       // Initialize the game map
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
  // int gameMap[60][80] = {0}; // Initialize all cells to 0 (wall)
  //  char gameMap[20][28] = {
  //      "111111111111111111111111111", "140000000000000000000000041",
  //      "101111110111111111110111101", "100000410000000000000140001",
  //      "101111010111110111110101101", "100001010000000000000101001",
  //      "101101010111110111110101101", "100001000000000000000001001",
  //      "101101010101112111010101101", "100000010101g333g1010101011",
  //      "101101010101g333g1010100001", "101101010101111111010101101",
  //      "100001000000000000000001001", "101101010111110111110101101",
  //      "100001010000000000000101001", "101111010111110111110101101",
  //      "100000410000000000000140001", "101111110111111111110111101",
  //      "14000000000000p000000000041", "111111111111111111111111111"};

  const int POWER_UP_VALUE =
      50;                      // Replace 50 with the actual value of a power-up
  const int GHOST_VALUE = 200; // Replace 200 with the actual value of a ghost
};

#endif // PLAYER_H
