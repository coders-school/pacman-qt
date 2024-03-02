#include "gamescreen.h"
#include "ui_gamescreen.h"

gameScreen::gameScreen(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::gameScreen) {
  ui->setupUi(this);

  // Tworzenie widgetu dla obrazu
  QWidget *imageWidget = new QWidget;
  imageWidget->setStyleSheet(
      "border-image: url(/Users/pawellos/projects/Pacman-Qt/pacman-qt/"
      "Assets/maze-start.png) 0 0 0 0 stretch stretch;");

  // Ustawienie minimalnej i maksymalnej wysokości backButton
  ui->backButton->setMinimumHeight(40); // Minimalna wysokość to 50 pikseli
  ui->backButton->setMaximumHeight(40); // Maksymalna wysokość to 50 pikseli
  ui->backButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

  // Tworzenie nowego układu QVBoxLayout
  QVBoxLayout *layout = new QVBoxLayout;

  // Dodanie widgetu obrazu i przycisku do układu
  layout->addWidget(imageWidget);
  layout->addWidget(ui->backButton);

  // Jeśli centralny widget już ma układ, usuń go
  if (ui->centralwidget->layout() != nullptr) {
    delete ui->centralwidget->layout();
  }

  // Ustawienie nowego układu na centralnym widżecie
  ui->centralwidget->setLayout(layout);
}

gameScreen::~gameScreen() { delete ui; }

void gameScreen::on_backButton_clicked() { emit backToMenuScreen(); }
