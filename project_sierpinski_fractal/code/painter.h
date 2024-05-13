#ifndef PAINTER_H
#define PAINTER_H

#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QMessageBox>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include <qrandom.h>
#include <random>
#include <QRandomGenerator>
#include <QColor>
#include <QTime>

#include <math.h>

class Painter
{
    QPixmap* pixmap;
    QPainter* painter;
    QLabel* lable;
    QPointF A, B, C;
    QVector<QPointF> points;
    QColor color = Qt::black;
    int n;

    int pixmapHeight;
    int pixmapWidht;
    bool autoChooseN;
    bool choosePoint;
    bool showGrid;
    bool fill;

    double oX;
    double oY;

    double xMin;
    double xMax;
    double yMin;
    double yMax;

    int globalXmin = -100;
    int globalXmax = 100;
    int globalYmin = -100;
    int globalYmax = 100;

    int countPoints = 0;

    double scale;
    double scaleX;
    double scaleY;

    void clear();
    void drawAxes();
    void drawGrid();

    bool inArea(QPoint, QPoint, QPoint);

    QColor randomColor();

public:
    Painter();
    Painter(QLabel*);

    void init(int = -10, int = 10);
    void init(double, double);
    void setX(int, int);
    void setY(int, int);
    void setX(double, double);
    void setY(double, double);
    void setSize();
    void setO();
    void setO(double, double);
    void setPen(QColor = Qt::black, int = 1);
    void setColor(QColor);
    void calcScale();
    void setAutoChooseN(bool, int = 0);
    void setChoosePoint(bool);
    void setShowGrid(bool);
    void setFill(bool);
    void setPoints(const QPoint&, const QPoint&, const QPoint&);

    double dist(QPoint, QPoint);
    double getScaleX() const;
    double getScaleY() const;
    double getOx() const;
    double getOy() const;
    bool getAutoN() const;
    bool getChoosePoint() const;
    int getSize() const;
    QVector<QPointF> getPoints() const;

    void changeSize();
    void changeO(double);
    void changeO(double, double);
    void changeScale(double);
    void changeScale(double, double);

    void addPoint(QPointF);
    void removeLastPoint();
    void removePoint(QPointF);
    void removePoint(int);
    void removeAll();

    void draw();
    void draw(const QPolygon&);
    void drawFractal(QPointF, QPointF, QPointF, int);
    void drawPoint(QPointF);
    void drawPoint(QPoint);
    void saveChanges();
    void update();
    void setEmptyGraph();
    void saveAs();

    void test();
};

#endif // PAINTER_H
