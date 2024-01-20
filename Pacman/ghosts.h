#ifndef GHOSTS_H
#define GHOSTS_H

#include <QObject>

class Ghosts : public QObject {
    Q_OBJECT

public:
    Ghosts();
    void move(); // Implement ghost movement logic
    void animate(); // Animate ghost
    void chasePlayer(); // Implement AI for chasing player
    void reset(); // Reset the ghost's state
    void setMode(int mode); // Set the mode of the ghost (chase, scatter, frightened)
    void resetPosition(); // Reset the ghost's position to its initial state

private:
    void updatePosition(); // Update the ghost's position based on the AI strategy
    void checkCollisionWithPlayer(); // Check if the ghost has collided with the player
    void checkCollisionWithWalls(); // Check if the ghost has collided with a wall
    void updateMode(); // Update the mode based on game state
    // TODO: Private member variables for AI strategy, position, mode, etc.
};

#endif // GHOSTS_H
