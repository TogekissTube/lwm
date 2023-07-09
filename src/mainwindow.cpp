#include "windowmanager.h"

WindowManager::WindowManager(QWidget *parent) : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    m_buttonCreateWindow = new QPushButton("Create Window", this);
    connect(m_buttonCreateWindow, &QPushButton::clicked, this, &WindowManager::createWindow);

    m_windowsLayout = new QStackedLayout;
    m_layout->addWidget(m_buttonCreateWindow);
    m_layout->addLayout(m_windowsLayout);

    setLayout(m_layout);
}

void WindowManager::createWindow()
{
    Window *window = new Window(this);
    int index = m_windows.size();
    m_windows.append(window);
    m_windowsLayout->addWidget(window);
    connect(window, &Window::moveRequested, this, [=](const QPoint &pos) {
        moveWindow(index, pos);
    });
    connect(window, &Window::minimizeRequested, this, [=]() {
        minimizeWindow(index);
    });

    window->show();
}

void WindowManager::moveWindow(int index, const QPoint &pos)
{
    Window *window = m_windows.at(index);
    QPropertyAnimation *animation = new QPropertyAnimation(window, "pos", this);
    animation->setDuration(500);
    animation->setStartValue(window->pos());
    animation->setEndValue(pos);

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animation);
    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void WindowManager::minimizeWindow(int index)
{
    Window *window = m_windows.at(index);
    QPropertyAnimation *animation = new QPropertyAnimation(window, "geometry", this);
    animation->setDuration(500);
    animation->setStartValue(window->geometry());
    animation->setEndValue(QRect(window->pos(), QSize(100, 30)));

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animation);
    group->start(QAbstractAnimation::DeleteWhenStopped);
}

