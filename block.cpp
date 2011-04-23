#include "block.h"

#include <QBrush>

Block::Block(qreal x, qreal y, QColor &color, QGraphicsItem *parent) :
    QGraphicsRectItem(x*(length+padding), y*(length+padding), qreal(length), qreal(length), parent)
{
    setBrush(QBrush(color));
    pos.setX(x);
    pos.setY(y);
}

const QPointF Block::getPoint(const qreal &x, const qreal &y)
{
    return QPointF(x*(length+padding), y*(length+padding));
}
