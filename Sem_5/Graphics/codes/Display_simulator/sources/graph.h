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
    int pointRequestStatus;
    int pointRequestInd;

    class MyGraphicsScene : public QGraphicsScene
    {
        Graph *parent;

    public:
        MyGraphicsScene(Graph *p)
        {
            parent = p;
        }

        void mousePressEvent(QGraphicsSceneMouseEvent *event)
        {
            emit parent->pointSelect(pair<int, int>(event->scenePos().x() / parent->pixelsize, event->scenePos().y() / parent->pixelsize));
            if (parent->pointRequestStatus == 1)
            {
                parent->pointRequestStatus = 0;
                emit parent->sendPoint(pair<int, int>(event->scenePos().x() / parent->pixelsize, event->scenePos().y() / parent->pixelsize), parent->pointRequestInd);
            }
            parent->GraphPointPaint(event->scenePos().x() / parent->pixelsize, event->scenePos().y() / parent->pixelsize);
        }

        void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
        {
            emit parent->pointHover(pair<int, int>(event->scenePos().x() / parent->pixelsize, event->scenePos().y() / parent->pixelsize));
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
    }

public:
    Graph(int p = 5, int n = 100)
    {
        this->setMouseTracking(1);
        pixelsize = p;
        no_of_pixels = n;
        pointRequestStatus = 0;
        GenerateGraph();
    }

    void GraphPointPaint(int x, int y)
    {
        if (abs(x) > no_of_pixels / 2 && abs(y) > no_of_pixels / 2)
        {
            cout << "pixel coordinates: (" << x << "," << y << ") incorrect " << no_of_pixels * pixelsize / 2 << endl;
            return;
        }
        else
        {
            QGraphicsItem *item = graphscene->itemAt(x * pixelsize, y * pixelsize, QTransform());
            if (item == NULL)
            {
                cout << " item at pixel coordinates: (" << x << "," << y << ") not found" << endl;
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
    void pointHover(pair<int, int>);
    void sendPoint(pair<int, int>, int);

public slots:
    void GraphResetSlot(int p, int n)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }

    void pointRequest(int ind)
    {
        pointRequestStatus = 1;
        pointRequestInd = ind;
    }
};