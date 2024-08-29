#ifndef CREDITCALCULATOR_H
#define CREDITCALCULATOR_H

#include <QDialog>

#include "../model/s21_smartcalc.h"

namespace Ui {
class creditCalculator;
}

class creditCalculator : public QDialog {
  Q_OBJECT

 public:
  explicit creditCalculator(QWidget *parent = nullptr);
  ~creditCalculator();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::creditCalculator *ui;
};

#endif  // CREDITCALCULATOR_H
