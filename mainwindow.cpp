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

    redrawScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redrawScene()
{
    int level = ui->radioSphere->isChecked() ? getLevel() - 1 : -1;
    int diameter = getDiameter();
    qreal radius = diameter/2;

    // adjust spinbox maximum
    if(level != -1 && ui->spinLvl->maximum() != diameter)
        ui->spinLvl->setMaximum(diameter);

    // level might be too high
    if(level > diameter)
        level = diameter - 1;

    int max = diameter < prev_diameter ? prev_diameter : diameter;
    for(int y = 0; y < max; ++y) {
        for(int x = 0; x < max; ++x) {
            qreal px = x - max/2, py = y - max/2, pz = level != -1 ? level - max/2 : 0;
            QPointF point(px*12, py*12);
            QGraphicsItem *item = scene.itemAt(point);
            if(item) {
                scene.removeItem(item);
                delete item;
            }
            // point inside the circle?
            if(qSqrt(qPow(px, 2) + qPow(py, 2) + qPow(pz, 2)) < radius + 0.5) {
                QColor color = Qt::white;
                if(!px && !py)
                    color = Qt::red;
                else if(!px || !py)
                    color = Qt::green;

                scene.addRect(point.x(), point.y(), 10, 10, QPen(), QBrush(color));
            }
        }
    }

    prev_diameter = diameter;
}

void MainWindow::on_radioSphere_clicked()
{
    ui->spinLvl->setDisabled(false);
}

void MainWindow::on_radioCircle_clicked()
{
    ui->spinLvl->setDisabled(true);
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
