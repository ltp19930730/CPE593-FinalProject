#include "mainwindow.h"
#include "mandelbrotparallel.h"
#include "mandelbrotthread.hpp"
#include <QApplication>
#include <iostream>
#include <QTime>
#include <fstream>

#include "Mandelbrot.h"
#include "Complex.hpp"

#define testProcedure 0
#define runNormal 1

using namespace std;

// Tests brute vs parallel for 100 to 5000 iterations
void testTimes() {
    ofstream dataFile;
    dataFile.open("data5.txt");

    Complex ca(-2, -1);
    Complex ce(0.5, 1);
    Mandelbrot *mandelbrot = new Mandelbrot(&ca,&ce,80,80,32);

    for(int i = 100; i<=5000; i+=100) {
        dataFile << i << ',';
        cout << i << endl;
        QTime time;
        time.start();
        mandelbrot->setDemension(860,720);
        mandelbrot->setIteration(i);
        mandelbrot->calculate();
        int time_Diff = time.elapsed();
        float f = (float)time_Diff/1000.0;

        QString tr_timeDiff = QString{"%1"}.arg(f);
        string t1 = tr_timeDiff.toStdString();
        dataFile << t1 <<",";

        MandelbrotThread mandelThread(860,720,i);
        QString timeThread = mandelThread.calculateTime();
        string t2 = timeThread.toStdString();
        dataFile << t2 << ",\n";

    }
    dataFile.close();
}

void testParallel() {
    ofstream dataFile;
    dataFile.open("2Threads.txt");


    int threadList[] = {5,10,20,35,50,100,200,500,1000};

    for(int i = 1000; i<=20000; i+=1000) {
        dataFile << i << ',';
        cout << i << endl;

        for(int k = 0; k < 9; k++) {
            MandelbrotThread mandelThread(860,720,i,threadList[k]);
            QString timeThread = mandelThread.calculateTime();
            string t2 = timeThread.toStdString();
            dataFile << t2;
            if(k!=8) dataFile << ",";
        }
        dataFile << '\n';

    }
    dataFile.close();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if testProcedure
    testParallel();
#endif

#if runNormal
    Complex ca(-2, -1);
    Complex ce(0.5, 1);
    Mandelbrot *mandelbrot = new Mandelbrot(&ca,&ce,80,80,32);

    mandelbrot->calculate();

    cout<< mandelbrot->toString()<<endl;

    QTime time;
    time.start();
    mandelbrot->setDemension(860,720);
    mandelbrot->setIteration(50);
    mandelbrot->calculate();
    int time_Diff = time.elapsed();
    float f = (float)time_Diff/1000.0;

    QString tr_timeDiff = QString{"%1"}.arg(f);

//    QApplication a(argc, argv);
    MainWindow w(mandelbrot);
    w.setWindowTitle("MandelbrotSet Calculate Time: " +tr_timeDiff);
    w.show();

    MandelbrotThread mandelThread(860,720, 500, 200);

    //show the widget of the mandelbrot viewer
    mandelThread.show();
#endif

    return a.exec();
}
