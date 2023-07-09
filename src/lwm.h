#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QWidget>

class WindowManager : public QWidget
{
    Q_OBJECT
public:
    explicit WindowManager(QWidget *parent = nullptr);

public slots:
    void createWindow();
    void moveWindow(int x, int y);
    void closeWindow();

private:
    // Variables y métodos privados según tus necesidades
};

#endif // WINDOWMANAGER_H

