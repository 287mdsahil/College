#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QHBoxLayout>
#include <iostream>
using namespace std;

class Graph : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *graphscene;
    int pixelsize;
    int no_of_pixels;

    void GenerateGraph()
    {
        graphscene = new QGraphicsScene();
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
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }

    QGraphicsView *getGraph()
    {
        return this;
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

    public slots:
    void GraphResetSlot(int p,int n)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }
};