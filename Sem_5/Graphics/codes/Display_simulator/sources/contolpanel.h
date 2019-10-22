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
    QLabel *clickCoordinate;
    QLabel *mouseCoordinate;
    AlgoWidget *algo;

public:
    ControlPanel()
    {
        pixelsize = 5;
        no_of_pixels = 120;
        this->setMinimumWidth(300);

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

        algo = new AlgoWidget(this,4,no_of_pixels,pixelsize);

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

signals:
    void GraphResetSignal(int, int);
    void pointRequest(int);

public slots:
    void handleButton()
    {
        pixelsize = pixelsizeSpinBox->value();
        no_of_pixels = noOfPixelsSpinBox->value();
        emit GraphResetSignal(pixelsize, no_of_pixels);
        algo->resetColormap(no_of_pixels,pixelsize);
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