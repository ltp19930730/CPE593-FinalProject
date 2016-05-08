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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    GraphicView* view;
    Mandelbrot* model;

private slots:
    void OnTblItemsCommitData(QWidget* pLineEdit);
    void on_tableWidget_cellChanged(int row, int column);

public:
    explicit MainWindow(Mandelbrot *model,QWidget *parent = 0);
    ~MainWindow();

    void initUI();
    void setSize(int wide,int height);
};

#endif // MAINWINDOW_H
