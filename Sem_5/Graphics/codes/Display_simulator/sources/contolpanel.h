#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QString>
#include <string>
#include <utility>
#include <iostream>

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

    //members of line drawing
    QLineEdit *lineDrawStartX;
    QLineEdit *lineDrawEndX;
    QLineEdit *lineDrawStartY;
    QLineEdit *lineDrawEndY;

public:
    ControlPanel()
    {
        pixelsize = 5;
        no_of_pixels = 100;

        //Contents of graph setting----------------------------------------------------
        QGroupBox *setGraphGroup = new QGroupBox("Graph Setting");
        QLayout *setGraphLayout = new QVBoxLayout();

        pixelsizeLabel = new QLabel("Enter the pixel size");
        pixelsizeSpinBox = new QSpinBox();
        pixelsizeSpinBox->setRange(1, 10);
        pixelsizeSpinBox->setValue(5);
        pixelsizeLabel->setBuddy(pixelsizeSpinBox);

        noOfPixelsLabel = new QLabel("Enter the no of pixels");
        noOfPixelsSpinBox = new QSpinBox();
        noOfPixelsSpinBox->setRange(10, 200);
        noOfPixelsSpinBox->setValue(100);
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
        QGroupBox *drawingGroup = new QGroupBox("Line Drawing Algorithms");
        QLayout *drawingLayout = new QVBoxLayout();
        clickCoordinate = new QLabel("Clicked Coordinate :\n 0, 0");
        mouseCoordinate = new QLabel("Mouse Coordinate :\n 0, 0");
        QLabel *lineDrawStartLabel = new QLabel("Start Point");
        lineDrawStartX = new QLineEdit();
        lineDrawStartX->setPlaceholderText("X Coordinate");
        lineDrawEndX = new QLineEdit();
        lineDrawEndX->setPlaceholderText("X Coordinate");
        lineDrawStartY = new QLineEdit();
        lineDrawStartY->setPlaceholderText("Y Coordinate");
        lineDrawEndY = new QLineEdit();
        lineDrawEndY->setPlaceholderText("Y Coordinate");
        QLabel *lineDrawEndLabel = new QLabel("End Point");
        QPushButton *lineButton = new QPushButton("Draw Line");
        QObject::connect(lineButton, SIGNAL(clicked()), this, SLOT(drawLineHandler()));

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("DDA line drawing");
        drawingAlgoComboBox->addItem("Bresenham's line drawing");

        drawingLayout->addWidget(drawingAlgoComboBox);
        drawingLayout->addWidget(lineDrawStartLabel);
        drawingLayout->addWidget(lineDrawStartX);
        drawingLayout->addWidget(lineDrawStartY);
        drawingLayout->addWidget(lineDrawEndLabel);
        drawingLayout->addWidget(lineDrawEndX);
        drawingLayout->addWidget(lineDrawEndY);
        drawingLayout->addWidget(lineButton);

        drawingLayout->addWidget(clickCoordinate);
        drawingLayout->addWidget(mouseCoordinate);
        drawingGroup->setLayout(drawingLayout);

        //Parent layout-----------------------------------------------------------------
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(setGraphGroup);
        layout->addWidget(drawingGroup);
        this->setLayout(layout);
    }

    string getCurrentAlgo()
    {
        QString q_algoname = drawingAlgoComboBox->currentText();
        string algoname = q_algoname.toStdString();
        return algoname;
    }
    void drawDDA(){
        float x, y, x1, y1, x2, y2, dx, dy, step;
        int i;
        x1 = (lineDrawStartX->text()).toInt();
        y1 = -1*(lineDrawStartY->text()).toInt();
        x2 = (lineDrawEndX->text()).toInt();
        y2 = -1*(lineDrawEndY->text()).toInt();
        dx = (x2 - x1);
        dy = (y2 - y1);
        if(abs(dx) >= abs(dy))
          step = abs(dx);
        else
          step = abs(dy);
        dx = dx / step;
        dy = dy / step;
        x = x1;
        y = y1;
        i = 1;
        while(i <= step) {
          emit GraphPlotSignal(x, y);
          x = x + dx;
          y = y + dy;
          i = i + 1;
        }
    }
    void drawBresenham(){
        float x, y, x0, y0, x1, y1, dx, dy, step;
        x0 = (lineDrawStartX->text()).toInt();
        y0 = -1*(lineDrawStartY->text()).toInt();
        x1 = (lineDrawEndX->text()).toInt();
        y1 = -1*(lineDrawEndY->text()).toInt();
        dx = x1 - x0;
        dy = y1 - y0;
        step = 2*dy - dx;
        y = y0;
        for(x = x0; x<=x1;x++){
            emit GraphPlotSignal(x, y);
            if (step>0){
                y++;
                step -= 2*dx;
            }
            step += 2*dy;
        }
    }
signals:
    void GraphResetSignal(int, int);
    void GraphPlotSignal(int,int);

public slots:
    void handleButton()
    {
        pixelsize = pixelsizeSpinBox->value();
        no_of_pixels = noOfPixelsSpinBox->value();
        emit GraphResetSignal(pixelsize, no_of_pixels);
    }
    void drawLineHandler(){
        int idx = drawingAlgoComboBox->currentIndex();
        cout<<idx;
        switch(idx){
            case 0:
                this->drawDDA();
                break;
            case 1:
                this->drawBresenham();
                break;

        }
    }

    void getPointHover(pair<int, int> point)
    {
        string showPoint = "Mouse Coordinate: \n" + to_string(point.first) + " " + to_string(-1*point.second);
        QString QShowPoint = QString::fromStdString(showPoint);
        mouseCoordinate->setText(QShowPoint);
    }

    void getPointSelect(pair<int, int> point)
    {
        string showPoint = "Clicked Coordinate: \n" + to_string(point.first) + " " + to_string(-1*point.second);
        QString QShowPoint = QString::fromStdString(showPoint);
        clickCoordinate->setText(QShowPoint);
    }
};
