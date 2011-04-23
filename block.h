#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>

class Block : public QGraphicsRectItem
{
public:
    explicit Block(qreal x, qreal y, QColor &color, QGraphicsItem *parent = 0);

    static const QPointF getPoint(const qreal &x, const qreal &y);

    static const int length = 10;
    static const int padding = 2;

private:
    QPointF pos;

};

#endif // BLOCK_H
