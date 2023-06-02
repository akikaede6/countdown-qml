#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include "CountDown.h"

class QMediaPlayer;
class MusicPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MusicPlayer(const CountDown& countDown, QObject *parent = nullptr);

signals:

public slots:
    void onSetSource(int index);
    void onStart();
    void onPause();
    void onCancel();

private:
    QMediaPlayer *m_player;
    const QList<QString> m_bgmList = {"qrc:/music/bgm1.mp3",
                                      "qrc:/music/bgm2.mp3",
                                      "qrc:/music/bgm3.mp3"};
};

#endif // MUSICPLAYER_H
