#ifndef TEXTMODEL_H
#define TEXTMODEL_H

#include <QObject>

class TextModel : public QObject
{
    Q_OBJECT
public:
    explicit TextModel(QObject *parent = nullptr);

signals:

};

#endif // TEXTMODEL_H
