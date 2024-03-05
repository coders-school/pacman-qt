#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>

namespace Ui {
class gameScreen;
}

class gameScreen : public QMainWindow {
  Q_OBJECT

public:
  explicit gameScreen(QWidget *parent = nullptr);
  ~gameScreen();

signals:
  void backToMenuScreen(); // Declare the signal

private slots:
  void on_backButton_clicked();

private:
  Ui::gameScreen *ui;
};

#endif // GAMESCREEN_H
