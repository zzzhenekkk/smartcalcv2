#include <QApplication>

//#include "../s21_smartcalc.h"
#include "../controller/s21_controller.h"
#include "../model/s21_smartcalc.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
