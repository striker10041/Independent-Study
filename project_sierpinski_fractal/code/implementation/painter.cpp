#include "../painter.h"
#include <QPainterPath>

Painter::Painter()
{

}

Painter::Painter(QLabel* l){
    lable = l;
    pixmapWidht = lable->width();
    pixmapHeight = lable->height();

    pixmap = new QPixmap(pixmapWidht, pixmapHeight);
    painter = new QPainter(pixmap);

    painter->setPen(QPen(Qt::black,1));

    init(0, 1);

    A = QPointF(2, 3);
    B = QPointF(-6, 8);
    C = QPointF(-1, -4);

    points.push_back(A);
    points.push_back(B);
    points.push_back(C);

    countPoints = 3;

}

void Painter::setX(int min, int max){
    xMin = min;
    xMax = max;
}

void Painter::setY(int min, int max){
    yMin = min;
    yMax = max;
}

void Painter::setX(double min, double max)
{
    xMin = min;
    xMax = max;
}

void Painter::setY(double min, double max)
{
    yMin = min;
    yMax = max;
}

void Painter::setO(double x, double y){
    oX = x;
    oY = y;
}

void Painter::setPen(QColor c, int n)
{
    painter->setPen(QPen(c, n));
}

void Painter::setColor(QColor c)
{
    color = c;
}

void Painter::setO(){
    oX = fabs(xMin);
    oY = yMax;
}

void Painter::init(int a, int b){
    setX(a, b);
    setY(a, b);
    setO();
    calcScale();
}

void Painter::init(double a, double b)
{
    setX(a, b);
    setY(a, b);
    setO();
    calcScale();
}

void Painter::clear(){
    painter->eraseRect(0, 0, pixmapWidht, pixmapHeight);
}

void Painter::calcScale(){
    int d = std::max(xMax - xMin, yMax - yMin);
    scale = 1.0 * std::max(pixmapWidht, pixmapHeight) / d;

    scaleX = 1.0 * pixmapWidht / (xMax - xMin);
    scaleY = 1.0 * pixmapHeight / (yMax - yMin);
}

void Painter::setAutoChooseN(bool f, int m)
{
    autoChooseN = f;
    n = m;
}

void Painter::setChoosePoint(bool f)
{
    choosePoint = f;
}

void Painter::setShowGrid(bool f)
{
    showGrid = f;
}

void Painter::setFill(bool f)
{
    fill = f;
}

void Painter::setPoints(const QPoint &a, const QPoint &b, const QPoint &c)
{
    A = QPoint(a);
    B = QPoint(b);
    C = QPoint(c);
    countPoints = 3;
}

double Painter::getScaleX() const
{
    return scaleX;
}

double Painter::getScaleY() const
{
    return scaleY;
}

double Painter::getOx() const
{
    return oX;
}

double Painter::getOy() const
{
    return oY;
}

bool Painter::getAutoN() const
{
    return autoChooseN;
}

bool Painter::getChoosePoint() const
{
    return choosePoint;
}

int Painter::getSize() const
{
    return points.size();
}

QVector<QPointF> Painter::getPoints() const
{
    return points;
}

void Painter::changeO(double d)
{
    oX /= d;
    oY /= d;
}

void Painter::changeO(double dx, double dy)
{
    oX += dx;
    oY += dy;
}

void Painter::changeScale(double d)
{
    scaleX *= d;
    scaleY *= d;
}

void Painter::addPoint(QPointF p)
{
    if(points.size() < 3)
        points.push_back(p);
}

void Painter::removeLastPoint()
{
    if(points.size() > 0)
        points.pop_back();
}

void Painter::removePoint(QPointF p)
{
    if(points.size() > 0)
        points.remove(std::find(points.begin(), points.end(), p) - points.begin());
}

void Painter::removePoint(int i)
{
    if(points.size() > 0)
        points.remove(i);
}

void Painter::removeAll()
{
    points.resize(0);
}

void Painter::drawAxes(){
    QLine l1(oX * scaleX, 0, oX * scaleX, pixmapHeight);
    QLine l2(0, oY * scaleY, pixmapWidht, oY * scaleY);

    painter->drawLine(l1);
    painter->drawLine(l2);

    painter->setPen(QPen(Qt::black,3));
    for(int i = globalXmin; i <= globalXmax; i++){
        painter->drawPoint((oX + i) * scaleX, oY * scaleY);

        if(i == 0){
            painter->drawText((oX + i) * scaleX + 5, oY * scaleY - 5, QString::number(i));
            continue;
        }
        painter->drawText((oX + i) * scaleX - 3, oY * scaleY - 5, QString::number(i));
    }

    for(int i = globalYmin; i <= globalYmax; i++){
        painter->drawPoint(oX * scaleX, (oY + i) * scaleY);

        if(i == 0)continue;
        painter->drawText(oX * scaleX + 5, (oY + i) * scaleY + 5, QString::number(-i));
    }
    painter->setPen(QPen(Qt::black,1));
}

void Painter::drawGrid(){
    for(int i = globalXmin; i <= globalXmax; i++){
        QLine l((oX + i) * scaleX, 0, (oX + i) * scaleX, pixmapHeight);
        painter->drawLine(l);
    }

    for(int i = globalYmin; i <= globalYmax; i++){
        QLine l(0, (oY + i) * scaleY, pixmapWidht, (oY + i) * scaleY);
        painter->drawLine(l);
    }
}

bool Painter::inArea(QPoint a, QPoint b, QPoint c)
{
    auto graphGeometry = lable->geometry();

    int left = std::min({a.x(), b.x(), c.x()});
    int right = std::max({a.x(), b.x(), c.x()});
    int top = std::max({a.y(), b.y(), c.y()});
    int bottom = std::min({a.y(), b.y(), c.y()});

    qDebug() << left << right << top << bottom;
    return !(left > graphGeometry.width() || right < 0 || top > graphGeometry.height() || bottom < 0);
}

QColor Painter::randomColor()
{
    std::srand(QTime::currentTime().msec());

    int r = std::rand() % 256;
    int g = std::rand() % 256;
    int b = std::rand() % 256;

    return QColor(r, g, b);
}

double Painter::dist(QPoint p1, QPoint p2)
{
    return std::hypot(p1.x() - p2.x(), p1.y() - p2.y());
}

void Painter::draw(){
    QPainterPath path;
    bool st = true;
    for (double i = -10; i <= 10; i += 0.01) {
        if(st){
            path.moveTo((i + oX) * scaleX, (oY - i * i) * scaleY);
            st = false;
        }else {
            path.lineTo((i + oX) * scaleX, (oY - i * i) * scaleY);
        }
    }
    QVector<QPoint>v(3);
    for (int i = 0; i < 3; i++) {
        v[i] = QPoint((oX + i * i) * scaleX, (oY + i) * scaleY);
    }
    QPolygon p(v);
    painter->drawPolygon(p);
}

void Painter::draw(const QPolygon &p)
{
    painter->drawPolygon(p);
}

void Painter::drawFractal(QPointF _v1, QPointF _v2, QPointF _v3, int n)
{    
    QPoint v1((_v1.x() + oX) * scaleX, (-_v1.y() + oY) * scaleY);
    QPoint v2((_v2.x() + oX) * scaleX, (-_v2.y() + oY) * scaleY);
    QPoint v3((_v3.x() + oX) * scaleX, (-_v3.y() + oY) * scaleY);

    if(n == 0){
        QPolygon polygon;
        polygon.append(v1);
        polygon.append(v2);
        polygon.append(v3);
        if(fill)
            painter->setBrush(color);
        else
            painter->setBrush(Qt::NoBrush);

        draw(polygon);
        return;
    }

    QPointF s12((_v1.x() + _v2.x()) / 2, (_v1.y() + _v2.y()) / 2);
    QPointF s23((_v2.x() + _v3.x()) / 2, (_v2.y() + _v3.y()) / 2);
    QPointF s31((_v3.x() + _v1.x()) / 2, (_v3.y() + _v1.y()) / 2);


    drawFractal(_v1, s12, s31, n - 1);
    drawFractal(s12, _v2, s23, n - 1);
    drawFractal(s23, _v3, s31, n - 1);
}

void Painter::drawPoint(QPointF p)
{
    painter->drawPoint(QPoint((p.x() + oX) * scaleX, (p.y() + oY) * scaleY));
    saveChanges();
}

void Painter::drawPoint(QPoint p)
{
    painter->drawPoint(p);
    saveChanges();
}

void Painter::saveChanges(){
    lable->setPixmap(*pixmap);
}

void Painter::update()
{
    clear();
    drawAxes();
    if(showGrid)
        drawGrid();

    if(points.size() != 3){
        saveChanges();
        return;
    }

    QPoint a((oX + points[0].x()) * scaleX, (oY + points[0].y()) * scaleY);
    QPoint b((oX + points[1].x()) * scaleX, (oY + points[1].y()) * scaleY);
    QPoint c((oX + points[2].x()) * scaleX, (oY + points[2].y()) * scaleY);

    if(autoChooseN){
        n = std::floor(std::log2(std::min({dist(a, b), dist(b, c), dist(a, c)}) / 4));
        n = std::min(n, 10);
        if(n < 0) n = 0;
    }
    qDebug() << n;
    drawFractal(points[0], points[1], points[2], n);
    saveChanges();
}

void Painter::setEmptyGraph()
{
    clear();
    if(showGrid)
        drawGrid();
    drawAxes();
    saveChanges();
}

void Painter::saveAs()
{
    QString strFilter="*.jpeg";
    QString str = QFileDialog::getSaveFileName(0,
                                    "Сохранить изображение",
                                    "D:\\image.jpeg",
                                    "*.png ;; *.jpg ;; *.bmp ;; *.jpeg",
                                    &strFilter
                                    );

    if (!str.isEmpty()) {
        if (strFilter.contains("jpg")){
            pixmap->save(str, "JPG");
        }
        else
            if (strFilter.contains("bmp")){
                 pixmap->save(str, "BMP");
            }
        else
            if(strFilter.contains("png")){
                pixmap->save(str, "PNG");
            }
        else
            if(strFilter.contains(".jpeg")){
                pixmap->save(str, "JPEG");
            }
    }
}

void Painter::test()
{
    clear();
    drawAxes();
}
