#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject {
  Q_OBJECT

public:
  Game();
  void startGame();
  void pauseGame();
  void endGame();
  void movePacman(
      int direction); // direction could be an enum with UP, DOWN, LEFT, RIGHT
  void moveGhosts();
  bool checkCollision(); // Check if Pacman has collided with a ghost or a wall
  void eatPellet();      // Check if Pacman is on a pellet and eat it
  void updateScore();    // Update the score based on eaten pellets and ghosts
  void checkWinCondition(); // Check if all pellets have been eaten

private:
  void initGameLoop();
  void initPacman(); // Initialize Pacman's position and state
  void initGhosts(); // Initialize ghosts' positions and states
  void initMaze();   // Initialize the maze with walls and pellets
  // TODO: Add additional private methods and member variables as needed

signals:
  void gameStateChanged();
  void scoreChanged(int newScore); // Signal to update the score display
  void gameWon();                  // Signal when the game is won
  void gameLost();                 // Signal when the game is lost
};

#endif //
