#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>

class ConfigManager : public QObject {
  Q_OBJECT

public:
  ConfigManager();
  void loadSettings();                          // Load settings from a file
  void saveSettings();                          // Save settings to a file
  void applySettings();                         // Apply settings to the game
  void setSetting(QString key, QVariant value); // Set a specific setting
  QVariant getSetting(QString key);             // Get a specific setting

private:
  void initDefaultSettings(); // Initialize default settings
  // TODO: Private member variables for storing configuration settings
  QMap<QString, QVariant> settings;
};

#endif // CONFIGMANAGER_H
