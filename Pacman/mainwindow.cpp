#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(std::make_unique<Ui::MainWindow>()) // Use std::make_unique for
                                             // initialization
{
  ui->setupUi(this);
  // Set vertical layout on the central widget of the main window to center
  // ui->centralwidget->setLayout(ui->verticalLayout);

  // Create a new QWidget to act as a container for your QVBoxLayout
  QWidget *containerWidget = new QWidget;

  // Set the layout of the container widget to your QVBoxLayout
  containerWidget->setLayout(ui->verticalLayout);

  // Create a new QGridLayout for your central widget
  QGridLayout *gridLayout = new QGridLayout;

  // Add the container widget to the grid layout
  gridLayout->addWidget(containerWidget, 1, 1);

  // Add spacers around the container widget to center it
  gridLayout->addItem(
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0,
      0);
  gridLayout->addItem(
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0,
      2);
  gridLayout->addItem(
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2,
      0);
  gridLayout->addItem(
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2,
      2);

  // Get the buttons from the QVBoxLayout
  QPushButton *startGameButton =
      qobject_cast<QPushButton *>(ui->verticalLayout->itemAt(0)->widget());
  QPushButton *exitButton =
      qobject_cast<QPushButton *>(ui->verticalLayout->itemAt(1)->widget());

  // Set the size policy to MinimumExpanding, which means the widget will be as
  // small as possible but can expand
  QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding,
                         QSizePolicy::MinimumExpanding);
  startGameButton->setSizePolicy(sizePolicy);
  exitButton->setSizePolicy(sizePolicy);

  // Set the minimum size of the buttons
  startGameButton->setMinimumSize(
      QSize(130, 70)); // Minimum width of 100 and minimum height of 50
  exitButton->setMinimumSize(
      QSize(130, 70)); // Minimum width of 100 and minimum height of 50
  // Set the layout of the central widget to the grid layout
  ui->centralwidget->setLayout(gridLayout);
}

MainWindow::~MainWindow() {
  // No need to delete ui, it will be automatically deleted.
}

void MainWindow::on_StartGameButton_clicked() { emit startGameSelected(); }

void MainWindow::on_ExitButton_clicked() {
  QApplication::quit(); // Close the application
}
