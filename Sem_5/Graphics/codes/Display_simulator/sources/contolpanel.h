#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QSignalMapper>
#include <QString>
#include <string>
#include <utility>
#include <iostream>
#include "algo.h"

using namespace std;

class ControlPanel : public QWidget
{
    Q_OBJECT

    //members of graph setting-----------------------------
    int pixelsize;
    int no_of_pixels;
    QLabel *pixelsizeLabel;
    QSpinBox *pixelsizeSpinBox;
    QLabel *noOfPixelsLabel;
    QSpinBox *noOfPixelsSpinBox;
    QPushButton *setGraphButton;

    //members of drawing------------------------------------
    QComboBox *drawingAlgoComboBox;
    QLabel *clickCoordinate;
    QLabel *mouseCoordinate;
    AlgoWidget *algo;
    // vector<QLabel *>pointLabels;
    // vector<QPushButton *> pointButtons;
    // vector<pair<int,int>> points;

public:
    ControlPanel()
    {
        pixelsize = 5;
        no_of_pixels = 100;
        this->setMinimumWidth(300);
        // points.push_back(pair<int,int>(0,0));
        // points.push_back(pair<int,int>(0,0));

        //Contents of graph setting----------------------------------------------------
        QGroupBox *setGraphGroup = new QGroupBox("Graph Setting");
        QLayout *setGraphLayout = new QVBoxLayout();

        pixelsizeLabel = new QLabel("Enter the pixel size");
        pixelsizeSpinBox = new QSpinBox();
        pixelsizeSpinBox->setRange(1, 30);
        pixelsizeSpinBox->setValue(5);
        pixelsizeLabel->setBuddy(pixelsizeSpinBox);

        noOfPixelsLabel = new QLabel("Enter the no of pixels");
        noOfPixelsSpinBox = new QSpinBox();
        noOfPixelsSpinBox->setRange(10, 1000);
        noOfPixelsSpinBox->setValue(120);
        noOfPixelsLabel->setBuddy(noOfPixelsSpinBox);

        setGraphButton = new QPushButton("Set Graph");

        QObject::connect(setGraphButton, SIGNAL(clicked()), this, SLOT(handleButton()));

        setGraphLayout->addWidget(pixelsizeLabel);
        setGraphLayout->addWidget(pixelsizeSpinBox);

        setGraphLayout->addWidget(noOfPixelsLabel);
        setGraphLayout->addWidget(noOfPixelsSpinBox);
        setGraphLayout->addWidget(setGraphButton);

        setGraphGroup->setLayout(setGraphLayout);

        //Contents of drawing----------------------------------------------------------
        QGroupBox *drawingGroup = new QGroupBox("Drawing");
        QLayout *drawingLayout = new QVBoxLayout();
        clickCoordinate = new QLabel("Clicked Coordinate :\n 0, 0");
        mouseCoordinate = new QLabel("Mouse Coordinate :\n 0, 0");

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("DDA line drawing");
        drawingAlgoComboBox->addItem("Bresenham\'s line drawing");

        // QGroupBox *pointGroup = new QGroupBox("Points");
        // QGridLayout *pointLayout = new QGridLayout();
        // pointButtons.push_back(new QPushButton("Select point 1"));
        // pointButtons.push_back(new QPushButton("Select point 2"));
        // pointLabels.push_back(new QLabel(QString::fromStdString(string(to_string(points[0].first) + ", " + to_string(points[0].second)))));
        // pointLabels.push_back(new QLabel(QString::fromStdString(string(to_string(points[1].first) + ", " + to_string(points[1].second)))));
        // pointLayout->addWidget(pointButtons[0],0,0);
        // pointLayout->addWidget(pointButtons[1],1,0);
        // pointLayout->addWidget(pointLabels[0],0,1);
        // pointLayout->addWidget(pointLabels[1],1,1);
        // pointGroup->setLayout(pointLayout);
        algo = new AlgoWidget(this,0);

        drawingLayout->addWidget(drawingAlgoComboBox);
        drawingLayout->addWidget(algo);
        drawingLayout->addWidget(clickCoordinate);
        drawingLayout->addWidget(mouseCoordinate);
        drawingGroup->setLayout(drawingLayout);

        //Parent layout-----------------------------------------------------------------
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(setGraphGroup);
        layout->addWidget(drawingGroup);
        this->setLayout(layout);
    }

    AlgoWidget *getAlgo()
    {
        return algo;
    }

    int getAlgoName()
    {
        return drawingAlgoComboBox->currentIndex();
    }

signals:
    void GraphResetSignal(int, int);
    void pointRequest(int);

public slots:
    void handleButton()
    {
        pixelsize = pixelsizeSpinBox->value();
        no_of_pixels = noOfPixelsSpinBox->value();
        emit GraphResetSignal(pixelsize, no_of_pixels);
    }

    void getPointHover(pair<int, int> point)
    {
        string showPoint = "Mouse Coordinate: \n" + to_string(point.first) + " " + to_string(point.second);
        QString QShowPoint = QString::fromStdString(showPoint);
        mouseCoordinate->setText(QShowPoint);
    }

    void getPointClicked(pair<int, int> point)
    {
        string showPoint = "Clicked Coordinate: \n" + to_string(point.first) + " " + to_string(point.second);
        QString QShowPoint = QString::fromStdString(showPoint);
        clickCoordinate->setText(QShowPoint);
    }
};