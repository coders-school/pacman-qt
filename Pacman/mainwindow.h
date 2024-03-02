#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory> // Include for std::unique_ptr

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void startGameSelected(); // Declare the signal

private slots:
  void on_StartGameButton_clicked();

  void on_ExitButton_clicked();

private:
  std::unique_ptr<Ui::MainWindow> ui; // Changed to unique_ptr
};
#endif // MAINWINDOW_H
