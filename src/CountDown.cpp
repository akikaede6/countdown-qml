#include "CountDown.h"

#include <QDebug>
#include <iostream>

CountDown::CountDown(QObject *parent)
    : QObject{parent}
    , m_timeText(QString::number(0))
    , m_time(0)
    , m_showText("00:00")
    , m_isPaused(false)
    , m_pauseStr("Pause")
{
    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &CountDown::onTimeout);
}

void CountDown::onTimeout()
{
    qInfo() << __func__;
    if (m_time > 0)
    {
        int minute = m_time / 60;
        int second = m_time % 60;
        QString minStr = QString::number(minute);
        QString secStr = QString::number(second);
        if (minute < 10)
            minStr = "0" + minStr;
        if (second < 10)
            secStr = "0" + secStr;

        setShowText(QString("%1:%2").arg(minStr).arg(secStr));
        m_time--;
    }
    else
    {
        reset();
    }
}

void CountDown::onTextFieldChanged(const QString &text)
{
    qInfo() << __func__ << text;
    std::cout << text.toStdString() << std::endl;
    m_timeText = text;
}

void CountDown::onStartBtnClicked()
{
    qInfo() << __func__;
    std::cout << __func__ << std::endl;
    bool ok = false;
    m_time = m_timeText.toInt(&ok);
    if (!ok)
        m_time = 0;
    else
        m_time *= 60;

    m_timer.start();
}

void CountDown::onPauseBtnClicked()
{
    qInfo() << __func__;
    std::cout << __func__ << std::endl;
    if (m_isPaused)
    {
        m_timer.start();
        setPauseStr("Pause");
    }
    else
    {
        m_timer.stop();
        setPauseStr("Resume");
    }
    m_isPaused = !m_isPaused;
}

void CountDown::onCancelBtnClicked()
{
    qInfo() << __func__;
    std::cout << __func__ << std::endl;
    reset();
}

void CountDown::reset()
{
    m_isPaused = false;
    m_time = 0;
    setShowText("00:00");
    setPauseStr("Pause");
    m_timer.stop();
}

QString CountDown::pauseStr() const
{
    return m_pauseStr;
}

void CountDown::setPauseStr(const QString &newPauseStr)
{
    if (m_pauseStr != newPauseStr)
    {
        m_pauseStr = newPauseStr;
        emit pauseChanged();
    }
}

QString CountDown::showText() const
{
    return m_showText;
}

void CountDown::setShowText(const QString &newShowText)
{
    if (m_showText != newShowText)
    {
        m_showText = newShowText;
        emit showTextChanged();
    }
}
