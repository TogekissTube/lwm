#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMouseEvent>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:
    void moveRequested(const QPoint &pos);
    void minimizeRequested();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QPoint m_dragStartPosition;
};

#endif // WINDOW_H

