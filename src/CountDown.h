#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QObject>
#include <QTimer>

class CountDown : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString countText READ showText WRITE setShowText NOTIFY showTextChanged)
    Q_PROPERTY(QString pausetext READ pauseStr WRITE setPauseStr NOTIFY pauseChanged)
public:
    explicit CountDown(QObject *parent = nullptr);

    QString showText() const;
    void setShowText(const QString &newShowText);

    QString pauseStr() const;
    void setPauseStr(const QString &newPauseStr);

signals:
    void showTextChanged();
    void pauseChanged();
    void countFinished();

private slots:
    void onTimeout();

public slots:
    void onTextFieldChanged(const QString &text);
    void onStartBtnClicked();
    void onPauseBtnClicked();
    void onCancelBtnClicked();

private:
    void reset();

private:
    QString m_timeText;
    int m_time;
    QTimer m_timer;

    QString m_showText;
    bool m_isPaused;
    QString m_pauseStr;
};

#endif // COUNTDOWN_H
