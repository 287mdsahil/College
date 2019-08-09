#include <QApplication>
#include "sources/graph.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>

using namespace std;

class ControlPanel : public QWidget
{
public:
    ControlPanel()
    {
        QLineEdit *pixelsizeEdit = new QLineEdit();
        pixelsizeEdit->setPlaceholderText("Pixel size");
        pixelsizeEdit->setValidator(new QIntValidator(0, 10, this));

        QLineEdit *noOfPixelsEdit = new QLineEdit();
        noOfPixelsEdit->setPlaceholderText("No of pixels");
        noOfPixelsEdit->setValidator(new QIntValidator(0,300,this));

        QPushButton *setGraphButton = new QPushButton("Set Graph");

        QVBoxLayout *layout = new QVBoxLayout();

        layout->addWidget(pixelsizeEdit);

        layout->addWidget(noOfPixelsEdit);
        layout->addWidget(setGraphButton);

        this->setLayout(layout);
    }

    QWidget *getControlPanel()
    {
        return this;
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("Display simulation");

    Graph *graph = new Graph();
    ControlPanel *contolpanel = new ControlPanel();

    QLayout *parentlayout = new QHBoxLayout;
    parentlayout->addWidget(graph->getGraph());
    parentlayout->addWidget(contolpanel->getControlPanel());

    window->setLayout(parentlayout);
    window->show();
    return app.exec();
}