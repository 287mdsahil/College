#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QSignalMapper>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QComboBox>
#include <utility>
#include <vector>
#include <iostream>
#include <chrono>
#include <math.h>
#define PI 3.14159265358979323846
using namespace std;

class AlgoWidget : public QWidget
{
    Q_OBJECT
public:
    QWidget *parent;
    QComboBox *drawingAlgoComboBox;
    vector<QLabel *> pointLabels;
    vector<QPushButton *> pointButtons;
    vector<pair<int, int>> points;
    pair<int, int> clickedPoint;
    QVBoxLayout *algoParentLayout;
    QLabel *timeLabel;
    QPushButton *drawLineButton;
    int algoIndex;

    QLabel *radiusLabel;
    QSpinBox *radiusSpinBox;
    QPushButton *drawCircleButton;

    QLabel *ellipseMajorAxisLabel;
    QLabel *ellipseMinorAxisLabel;
    QSpinBox *ellipseMajorAxisSpinBox;
    QSpinBox *ellipseMinorAxisSpinBox;
    QPushButton *drawEllipseButton;

    //LINE DRAWING-----------------------------------------------------------------

    //parametric line drawing algorithm
    void parametricLineDrawing(pair<int, int> p1, pair<int, int> p2)
    {
        cout << "parametirc line drawing called" << endl;
        int x1 = p1.first, x2 = p2.first;
        int y1 = p1.second, y2 = p2.second;
        double m, b;
        m = double(y2 - y1) / (x2 - x1);
        b = y1 - m * x1;

        if (std::abs(m) <= 1)
        {
            if (x1 > x2)
            {
                //swapPoints
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for (int currX = x1; currX <= x2; ++currX)
            {
                int currY = int(std::round(m * currX + b));
                emit paintPointSignal(pair<int, int>(currX, currY));
            }
        }
        else
        {
            if (y1 > y2)
            {
                //swapPoints
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for (int currY = y1; currY <= y2; ++currY)
            {
                int currX = int(std::round((currY - b) / m));
                emit paintPointSignal(pair<int, int>(currX, currY));
            }
        }
    }

    //DDA Line Drawing algorithm
    void DDA(pair<int, int> p1, pair<int, int> p2)
    {
        cout << "DDA line drawing called" << endl;
        pair<int, int> point1, point2;

        if (p1.first == p2.first)
        {
            int y1 = min(p1.second, p2.second);
            int y2 = max(p1.second, p2.second);
            for (int y = y1; y <= y2; y++)
                emit paintPointSignal(pair<int, int>(p1.first, y));
        }
        else if (p1.second == p2.second)
        {
            int x1 = min(p1.first, p2.first);
            int x2 = max(p1.first, p2.first);
            for (int x = x1; x <= x2; x++)
                emit paintPointSignal(pair<int, int>(x, p1.second));
        }
        else
        {
            float m = (p2.second - p1.second) / (float)(p2.first - p1.first);
            if (fabs(m) < 1)
            {
                float y = p1.second;
                int x = p1.first;
                int incr = abs(p2.first - p1.first) / (p2.first - p1.first);
                while (x != p2.first)
                {
                    emit paintPointSignal(pair<int, int>(x, y));
                    y += m * incr;
                    x = x + incr;
                }
            }
            else
            {
                m = 1 / m;
                float x = p1.first;
                int y = p1.second;
                int incr = abs(p2.second - p1.second) / (p2.second - p1.second);
                while (y != p2.second)
                {
                    emit paintPointSignal(pair<int, int>(x, y));
                    x += m * incr;
                    y = y + incr;
                }
            }
        }
    }

    // Bresenhams line drawing algorithm
    void bresenham(pair<int, int> p1, pair<int, int> p2)
    {
        cout << "Bresenham line drawing called" << endl;
        int x1, y1, x2, y2;
        if (p1.first < p2.first)
        {
            x1 = p1.first;
            x2 = p2.first;
            y1 = p1.second;
            y2 = p2.second;
        }
        else
        {
            x1 = p2.first;
            x2 = p1.first;
            y1 = p2.second;
            y2 = p1.second;
        }
        int m_new = 2 * (y2 - y1);
        int slope_error_new = m_new - (x2 - x1);
        for (int x = x1, y = y1; x <= x2; x++)
        {
            emit paintPointSignal(pair<int, int>(x, y));

            // Add slope to increment angle formed
            slope_error_new += m_new;
            cout << slope_error_new << endl;
            // Slope error reached limit, time to
            // increment y and update slope error.
            if (slope_error_new >= 0)
            {
                y++;
                slope_error_new -= 2 * (x2 - x1);
            }
        }
    }

    //CIRCLE DRAWING ALGORITHM-----------------------------------------------------------------

    void PolarCircle(pair<int, int> p, int r)
    {
        double step = 1 / double(r);
        double angle = 0;
        int xc = p.first;
        int yc = p.second;
        emit paintPointSignal(pair<int, int>(xc, yc));
        while (angle <= PI / 4)
        {
            int x = r * cos(angle);
            int y = r * sin(angle);
            plotAllOctant(xc, yc, x, y);
            angle += step;
        }
    }

    void BresenhamCircle(pair<int, int> p, int r)
    {
        int xc = p.first;
        int yc = p.second;
        int x = 0, y = r;
        int d = 3 - 2 * r;
        plotAllOctant(xc, yc, x, y);
        while (y >= x)
        {
            // for each pixel we will
            // draw all eight pixels

            x++;

            // check for decision parameter
            // and correspondingly
            // update d, x, y
            if (d > 0)
            {
                y--;
                d = d + 4 * (x - y) + 10;
            }
            else
                d = d + 4 * x + 6;
            plotAllOctant(xc, yc, x, y);
        }
    }

    void plotAllOctant(int xc, int yc, int x, int y)
    {
        emit paintPointSignal(pair<int, int>(xc + x, yc + y));
        emit paintPointSignal(pair<int, int>(xc + x, yc - y));
        emit paintPointSignal(pair<int, int>(xc - x, yc - y));
        emit paintPointSignal(pair<int, int>(xc - x, yc + y));
        emit paintPointSignal(pair<int, int>(xc + y, yc + x));
        emit paintPointSignal(pair<int, int>(xc + y, yc - x));
        emit paintPointSignal(pair<int, int>(xc - y, yc + x));
        emit paintPointSignal(pair<int, int>(xc - y, yc - x));
    }

    void MidPointCircle(pair<int, int> p, int r)
    {
        int xc = p.first;
        int yc = p.second;
        int x = r, y = 0;

        emit paintPointSignal(pair<int, int>(xc, yc));

        // When radius is zero only a single
        // point will be printed
        if (r > 0)
        {
            plotAllOctant(xc, yc, x, y);
        }

        // Initialising the value of P
        int P = 1 - r;
        while (x > y)
        {
            y++;

            // Mid-point is inside or on the perimeter
            if (P <= 0)
                P = P + 2 * y + 1;

            // Mid-point is outside the perimeter
            else
            {
                x--;
                P = P + 2 * y - 2 * x + 1;
            }

            // All the perimeter points have already been printed
            if (x < y)
                break;

            // Printing the generated point and its reflection
            // in the other octants after translation
            plotAllOctant(xc, yc, x, y);
        }
    }

    //ELLIPSE DRAWING ALGORITHM---------------------------------------------------

    void EllipseMidPoint(pair<int, int> p, int a, int b)
    {
        int rx = a;
        int ry = b;
        int xc = p.first;
        int yc = p.second;

        float dx, dy, d1, d2, x, y;
        x = 0;
        y = ry;

        // Initial decision parameter of region 1
        d1 = (ry * ry) - (rx * rx * ry) +
             (0.25 * rx * rx);
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;

        // For region 1
        while (dx < dy)
        {

            // Print points based on 4-way symmetry
            plotAllQuadrant(xc, yc, x, y);

            // Checking and updating value of
            // decision parameter based on algorithm
            if (d1 < 0)
            {
                x++;
                dx = dx + (2 * ry * ry);
                d1 = d1 + dx + (ry * ry);
            }
            else
            {
                x++;
                y--;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                d1 = d1 + dx - dy + (ry * ry);
            }
        }

        // Decision parameter of region 2
        d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
             ((rx * rx) * ((y - 1) * (y - 1))) -
             (rx * rx * ry * ry);

        // Plotting points of region 2
        while (y >= 0)
        {

            // Print points based on 4-way symmetry
            plotAllQuadrant(xc, yc, x, y);

            // Checking and updating parameter
            // value based on algorithm
            if (d2 > 0)
            {
                y--;
                dy = dy - (2 * rx * rx);
                d2 = d2 + (rx * rx) - dy;
            }
            else
            {
                y--;
                x++;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                d2 = d2 + dx - dy + (rx * rx);
            }
        }
    }

    void EllipseParametric(pair<int, int> p, int a, int b)
    {
        double step = 1 / double(sqrt(a * a + b * b));
        double angle = 0;
        int xc = p.first;
        int yc = p.second;
        emit paintPointSignal(pair<int, int>(xc, yc));
        while (angle <= PI / 2)
        {
            int x = a * cos(angle);
            int y = b * sin(angle);
            plotAllQuadrant(xc, yc, x, y);
            angle += step;
        }
    }

    void plotAllQuadrant(int xc, int yc, int x, int y)
    {
        emit paintPointSignal(pair<int, int>(xc + x, yc + y));
        emit paintPointSignal(pair<int, int>(xc + x, yc - y));
        emit paintPointSignal(pair<int, int>(xc - x, yc - y));
        emit paintPointSignal(pair<int, int>(xc - x, yc + y));
    }

    //----------------------------------------------------------------------------

    void makelineDrawing()
    {
        points.push_back(pair<int, int>(0, 0));
        points.push_back(pair<int, int>(0, 0));

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("Parametric line drawing");
        drawingAlgoComboBox->addItem("DDA line drawing");
        drawingAlgoComboBox->addItem("Bresenham\'s line drawing");

        algoParentLayout = new QVBoxLayout();
        QGroupBox *pointGroup = new QGroupBox("Points");
        QGridLayout *pointLayout = new QGridLayout();
        pointButtons.push_back(new QPushButton("Select point 1"));
        pointButtons.push_back(new QPushButton("Select point 2"));
        pointLabels.push_back(new QLabel(QString::fromStdString(string(to_string(points[0].first) + ", " + to_string(points[0].second)))));
        pointLabels.push_back(new QLabel(QString::fromStdString(string(to_string(points[1].first) + ", " + to_string(points[1].second)))));
        pointLayout->addWidget(pointButtons[0], 0, 0);
        pointLayout->addWidget(pointButtons[1], 1, 0);
        pointLayout->addWidget(pointLabels[0], 0, 1);
        pointLayout->addWidget(pointLabels[1], 1, 1);
        pointGroup->setLayout(pointLayout);

        QSignalMapper *mapper = new QSignalMapper();
        connect(mapper, SIGNAL(mapped(int)), this, SLOT(makePointRequest(int)));

        mapper->setMapping(pointButtons[0], 0);
        connect(pointButtons[0], SIGNAL(clicked()), mapper, SLOT(map()));

        mapper->setMapping(pointButtons[1], 1);
        connect(pointButtons[1], SIGNAL(clicked()), mapper, SLOT(map()));

        drawLineButton = new QPushButton("Draw Line");
        connect(drawLineButton, SIGNAL(clicked()), this, SLOT(callLineDrawingAlgorithm()));

        timeLabel = new QLabel("Time required: -");

        algoParentLayout->addWidget(drawingAlgoComboBox);
        algoParentLayout->addWidget(pointGroup);
        algoParentLayout->addWidget(drawLineButton);
        algoParentLayout->addWidget(timeLabel);
        setLayout(algoParentLayout);
    }

    void makeCircleDrawing()
    {
        points.push_back(pair<int, int>(0, 0));

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("Parametric circle drawing");
        drawingAlgoComboBox->addItem("Bresenham circle drawing");
        drawingAlgoComboBox->addItem("Mid point circle drawing");

        algoParentLayout = new QVBoxLayout();
        QGroupBox *pointGroup = new QGroupBox("Circle parameters");
        QGridLayout *pointLayout = new QGridLayout();
        pointButtons.push_back(new QPushButton("Select Center"));
        pointLabels.push_back(new QLabel(QString::fromStdString(string(to_string(points[0].first) + ", " + to_string(points[0].second)))));
        radiusLabel = new QLabel("Select Radius");
        radiusSpinBox = new QSpinBox();
        pointLayout->addWidget(pointButtons[0], 0, 0);
        pointLayout->addWidget(pointLabels[0], 0, 1);
        pointLayout->addWidget(radiusLabel, 1, 0);
        pointLayout->addWidget(radiusSpinBox, 1, 1);

        pointGroup->setLayout(pointLayout);

        QSignalMapper *mapper = new QSignalMapper();
        connect(mapper, SIGNAL(mapped(int)), this, SLOT(makePointRequest(int)));

        mapper->setMapping(pointButtons[0], 0);
        connect(pointButtons[0], SIGNAL(clicked()), mapper, SLOT(map()));

        drawCircleButton = new QPushButton("Draw circle");
        connect(drawCircleButton, SIGNAL(clicked()), this, SLOT(callCircleDrawingAlgorithm()));

        timeLabel = new QLabel("Time required: -");

        algoParentLayout->addWidget(drawingAlgoComboBox);
        algoParentLayout->addWidget(pointGroup);
        algoParentLayout->addWidget(drawCircleButton);
        algoParentLayout->addWidget(timeLabel);
        setLayout(algoParentLayout);
    }

    void makeEllipseDrawing()
    {
        points.push_back(pair<int, int>(0, 0));

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("Ellipse mid point drawing");
        drawingAlgoComboBox->addItem("Ellipse parametric Drawing");

        algoParentLayout = new QVBoxLayout();
        QGroupBox *pointGroup = new QGroupBox("Ellipse parameters");
        QGridLayout *pointLayout = new QGridLayout();
        pointButtons.push_back(new QPushButton("Select Center"));
        pointLabels.push_back(new QLabel(QString::fromStdString(string(to_string(points[0].first) + ", " + to_string(points[0].second)))));
        ellipseMajorAxisLabel = new QLabel("Select major axis length");
        ellipseMinorAxisLabel = new QLabel("Select minor axis length");
        ellipseMajorAxisSpinBox = new QSpinBox();
        ellipseMinorAxisSpinBox = new QSpinBox();
        pointLayout->addWidget(pointButtons[0], 0, 0);
        pointLayout->addWidget(pointLabels[0], 0, 1);
        pointLayout->addWidget(ellipseMajorAxisLabel, 1, 0);
        pointLayout->addWidget(ellipseMajorAxisSpinBox, 1, 1);
        pointLayout->addWidget(ellipseMinorAxisLabel, 2, 0);
        pointLayout->addWidget(ellipseMinorAxisSpinBox, 2, 1);

        pointGroup->setLayout(pointLayout);

        QSignalMapper *mapper = new QSignalMapper();
        connect(mapper, SIGNAL(mapped(int)), this, SLOT(makePointRequest(int)));

        mapper->setMapping(pointButtons[0], 0);
        connect(pointButtons[0], SIGNAL(clicked()), mapper, SLOT(map()));

        drawEllipseButton = new QPushButton("Draw Ellipse");
        connect(drawEllipseButton, SIGNAL(clicked()), this, SLOT(callEllipseDrawingAlgorithm()));

        timeLabel = new QLabel("Time required: -");

        algoParentLayout->addWidget(drawingAlgoComboBox);
        algoParentLayout->addWidget(pointGroup);
        algoParentLayout->addWidget(drawEllipseButton);
        algoParentLayout->addWidget(timeLabel);
        setLayout(algoParentLayout);
    }

    AlgoWidget(QWidget *parentPtr, int type)
    {
        parent = parentPtr;
        algoIndex = 0;
        if (type == 0)
        {
            makelineDrawing();
        }
        if (type == 1)
        {
            makeCircleDrawing();
        }
        if (type == 2)
        {
            makeEllipseDrawing();
        }
    }

signals:
    void pointRequest(int);
    void paintPointSignal(pair<int, int>);
    void unPaintPointSignal(pair<int, int>);

public slots:
    void makePointRequest(int ind)
    {
        points[ind] = clickedPoint;
        pointLabels[ind]->setText(QString::fromStdString(string(to_string(points[ind].first) + ", " + to_string(points[ind].second))));
    }

    void receiveClickedPoint(pair<int, int> p)
    {
        emit unPaintPointSignal(clickedPoint);
        clickedPoint = p;
    }

    // function to decide the line drawing algorithm
    void callLineDrawingAlgorithm()
    {
        //start of algo
        algoIndex = drawingAlgoComboBox->currentIndex();
        double tstart = (chrono::system_clock::now().time_since_epoch()).count();
        if (algoIndex == 0)
        {
            parametricLineDrawing(points[0], points[1]);
        }
        if (algoIndex == 1)
        {
            DDA(points[0], points[1]);
        }
        if (algoIndex == 2)
        {
            bresenham(points[0], points[1]);
        }
        double tend = (chrono::system_clock::now().time_since_epoch()).count();
        //end of algo
        timeLabel->setText(QString::fromStdString("Time required : " + to_string((tend - tstart) / 1000000) + " ms"));
    }

    //function to decide the circle drawing algorithm
    void callCircleDrawingAlgorithm()
    {
        double tstart = (chrono::system_clock::now().time_since_epoch()).count();
        int i = drawingAlgoComboBox->currentIndex();
        if (i == 0)
            PolarCircle(points[0], radiusSpinBox->value());
        else if (i == 1)
            BresenhamCircle(points[0], radiusSpinBox->value());
        else if (i == 2)
            MidPointCircle(points[0], radiusSpinBox->value());
        double tend = (chrono::system_clock::now().time_since_epoch()).count();
        //end of algo
        timeLabel->setText(QString::fromStdString("Time required : " + to_string((tend - tstart) / 1000000) + " ms"));
    }

    //function to decide the ellipse drawing algorithm
    void callEllipseDrawingAlgorithm()
    {
        double tstart = (chrono::system_clock::now().time_since_epoch()).count();
        int i = drawingAlgoComboBox->currentIndex();
        if (i == 0)
            EllipseMidPoint(points[0], ellipseMajorAxisSpinBox->value(), ellipseMinorAxisSpinBox->value());
        if (i == 1)
            EllipseParametric(points[0], ellipseMajorAxisSpinBox->value(), ellipseMinorAxisSpinBox->value());
        double tend = (chrono::system_clock::now().time_since_epoch()).count();
        //end of algo
        timeLabel->setText(QString::fromStdString("Time required : " + to_string((tend - tstart) / 1000000) + " ms"));
    }
};