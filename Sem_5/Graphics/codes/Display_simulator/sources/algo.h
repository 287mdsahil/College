#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QComboBox>
#include <utility>
#include <vector>
#include <iostream>
#include <chrono>
#include <math.h>
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
    QVBoxLayout *algoParentLayout;
    QLabel *timeLabel;
    QPushButton *drawLineButton;
    int algoIndex;

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
        int x1 = p1.first, x2 = p2.first;
        int y1 = p1.second, y2 = p2.second;
        int m_new = 2 * (y2 - y1);
        int slope_error_new = m_new - (x2 - x1);
        for (int x = x1, y = y1; x <= x2; x++)
        {
            emit paintPointSignal(pair<int, int>(x, y));

            // Add slope to increment angle formed
            slope_error_new += m_new;

            // Slope error reached limit, time to
            // increment y and update slope error.
            if (slope_error_new >= 0)
            {
                y++;
                slope_error_new -= 2 * (x2 - x1);
            }
        }
    }

    AlgoWidget(QWidget *parentPtr, int algoInd)
    {
        parent = parentPtr;
        algoIndex = algoInd;
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
        connect(drawLineButton, SIGNAL(clicked()), this, SLOT(callAlgorithm()));

        timeLabel = new QLabel("Time required: -");

        algoParentLayout->addWidget(drawingAlgoComboBox);
        algoParentLayout->addWidget(pointGroup);
        algoParentLayout->addWidget(drawLineButton);
        algoParentLayout->addWidget(timeLabel);
        setLayout(algoParentLayout);
    }

signals:
    void pointRequest(int);
    void paintPointSignal(pair<int, int>);

public slots:
    void makePointRequest(int ind)
    {
        emit pointRequest(ind);
    }

    void receivePoint(pair<int, int> point, int ind)
    {
        points[ind] = point;
        pointLabels[ind]->setText(QString::fromStdString(string(to_string(points[ind].first) + ", " + to_string(points[ind].second))));
    }

    void callAlgorithm()
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
};