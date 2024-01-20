#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QMediaPlayer>

class AudioManager : public QObject {
    Q_OBJECT

public:
  AudioManager();
  ~AudioManager();

  void playSoundEffect(const QString &soundEffect);
  void playMusic();
  void stopSoundEffect(QMediaPlayer *player);
  void stopMusic(QMediaPlayer *musicPlayer);
  void setVolume(int newVolume);
  void mute();   // Mute all audio
  void unmute(); // Unmute all audio

private:
    void initAudio(); // Initialize the audio system
    void loadSoundEffects(); // Load sound effects from files
    void loadMusicTracks(); // Load music tracks from files
    // TODO: Private member variables for audio settings, sound effects, music tracks, etc.
    int volume;
    QMediaPlayer *soundEffectPlayer;
    QMediaPlayer *musicPlayer;
    QStringList musicTrackList;
    int currentTrackIndex;
};

#endif // AUDIOMANAGER_H
