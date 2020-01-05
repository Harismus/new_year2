#pragma once

#include <QObject>
#include <QScreen>

/**
 * @brief The MonitorsSize class этот клдасс определяет размеры экрана
 */
class MonitorsSize : public QObject
{
    Q_OBJECT
public:
    explicit MonitorsSize(QObject *parent = nullptr);
    int size();
    static QSize getQSizeAt(const int &n);
    QRect getQRectAt(const int &n);
    int getWidthAt(int n);
    int getHeightAt(int n);
private:
    QList<QScreen *> listScreen;
};
