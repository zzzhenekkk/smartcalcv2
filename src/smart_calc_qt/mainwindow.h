#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../controller/s21_controller.h"
#include "../model/s21_smartcalc.h"
#include "creditcalculator.h"

class creditCalculator;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  //  class s21::Controller;

 private slots:
  void digits_numbers();
  //    void on_pushButton_clicked();

  //      void operations();
  void on_pushButton_ac_clicked();

  void on_pushButton_eq_clicked();

  void on_pushButton_set_x_clicked();

  void on_pushButton_clear_x_clicked();

  void on_pushButton_calc_x_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_clicked();

 private:
  Ui::MainWindow *ui;
  creditCalculator *creditCalculator_;
};
#endif  // MAINWINDOW_H
