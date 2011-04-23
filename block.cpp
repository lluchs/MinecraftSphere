#include "block.h"

#include <QBrush>

Block::Block(int x, int y, QColor &color, QGraphicsItem *parent) :
    QGraphicsRectItem(x*(length+padding), y*(length+padding), int(length), int(length), parent)
{
    setBrush(QBrush(color));
    setAcceptHoverEvents(true);

    pos.setX(x);
    pos.setY(y);
}

void Block::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit hover(pos.x(), pos.y());
}

void Block::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit hoverEnd();
}

const QPoint Block::getPoint(const int &x, const int &y)
{
    return QPoint(x*(length+padding), y*(length+padding));
}
