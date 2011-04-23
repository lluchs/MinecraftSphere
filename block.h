#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>

class Block : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Block(int x, int y, QColor &color, QGraphicsItem *parent = 0);

    static const QPoint getPoint(const int &x, const int &y);

    static const int length = 10;
    static const int padding = 2;

signals:
    void hover(int x, int y);
    void hoverEnd();

private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QPoint pos;

};

#endif // BLOCK_H
