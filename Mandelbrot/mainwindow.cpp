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
#include <QLineEdit>

MainWindow::MainWindow(Mandelbrot *model,QWidget *parent) : QMainWindow(parent){
    this->model = model ;
    initUI();
    this->resize(model->getWide()+200,model->getHeight());
    //ui->tableWidget->setGeometry(model->getWide()-200,0,200,(int)ui->tableWidget->geometry().height());
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
    ui->GraphicsView = new GraphicView(model,this);
    //view = new GraphicView(model,this);
}

void MainWindow::setSize(int wide,int height){
    ui->GraphicsView->resize(wide, height);
}

void MainWindow::OnTblItemsCommitData(QWidget* pLineEdit){
    int row = ui->tableWidget->currentRow();
    int col = ui->tableWidget->currentColumn();
    int value = (reinterpret_cast<QLineEdit*>(pLineEdit)->text()).toInt();
    if(row && col == 1) {
        model->setIteration(value);
        model->calculate();
        ui->GraphicsView->repaint();
    }
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(row == 0 && column == 0) {
        int value = ui->tableWidget->currentItem()->text().toInt();
        model->setIteration(value);
        model->calculate();
        ui->GraphicsView->repaint();
    }
}
