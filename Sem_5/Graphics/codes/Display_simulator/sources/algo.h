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
#include <map>
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
    int no_of_pixels;
    int pixelsize;

    QLabel *radiusLabel;
    QSpinBox *radiusSpinBox;
    QPushButton *drawCircleButton;

    QLabel *ellipseMajorAxisLabel;
    QLabel *ellipseMinorAxisLabel;
    QSpinBox *ellipseMajorAxisSpinBox;
    QSpinBox *ellipseMinorAxisSpinBox;
    QPushButton *drawEllipseButton;

    QPushButton *fillButton;
    pair<int, int> internalPoint;
    QColor boundary_color = QColor(Qt::blue);
    QColor fill_color = QColor(Qt::red);
    map<pair<int, int>, QColor> colormap;

    //variable for clipping
    const int INSIDE = 0; // 0000
    const int LEFT = 1;   // 0001
    const int RIGHT = 2;  // 0010
    const int BOTTOM = 4; // 0100
    const int TOP = 8;    // 1000
    vector<pair<int, int>> clippingRectPoints;
    vector<pair<int, int>> linePoints;

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
                paintSignalEmitter(pair<int, int>(currX, currY));
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
                paintSignalEmitter(pair<int, int>(currX, currY));
            }
        }
    }

    //DDA Line Drawing algorithm
    void DDA(pair<int, int> p1, pair<int, int> p2, QColor paintcolor = Qt::blue)
    {
        cout << "DDA line drawing called" << endl;
        pair<int, int> point1, point2;

        if (p1.first == p2.first)
        {
            int y1 = min(p1.second, p2.second);
            int y2 = max(p1.second, p2.second);
            for (int y = y1; y <= y2; y++)
                paintSignalEmitter(pair<int, int>(p1.first, y), paintcolor);
        }
        else if (p1.second == p2.second)
        {
            int x1 = min(p1.first, p2.first);
            int x2 = max(p1.first, p2.first);
            for (int x = x1; x <= x2; x++)
                paintSignalEmitter(pair<int, int>(x, p1.second), paintcolor);
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
                    paintSignalEmitter(pair<int, int>(x, y), paintcolor);
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
                    paintSignalEmitter(pair<int, int>(x, y), paintcolor);
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
            paintSignalEmitter(pair<int, int>(x, y));

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
        paintSignalEmitter(pair<int, int>(xc, yc));
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
        paintSignalEmitter(pair<int, int>(xc + x, yc + y));
        paintSignalEmitter(pair<int, int>(xc + x, yc - y));
        paintSignalEmitter(pair<int, int>(xc - x, yc - y));
        paintSignalEmitter(pair<int, int>(xc - x, yc + y));
        paintSignalEmitter(pair<int, int>(xc + y, yc + x));
        paintSignalEmitter(pair<int, int>(xc + y, yc - x));
        paintSignalEmitter(pair<int, int>(xc - y, yc + x));
        paintSignalEmitter(pair<int, int>(xc - y, yc - x));
    }

    void MidPointCircle(pair<int, int> p, int r)
    {
        int xc = p.first;
        int yc = p.second;
        int x = r, y = 0;

        paintSignalEmitter(pair<int, int>(xc, yc));

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
        paintSignalEmitter(pair<int, int>(xc, yc));
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
        paintSignalEmitter(pair<int, int>(xc + x, yc + y));
        paintSignalEmitter(pair<int, int>(xc + x, yc - y));
        paintSignalEmitter(pair<int, int>(xc - x, yc - y));
        paintSignalEmitter(pair<int, int>(xc - x, yc + y));
    }

    //Filling algorithms----------------------------------------------------------------

    void boundaryFill4(pair<int, int> p)
    {
        int x = p.first;
        int y = p.second;
        if (abs(x) <= no_of_pixels / 2 && abs(y) <= no_of_pixels / 2 && colormap[make_pair(x, y)] != boundary_color && colormap[make_pair(x, y)] != fill_color)
        {
            paintSignalEmitter(pair<int, int>(x, y), fill_color);
            boundaryFill4(pair<int, int>(x + 1, y));
            boundaryFill4(pair<int, int>(x, y + 1));
            boundaryFill4(pair<int, int>(x - 1, y));
            boundaryFill4(pair<int, int>(x, y - 1));
        }
    }

    void floodFill4(pair<int, int> p, QColor curColor)
    {
        int x = p.first;
        int y = p.second;

        if (abs(x) <= no_of_pixels / 2 && abs(y) <= no_of_pixels / 2 && colormap[p] == curColor)
        {
            paintSignalEmitter(pair<int, int>(x, y), fill_color);
            floodFill4(pair<int, int>(x + 1, y), curColor);
            floodFill4(pair<int, int>(x, y + 1), curColor);
            floodFill4(pair<int, int>(x - 1, y), curColor);
            floodFill4(pair<int, int>(x, y - 1), curColor);
        }
    }

    void scanlineFill()
    {
        cout << "scan line called" << endl;
        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            vector<pair<int, int>> linepoints;
            for (int j = no_of_pixels / 2; j >= -no_of_pixels / 2; j--)
            {
                QColor colorPix = colormap[make_pair(i, j)];
                if (colorPix == Qt::blue)
                {
                    linepoints.push_back((make_pair(i, j)));
                    if (searchPoint(make_pair(i, j)))
                        linepoints.push_back((make_pair(i, j)));

                    while (colormap[make_pair(i, j - 1)] == Qt::blue)
                    {
                        j--;
                    }
                }
            }

            if (linepoints.size() > 1)
            {
                int flag = 0;
                for (unsigned int i = 0; i < linepoints.size() - 1; i++)
                {
                    pair<int, int> x(linepoints[i].first, linepoints[i].second);
                    pair<int, int> y(linepoints[i + 1].first, linepoints[i + 1].second);
                    if (x.second + 1 != y.second && flag == 0)
                    {
                        for (int j = x.second - 1; j > y.second; j--)
                        {
                            paintSignalEmitter(make_pair(x.first, j), fill_color);
                            cout << j << " " << x.second << endl;
                        }
                        i++;
                        flag = flag ^ 1;
                    }
                    else if (x.second + 1 != y.second)
                    {
                        flag = flag ^ 1;
                    }
                }
            }
        }
    }

    //Clipping algorithms----------------------------------------------------------------------------------

    int computeCode(int x, int y) //compare (X,Y) with boundary
    {

        int x_max = max(clippingRectPoints[1].first,clippingRectPoints[0].first);
        int y_max = max(clippingRectPoints[1].second,clippingRectPoints[0].second);
        int x_min = min(clippingRectPoints[1].first,clippingRectPoints[0].first);
        int y_min = min(clippingRectPoints[1].second,clippingRectPoints[0].second);

        // initialized as being inside
        int code = INSIDE;

        if (x < x_min) // to the left of rectangle
            code |= LEFT;
        else if (x > x_max) // to the right of rectangle
            code |= RIGHT;
        if (y < y_min) // below the rectangle
            code |= BOTTOM;
        else if (y > y_max) // above the rectangle
            code |= TOP;

        return code;
    }

    // Implementing Cohen-Sutherland algorithm
    // Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
    void cohenSutherlandClip(pair<int, int> p1, pair<int, int> p2)
    {
        cout << "cohen sutherland line clipping called" << endl;

        //DDA(p1, p2, Qt::white);
        int x1 = p1.first;
        int y1 = p1.second;
        int x2 = p2.first;
        int y2 = p2.second;

        //cout<<x1<<","<<y1<<" - "<<x2<<","<<y2<<endl;

        int x_max = max(clippingRectPoints[1].first,clippingRectPoints[0].first);
        int y_max = max(clippingRectPoints[1].second,clippingRectPoints[0].second);
        int x_min = min(clippingRectPoints[1].first,clippingRectPoints[0].first);
        int y_min = min(clippingRectPoints[1].second,clippingRectPoints[0].second);

        // Compute region codes for P1, P2
        int code1 = computeCode(x1, y1);
        int code2 = computeCode(x2, y2);

        // Initialize line as outside the rectangular window
        bool accept = false;

        while (true)
        {
            if ((code1 == 0) && (code2 == 0))
            {
                // If both endpoints lie within rectangle
                accept = true;
                break;
            }
            else if (code1 & code2)
            {
                // If both endpoints are outside rectangle,
                // in same region
                break;
            }
            else
            {
                // Some segment of line lies within the
                // rectangle
                int code_out;
                int x, y;

                // At least one endpoint is outside the
                // rectangle, pick it.
                if (code1 != 0)
                    code_out = code1;
                else
                    code_out = code2;

                // Find intersection point;
                // using formulas y = y1 + slope * (x - x1),
                // x = x1 + (1 / slope) * (y - y1)
                if (code_out & TOP)
                {
                    // point is above the clip rectangle
                    x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                    y = y_max;
                }
                else if (code_out & BOTTOM)
                {
                    // point is below the rectangle
                    x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                    y = y_min;
                }
                else if (code_out & RIGHT)
                {
                    // point is to the right of rectangle
                    y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                    x = x_max;
                }
                else if (code_out & LEFT)
                {
                    // point is to the left of rectangle
                    y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                    x = x_min;
                }

                // Now intersection point x,y is found
                // We replace point outside rectangle
                // by intersection point
                if (code_out == code1)
                {
                    x1 = x;
                    y1 = y;
                    code1 = computeCode(x1, y1);
                }
                else
                {
                    x2 = x;
                    y2 = y;
                    code2 = computeCode(x2, y2);
                }
            }
        }

        cout<<accept<<endl;
        if (accept)
        {
            //You have (X1,Y1) and (X2,Y2).Draw the line.

            DDA(pair<int, int>(x1, y1), pair<int, int>(x2, y2),Qt::green);

            // cout <<"Line accepted from " << x1 << ", "
            //     << y1 << " to "<< x2 << ", " << y2 << endl;
            // Here the user can add code to display the rectangle
            // along with the accepted (portion of) lines
        }
    }

    //-----------------------------------------------------------------------------------------------------

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

    void makeFilling()
    {
        points.clear();
        internalPoint = pair<int, int>(0, 0);
        algoParentLayout = new QVBoxLayout();

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("Boundary fill algorithm");
        drawingAlgoComboBox->addItem("Flood fill algorithm");
        drawingAlgoComboBox->addItem("Scanline fill algorithm");

        QGroupBox *pointGroup = new QGroupBox("Points");
        QGridLayout *pointLayout = new QGridLayout();
        pointButtons.push_back(new QPushButton("Add polygon point"));
        pointButtons.push_back(new QPushButton("Connect"));
        pointButtons.push_back(new QPushButton("clear points stack"));
        pointButtons.push_back(new QPushButton("select internal point"));
        pointLabels.push_back(new QLabel("0,0"));
        pointLayout->addWidget(pointButtons[0], 0, 0);
        pointLayout->addWidget(pointButtons[1], 1, 0);
        pointLayout->addWidget(pointButtons[2], 2, 0);
        pointLayout->addWidget(pointButtons[3], 3, 0);
        pointLayout->addWidget(pointLabels[0], 3, 1);
        pointGroup->setLayout(pointLayout);

        connect(pointButtons[0], SIGNAL(clicked()), this, SLOT(makePointRequestPolygon()));
        connect(pointButtons[1], SIGNAL(clicked()), this, SLOT(connectPolygon()));
        connect(pointButtons[2], SIGNAL(clicked()), this, SLOT(clearPoints()));
        connect(pointButtons[3], SIGNAL(clicked()), this, SLOT(setInternalPoint()));

        fillButton = new QPushButton("Fill");
        connect(fillButton, SIGNAL(clicked()), this, SLOT(callFillingAlgorithm()));

        timeLabel = new QLabel("Time required: -");

        algoParentLayout->addWidget(drawingAlgoComboBox);
        algoParentLayout->addWidget(pointGroup);
        algoParentLayout->addWidget(fillButton);
        algoParentLayout->addWidget(timeLabel);
        setLayout(algoParentLayout);
    }

    void makeClipping()
    {
        points.clear();
        points.push_back(pair<int, int>(0, 0));
        points.push_back(pair<int, int>(0, 0));
        internalPoint = pair<int, int>(0, 0);
        algoParentLayout = new QVBoxLayout();

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("line clipping");

        QGroupBox *pointGroup = new QGroupBox("Line");
        QGridLayout *pointLayout = new QGridLayout();
        pointButtons.push_back(new QPushButton("Point 1"));
        pointButtons.push_back(new QPushButton("Point 2"));
        pointLabels.push_back(new QLabel("0,0"));
        pointLabels.push_back(new QLabel("0,0"));
        pointButtons.push_back(new QPushButton("Draw line"));
        pointButtons.push_back(new QPushButton("Draw rectangle"));
        pointButtons.push_back(new QPushButton("CLip Line"));
        pointLayout->addWidget(pointButtons[0], 0, 0);
        pointLayout->addWidget(pointLabels[0], 0, 1);
        pointLayout->addWidget(pointButtons[1], 1, 0);
        pointLayout->addWidget(pointLabels[1], 1, 1);
        pointLayout->addWidget(pointButtons[2], 2, 0);
        pointLayout->addWidget(pointButtons[3], 3, 0);
        pointLayout->addWidget(pointButtons[4], 4, 0);
        pointGroup->setLayout(pointLayout);

        QSignalMapper *mapper = new QSignalMapper();
        connect(mapper, SIGNAL(mapped(int)), this, SLOT(makePointRequest(int)));
        mapper->setMapping(pointButtons[0], 0);
        connect(pointButtons[0], SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(pointButtons[1], 1);
        connect(pointButtons[1], SIGNAL(clicked()), mapper, SLOT(map()));
        connect(pointButtons[2], SIGNAL(clicked()), this, SLOT(drawLine()));

        connect(pointButtons[3], SIGNAL(clicked()), this, SLOT(drawRect()));

        connect(pointButtons[4], SIGNAL(clicked()), this, SLOT(callClippingAlgorithm()));

        timeLabel = new QLabel("Time required: -");

        algoParentLayout->addWidget(drawingAlgoComboBox);
        algoParentLayout->addWidget(pointGroup);
        algoParentLayout->addWidget(timeLabel);
        setLayout(algoParentLayout);
    }

    void resetColormap(int npixel, int spixel)
    {
        no_of_pixels = npixel;
        pixelsize = spixel;

        for (int i = -no_of_pixels / 2; i <= no_of_pixels; i++)
            for (int j = -no_of_pixels / 2; j <= no_of_pixels; j++)
                if (i == 0 || j == 0)
                    colormap[make_pair(i, j)] = Qt::lightGray;
                else
                    colormap[make_pair(i, j)] = Qt::white;
    }

    int searchPoint(pair<int, int> p)
    {
        for (vector<pair<int, int>>::iterator i = points.begin(); i != points.end(); i++)
        {
            if (*i == p)
            {
                return 1;
            }
        }
        return 0;
    }

    AlgoWidget(QWidget *parentPtr, int type, int npixel, int spixel)
    {
        no_of_pixels = npixel;
        pixelsize = spixel;
        parent = parentPtr;
        algoIndex = 0;

        for (int i = -no_of_pixels / 2; i <= no_of_pixels; i++)
            for (int j = -no_of_pixels / 2; j <= no_of_pixels; j++)
                if (i == 0 || j == 0)
                    colormap.insert(make_pair(make_pair(i, j), Qt::lightGray));
                else
                    colormap.insert(make_pair(make_pair(i, j), Qt::white));

        if (type == 0)
        {
            makelineDrawing();
        }
        else if (type == 1)
        {
            makeCircleDrawing();
        }
        else if (type == 2)
        {
            makeEllipseDrawing();
        }
        else if (type == 3)
        {
            makeFilling();
        }
        else if (type == 4)
        {
            makeClipping();
        }
    }

    void paintSignalEmitter(pair<int, int> p, QColor color = Qt::blue)
    {
        emit paintPointSignal(p, color);
        colormap[p] = color;
    }

signals:
    void pointRequest(int);
    void paintPointSignal(pair<int, int>);
    void paintPointSignal(pair<int, int>, QColor);
    void unPaintPointSignal(pair<int, int>);

public slots:
    void makePointRequest(int ind)
    {
        points[ind] = clickedPoint;
        pointLabels[ind]->setText(QString::fromStdString(string(to_string(points[ind].first) + ", " + to_string(points[ind].second))));
    }

    void makePointRequestPolygon()
    {
        points.push_back(clickedPoint);
        if (points.size() > 1)
        {
            DDA(points[points.size() - 1], points[points.size() - 2]);
        }
    }

    void receiveClickedPoint(pair<int, int> p)
    {
        //emit unPaintPointSignal(clickedPoint);
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

    // function to decide the filling algorithm
    void callFillingAlgorithm()
    {
        //start of algo
        algoIndex = drawingAlgoComboBox->currentIndex();
        double tstart = (chrono::system_clock::now().time_since_epoch()).count();
        if (algoIndex == 0)
        {
            boundaryFill4(internalPoint);
        }
        else if (algoIndex == 1)
        {
            floodFill4(internalPoint, colormap[internalPoint]);
        }
        else if (algoIndex == 2)
        {
            scanlineFill();
        }

        double tend = (chrono::system_clock::now().time_since_epoch()).count();
        //end of algo
        timeLabel->setText(QString::fromStdString("Time required : " + to_string((tend - tstart) / 1000000) + " ms"));
    }

    //function to call the clipping algorithm
    void callClippingAlgorithm()
    {
        //start of algo
        algoIndex = drawingAlgoComboBox->currentIndex();
        double tstart = (chrono::system_clock::now().time_since_epoch()).count();
        if (algoIndex == 0)
        {
            cohenSutherlandClip(linePoints[0], linePoints[1]);
        }

        double tend = (chrono::system_clock::now().time_since_epoch()).count();
        //end of algo
        timeLabel->setText(QString::fromStdString("Time required : " + to_string((tend - tstart) / 1000000) + " ms"));
    }

    //function to set the internal point
    void setInternalPoint()
    {
        internalPoint = clickedPoint;
        string showInternalPoint = to_string(internalPoint.first) + " " + to_string(internalPoint.second);
        QString QShowInternalPoint = QString::fromStdString(showInternalPoint);
        pointLabels[0]->setText(QShowInternalPoint);
    }

    //function to connect the last and first points of the polygon
    void connectPolygon()
    {
        //connect the first and last points
        parametricLineDrawing(points[points.size() - 1], points[0]);
    }

    void clearPoints()
    {
        //clear the points vector
        points.clear();
    }

    void drawLine()
    {
        linePoints.clear();
        DDA(points[0], points[1]);
        linePoints.push_back(points[0]);
        linePoints.push_back(points[1]);
    }

    void drawRect() //p1->top left;p2->bottom right
    {
        clippingRectPoints.clear();
        pair<int, int> p1 = points[0];
        pair<int, int> p2 = points[1];

        clippingRectPoints.push_back(points[0]);
        clippingRectPoints.push_back(points[1]);

        DDA(p1, pair<int, int>(p2.first, p1.second),Qt::red);
        DDA(p1, pair<int, int>(p1.first, p2.second),Qt::red);
        DDA(p2, pair<int, int>(p1.first, p2.second),Qt::red);
        DDA(p2, pair<int, int>(p2.first, p1.second),Qt::red);
    }
};