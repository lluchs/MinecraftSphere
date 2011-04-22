#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    inline const int getDiameter();
    inline const int getLevel();

public slots:
    void redrawScene();

private:
    Ui::MainWindow *ui;

    QGraphicsScene scene;
    int prev_diameter;

    QPainterPath obsoleteRing(qreal dold, qreal dnew);
};

#endif // MAINWINDOW_H
