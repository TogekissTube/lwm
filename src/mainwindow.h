#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedLayout>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "window.h"

class WindowManager : public QWidget
{
    Q_OBJECT
public:
    explicit WindowManager(QWidget *parent = nullptr);

public slots:
    void createWindow();
    void moveWindow(int index, const QPoint &pos);
    void minimizeWindow(int index);

private:
    QVBoxLayout *m_layout;
    QPushButton *m_buttonCreateWindow;
    QStackedLayout *m_windowsLayout;
    QList<Window *> m_windows;
};

#endif // WINDOWMANAGER_H

