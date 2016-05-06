#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Mandelbrot *model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
