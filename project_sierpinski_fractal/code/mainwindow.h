#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPair>
#include <QColorDialog>

#include "painter.h"
//#include "triangle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

     Painter* paint;
     QPolygon* polygon;

     bool moving = false;
     bool f = true;
     bool start = false;
     double _dx, _dy;
     QPair<int,int> movingStart;

     bool checkArea(QPoint, QRect);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalMousePress(QPoint);
    void signalMouseRelease();
    void signalMouseMove(QPoint);
    void signalWhell(int);
    void signalAddPoins(QPoint);
    void signalColor();

private:
    Ui::MainWindow *ui;

protected:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void wheelEvent(QWheelEvent*);

private slots:
    void slotMousePress(QPoint);
    void slotMouseRelease();
    void slotMouseMove(QPoint);
    void slotWhell(int);
    void slotAddPoints(QPoint);
    void slotColor();
    void on_cb_nAuto_stateChanged(int arg1);
    void on_sb_n_valueChanged(int arg1);
    void on_pb_clear_clicked();
    void on_pb_saveAs_clicked();
    void on_pb_update_clicked();
    void on_cb_choosePoint_stateChanged(int arg1);
    void on_cb_fill_stateChanged(int arg1);
    void on_cb_showGrid_stateChanged(int arg1);
    void on_cb_setZ_stateChanged(int arg1);
    void on_pb_default_clicked();
};

#endif // MAINWINDOW_H
