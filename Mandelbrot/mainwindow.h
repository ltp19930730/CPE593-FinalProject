#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <QGraphicsView>

#include "graphic.h"
#include "ui_mainwindow.h"
#include "Complex.hpp"
#include "graphicview.h"
#include "Mandelbrot.h"

using namespace mandelbrot;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Mandelbrot *model,QWidget *parent = 0) : QMainWindow(parent){
        this->model = model ;
        initUI();
        this->resize(model->getWide(),model->getHeight());
        setSize(model->getWide(),model->getHeight());

    }
    ~MainWindow(){
        delete view;
        delete ui;
    }

    void initUI(){
        ui = new Ui::MainWindow;
        ui -> setupUi(this);
        view = new GraphicView(model,this);
    }
    void setSize(int wide,int height){
        view->setSize(wide,height);
    }

private:
    Ui::MainWindow *ui;
    GraphicView* view;
    Mandelbrot* model;
};

#endif // MAINWINDOW_H
