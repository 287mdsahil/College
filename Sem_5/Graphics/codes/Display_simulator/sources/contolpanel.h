#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QSpinBox>
#include <QVBoxLayout>

using namespace std;

class ControlPanel : public QWidget
{
    Q_OBJECT
    int pixelsize;
    int no_of_pixels;
    QLabel *pixelsizeLabel;
    QSpinBox *pixelsizeSpinBox;
    QLabel *noOfPixelsLabel;
    QSpinBox *noOfPixelsSpinBox;
    QPushButton *setGraphButton;

public:
    ControlPanel()
    {
        pixelsize = 5;
        no_of_pixels = 100;

        pixelsizeLabel = new QLabel("Enter the pixel size");
        pixelsizeSpinBox = new QSpinBox();
        pixelsizeSpinBox->setRange(1, 10);
        pixelsizeSpinBox->setValue(5);
        pixelsizeLabel->setBuddy(pixelsizeSpinBox);

        noOfPixelsLabel = new QLabel("Enter the pixel size");
        noOfPixelsSpinBox = new QSpinBox();
        noOfPixelsSpinBox->setRange(10, 200);
        noOfPixelsSpinBox->setValue(100);
        noOfPixelsLabel->setBuddy(noOfPixelsSpinBox);

        setGraphButton = new QPushButton("Set Graph");

        QObject::connect(setGraphButton, SIGNAL(clicked()), this, SLOT(handleButton()));

        QVBoxLayout *layout = new QVBoxLayout();

        layout->addWidget(pixelsizeLabel);
        layout->addWidget(pixelsizeSpinBox);

        layout->addWidget(noOfPixelsLabel);
        layout->addWidget(noOfPixelsSpinBox);
        layout->addWidget(setGraphButton);

        this->setLayout(layout);
    }

    QWidget *getControlPanel()
    {
        return this;
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
};