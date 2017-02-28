//
// Created by ZhangMing on 02-26-17
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "function.h"
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ServiceHub_triggered()
{
    const QUrl url("http://hub.hust.edu.cn/index.jsp");
    qDebug() << url.scheme();
    qDebug() << url.port();
    QDesktopServices::openUrl(url);
}

void MainWindow::on_ServiceHubEmail_triggered()
{
    const QUrl url("https://mail.hust.edu.cn/");
    qDebug() << url.scheme();
    qDebug() << url.port();
    QDesktopServices::openUrl(url);
}

void MainWindow::on_ServiceGithub_triggered()
{
    const QUrl url("https://github.com/");
    qDebug() << url.scheme();
    qDebug() << url.port();
    QDesktopServices::openUrl(url);
}

void MainWindow::on_FunCourseTree_triggered()
{
    CourseTree *p;
    QString queryname;
    if(BuildCourseTree() == false)
    {
        QMessageBox::information(this,"error","No File");
        return;
    }
    else
    {
        // Dialog
        if((p = QueryCourse(queryname)) == nullptr)
        {
            QMessageBox::information(this, "error", "No Such Course");
            return;
        }
        // Web Page
        DataVisualization(p);
    }
}
