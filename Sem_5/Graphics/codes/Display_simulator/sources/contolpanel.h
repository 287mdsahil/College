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
    QLabel *clickCoordinate;

    //members of drawing------------------------------------
    QComboBox *drawingAlgoComboBox;

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
        QGroupBox *drawingGroup = new QGroupBox("Drawing");
        QLayout *drawingLayout = new QVBoxLayout();
        clickCoordinate = new QLabel("0, 0");

        drawingAlgoComboBox = new QComboBox();
        drawingAlgoComboBox->addItem("DDA line drawing");
        drawingAlgoComboBox->addItem("Bresenham\'s line drawing");

        drawingLayout->addWidget(drawingAlgoComboBox);
        drawingLayout->addWidget(clickCoordinate);
        drawingGroup->setLayout(drawingLayout);

        //Parent layout-----------------------------------------------------------------
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(setGraphGroup);
        layout->addWidget(drawingGroup);
        this->setLayout(layout);
    }

    string getCurrentALgo()
    {
        QString q_algoname = drawingAlgoComboBox->currentText();
        string algoname = q_algoname.toStdString();
        return algoname;
    }
signals:
    void GraphResetSignal(int, int);

public slots:
    void handleButton()
    {
        if (pixelsize != pixelsizeSpinBox->value() || no_of_pixels != noOfPixelsSpinBox->value())
        {
            pixelsize = pixelsizeSpinBox->value();
            no_of_pixels = noOfPixelsSpinBox->value();
            emit GraphResetSignal(pixelsize, no_of_pixels);
        }
    }

    void getPointSelect(pair<int,int> point)
    {
        string showPoint = to_string(point.first) + " " + to_string(point.second);
        QString QShowPoint = QString::fromStdString(showPoint);
        clickCoordinate->setText(QShowPoint);
    }
};