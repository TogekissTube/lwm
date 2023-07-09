#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "window.h"

class WindowManager : public QWidget
{
    Q_OBJECT
public:
    explicit WindowManager(QWidget *parent = nullptr);

public slots:
    void createWindow();

private:
    QVBoxLayout *m_layout;
    QPushButton *m_buttonCreateWindow;
};

#endif // WINDOWMANAGER_H

