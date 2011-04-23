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

    void blockHover(qreal x, qreal y);
    void blockHoverEnd();

    void on_radioSphere_clicked();
    void on_radioCircle_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene scene;
    int prev_diameter;
};

#endif // MAINWINDOW_H
