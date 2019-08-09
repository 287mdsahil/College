#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QHBoxLayout>
#include <iostream>
using namespace std;

class Graph
{
    QGraphicsScene *graphscene;
    int pixelsize;
    int no_of_pixel;
    QGraphicsView *graphview;

    void GenerateGraph(QGraphicsScene *graphscene, int pixelsize, int no_of_pixels)
    {
        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            for (int j = -no_of_pixels / 2; j <= no_of_pixels / 2; j++)
                graphscene->addRect(i * pixelsize, j * pixelsize, pixelsize, pixelsize);
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
            br.setColor(Qt::black);
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
            br.setColor(Qt::black);
            rect->setBrush(br);
            rect->update();
        }
    }

public:
    Graph(int p = 5, int n = 100)
    {
        graphscene = new QGraphicsScene();
        pixelsize = p;
        no_of_pixel = n;
        GenerateGraph(graphscene, pixelsize, no_of_pixel);
        graphview = new QGraphicsView(graphscene);
    }

    QGraphicsView *getGraph()
    {
        return graphview;
    }

    void GraphPointPaint(int x, int y)
    {
        if (abs(x) > no_of_pixel / 2 && abs(y) > no_of_pixel / 2)
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
        GenerateGraph(graphscene, pixelsize, no_of_pixel);
    }
};