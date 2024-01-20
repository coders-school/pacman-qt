#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QObject>
//#include <QSqlDatabase>

class ScoreManager : public QObject {
    Q_OBJECT

public:
    ScoreManager();
    void createDatabase(); // Initialize SQLite database
    void addScore(int score); // Add new score to the database
    void updateScore(int score); // Update existing score in the database
    QList<int> loadScores(); // Retrieve scores from the database
    void saveProgress(); // Save game progress
    void loadProgress(); // Load game progress
    void resetScores(); // Reset all scores

private:
    void initDatabase(); // Initialize the database
    // QSqlDatabase db; // Database for storing scores and progress
    // TODO: Additional member variables for database management
};

#endif // SCOREMANAGER_H
