#include "gamescreen.h"
#include "player.h"
#include "ui_gamescreen.h"
#include "wall.h"
#include <QDebug>
#include <QDir>
#include <QGraphicsScene> // Include this
#include <QGraphicsView>
#include <memory> // Include for std::unique_ptr

gameScreen::gameScreen(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::gameScreen) {
  ui->setupUi(this);

  // Tworzenie widgetu dla obrazu
  QDir dir = QDir::current();
  while (!dir.exists("Assets") && dir.cdUp())
    ;
  QString imagePath = dir.absolutePath() + "/Assets/maze-start.png";
  qDebug() << "Image path: " << imagePath;

  // Ustawienie minimalnej i maksymalnej wysokości backButton
  ui->backButton->setMinimumHeight(40); // Minimalna wysokość to 50 pikseli
  ui->backButton->setMaximumHeight(40); // Maksymalna wysokość to 50 pikseli
  ui->backButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

  // Tworzenie nowego układu QVBoxLayout
  QVBoxLayout *layout = new QVBoxLayout;

  // Dodanie przycisku do układu
  layout->addWidget(ui->backButton);

  // Jeśli centralny widget już ma układ, usuń go
  if (ui->centralwidget->layout() != nullptr) {
    delete ui->centralwidget->layout();
  }

  // Ustawienie nowego układu na centralnym widżecie
  ui->centralwidget->setLayout(layout);

  // Create a new scene
  QGraphicsScene *scene = new QGraphicsScene(this);

  // Maze *maze = new Maze(); // Create a new Maze object

  // Create a new player
  Player *player = new Player();
  player->setPos(100, 100);

  scene->addItem(player); // Add the player to the scene
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

  // Create a new wall
  // Wall *wall = new Wall();s

  // // Set the wall's position

  // // Add the wall to the scene
  // scene->addItem(wall);

  // Create a new view to display the scene
  QGraphicsView *view = new QGraphicsView(scene, this);
  view->setStyleSheet("border-image: url(" + imagePath +
                      ") 0 0 0 0 stretch stretch;");
  // Add the view and the backButton to the layout
  layout->insertWidget(0, view); // Add the view at the top of the layout

  // Set the layout on the central widget
  ui->centralwidget->setLayout(layout);
}

gameScreen::~gameScreen() { delete ui; }

void gameScreen::on_backButton_clicked() { emit backToMenuScreen(); }
