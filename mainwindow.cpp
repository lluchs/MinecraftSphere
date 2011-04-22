#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    // setup connections
    connect(ui->pushGen, SIGNAL(clicked()), SLOT(redrawScene()));

    prev_diameter = getDiameter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redrawScene()
{
    int diameter = getDiameter();
    qreal radius = diameter/2;

    int max = diameter < prev_diameter ? prev_diameter : diameter;
    for(int y = 0; y < max; ++y) {
        for(int x = 0; x < max; ++x) {
            qreal px = x - max/2, py = y - max/2;
            QPointF point(px*12, py*12);
            QGraphicsItem *item = scene.itemAt(point);
            // point inside the circle?
            if(qSqrt(qPow(px, 2) + qPow(py, 2)) < radius + 0.5) {
                if(!item)
                    scene.addRect(point.x(), point.y(), 10, 10);
            }
            else {
                if(item)
                    delete item;
            }
        }
    }

    prev_diameter = diameter;
}

QPainterPath MainWindow::obsoleteRing(qreal dold, qreal dnew)
{
    QPainterPath path;
    path.addRect(-dold/2, -dold/2, dold, dold);
    path.addRect(-dnew/2, -dnew/2, dnew, dnew);
    return path;
}

const int MainWindow::getDiameter()
{
    int value = ui->spinDia->value();
    if(value % 2 == 0)
        ui->spinDia->setValue(--value);
    return value;
}

const int MainWindow::getLevel()
{
    return ui->spinLvl->value();
}
