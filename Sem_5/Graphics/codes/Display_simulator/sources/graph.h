#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QHBoxLayout>
#include <iostream>
#include <utility>
using namespace std;

class Graph : public QGraphicsView
{
    Q_OBJECT

    int pixelsize;
    int no_of_pixels;
    int mouseclickStatus;
    pair<float, float> points[2];

    class MyGraphicsScene : public QGraphicsScene
    {
        QGraphicsTextItem *cursor;
        Graph *parent;

    public:
        MyGraphicsScene(Graph *p)
        {
            parent = p;
        }

        void mousePressEvent(QGraphicsSceneMouseEvent *event)
        {
                int x = event->scenePos().x();
                int y = event->scenePos().y();
                emit parent->pointSelect(pair<int, int>(x, y));
        }
    };

    MyGraphicsScene *graphscene;

    void GenerateGraph()
    {
        graphscene = new MyGraphicsScene(this);
        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            for (int j = -no_of_pixels / 2; j <= no_of_pixels / 2; j++)
            {
                graphscene->addRect(i * pixelsize, j * pixelsize, pixelsize, pixelsize);
            }
        }

        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            QGraphicsItem *item = graphscene->itemAt(i * pixelsize, 0, QTransform());
            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);
            if (rect == NULL)
            {
                cout << "rect is null at " << i << " "
                     << "0" << endl;
            }
            QBrush br(Qt::SolidPattern);
            br.setColor(Qt::lightGray);
            rect->setBrush(br);
            rect->update();
        }

        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            QGraphicsItem *item = graphscene->itemAt(0, i * pixelsize, QTransform());
            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);
            if (rect == NULL)
            {
                cout << "rect is null at " << i << " "
                     << "0" << endl;
            }
            QBrush br(Qt::SolidPattern);
            br.setColor(Qt::lightGray);
            rect->setBrush(br);
            rect->update();
        }
        this->setScene(graphscene);
        mouseclickStatus = 0;
    }

public:
    Graph(int p = 5, int n = 100)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }

    void GraphPointPaint(int x, int y)
    {
        if (abs(x) > no_of_pixels / 2 && abs(y) > no_of_pixels / 2)
        {
            cout << "pixel coordinates: (" << x << "," << y << ") incorrect" << endl;
            return;
        }
        else
        {
            QGraphicsItem *item = graphscene->itemAt(x * pixelsize, y * pixelsize, QTransform());
            if (item == NULL)
            {
                cout << "pixel coordinates: (" << x << "," << y << ") incorrect" << endl;
                return;
            }

            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);

            QBrush *br = new QBrush(Qt::SolidPattern);
            br->setColor(Qt::blue);
            rect->setBrush(*br);
            rect->update();
        }
    }

    void GraphReset()
    {
        GenerateGraph();
    }

    void GraphReset(int p, int n)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }

public:
signals:
    void pointSelect(pair<int, int>);

public slots:
    void GraphResetSlot(int p, int n)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }
};