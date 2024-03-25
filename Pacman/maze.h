#ifndef MAZE_H
#define MAZE_H

#include <QObject>

class Maze : public QObject {
  Q_OBJECT

public:
  Maze();
  void loadLayout(); // Load labyrinth structure from a file or hard-coded data
  void placeItems(); // Place points and power-ups in the maze
  void checkCollision(); // Check if a player or ghost has collided with a wall
  void
  getItemAtPosition(int x,
                    int y); // Get the item at a specific position in the maze
  void removeItemAtPosition(
      int x, int y); // Remove the item at a specific position in the maze
  void reset();      // Reset the maze to its initial state
  bool isWallAt(int x, int y);  // Implement logic to check if there's a wall at
                                // the given coordinates
  bool isGhostAt(int x, int y); // Implement logic to check if there's a ghost
                                // at the given coordinates
  bool isPelletAt(int x, int y); // Implement logic to check if there's a pellet
                                 // at the given coordinates
  void removePelletAt(
      int x,
      int y); // Implement logic to remove a pellet at the given coordinates
  void removePowerUpAt(
      int x,
      int y); // Implement logic to remove a power-up at the given coordinates
private:
  void initLayout(); // Initialize the maze layout
  void initItems();  // Initialize the items in the maze
  // TODO: Private member variables for maze layout, items, etc.
  char gameMap[20][28];
};

#endif // MAZE_H
