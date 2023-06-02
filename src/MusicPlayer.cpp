#include "MusicPlayer.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <iostream>

MusicPlayer::MusicPlayer(const CountDown& countDown, QObject *parent)
    : QObject{parent}
    , m_player(new QMediaPlayer)
{
    QAudioOutput *audioOutput = new QAudioOutput;
    m_player->setAudioOutput(audioOutput);
    m_player->setSource(QUrl(m_bgmList[0]));
    m_player->setLoops(QMediaPlayer::Infinite);
}

void MusicPlayer::onSetSource(int index)
{
    std::cout << __func__ << index << std::endl;
    if (index < m_bgmList.size())
        m_player->setSource(QUrl(m_bgmList[index]));
}

void MusicPlayer::onStart()
{
    m_player->play();
}

void MusicPlayer::onPause()
{
    if (m_player->playbackState() == QMediaPlayer::PausedState)
    {
        m_player->play();
    }
    else if (m_player->playbackState() == QMediaPlayer::PlayingState)
    {
        m_player->pause();
    }
}

void MusicPlayer::onCancel()
{
    m_player->stop();
}
