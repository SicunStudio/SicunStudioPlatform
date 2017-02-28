//
// Created by ZhangMing on 02-26-17
//

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("思存平台");
    w.show();

    return a.exec();
}
