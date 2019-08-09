#include <QApplication>
#include "sources/graph.h"
#include <QWidget>
#include <QHBoxLayout>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("Display simulation");

    Graph *graph = new Graph();

    QLayout *parentlayout = new QHBoxLayout;
    parentlayout->addWidget(graph->getGraph());
    window->setLayout(parentlayout);
    window->show();

    return app.exec();
}