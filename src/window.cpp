#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Window");
    setMinimumSize(400, 300);
}

void Window::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragStartPosition = event->globalPos() - frameGeometry().topLeft();
    }
    QWidget::mousePressEvent(event);
}
