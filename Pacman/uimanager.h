#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>

class UIManager : public QObject {
  Q_OBJECT

public:
  UIManager();
  void createMenu();                  // Create game menu
  void showPauseScreen();             // Display pause screen
  void showEndGameScreen();           // Display end game screen
  void updateScoreDisplay(int score); // Update score and statistics display
  void updateLivesDisplay(int lives); // Update lives display
  void updateLevelDisplay(int level); // Update level display
  void showStartScreen();             // Display start screen
  void showGameOverScreen();          // Display game over screen
  void reset();                       // Reset the UI to its initial state

private:
  void initUI(); // Initialize the UI components
  // TODO: Private member variables for UI components like score display, lives
  // display, level display, etc.
};

#endif // UIMANAGER_H
