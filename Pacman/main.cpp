#include "gamescreen.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  gameScreen gamescreen; // Create an instance of your GameScreen window
  QObject::connect(&w, &MainWindow::startGameSelected, [&]() {
    gamescreen.show(); // Show the GameScreen window when the startGameSelected
                       // signal is emitted
    w.hide();          // Hide the MainWindow
  });

  QObject::connect(&gamescreen, &gameScreen::backToMenuScreen, [&]() {
    w.show(); // Show the menu window when the startGameSelected signal is
              // emitted
    gamescreen.hide(); // Hide the game screen window
  });

  w.show();
  return a.exec();
}
