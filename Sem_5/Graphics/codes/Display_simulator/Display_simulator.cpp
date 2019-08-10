#include <QApplication>
#include "sources/graph.h"
#include "sources/contolpanel.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("Display simulation");

    Graph *graph = new Graph();
    ControlPanel *controlpanel = new ControlPanel();

    QLayout *parentlayout = new QHBoxLayout;
    parentlayout->addWidget(graph);
    parentlayout->addWidget(controlpanel);

    QObject::connect(controlpanel,SIGNAL(GraphResetSignal(int,int)),graph,SLOT(GraphResetSlot(int,int)));
    

    window->setLayout(parentlayout);
    window->show();
    return app.exec();
}