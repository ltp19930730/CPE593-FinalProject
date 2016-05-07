#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphic.h"
#include "Complex.hpp"
#include "graphicview.h"
#include "Mandelbrot.h"

#include <QMainWindow>
#include <iostream>
#include <string>
#include <QGraphicsView>

MainWindow::MainWindow(Mandelbrot *model,QWidget *parent) : QMainWindow(parent){
    this->model = model ;
    initUI();
    this->resize(model->getWide(),model->getHeight());
    setSize(model->getWide(),model->getHeight());

}

MainWindow::~MainWindow()
{
    delete view;
    delete ui;
}

void MainWindow::initUI() {
    ui = new Ui::MainWindow;
    ui -> setupUi(this);
    view = new GraphicView(model,this);
}

void MainWindow::setSize(int wide,int height){
    view->setSize(wide,height);
}
