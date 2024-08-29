#include "creditcalculator.h"

#include "../controller/s21_controller.h"
#include "ui_creditcalculator.h"

creditCalculator::creditCalculator(QWidget *parent)
    : QDialog(parent), ui(new Ui::creditCalculator) {
  ui->setupUi(this);
  ui->interestRate->setRange(0, 100);
  ui->term->setRange(0, 999999999);
  ui->creditSum->setRange(0, 999999999999999);
}

creditCalculator::~creditCalculator() { delete ui; }

void creditCalculator::on_pushButton_clicked() {
  long double credit_amount = ui->creditSum->value();
  long double month = ui->term->value();
  long double interest = ui->interestRate->value();

  long double total_payment = 0, overpay = 0;

  if (ui->annuitet->isChecked()) {
    long double pay_for_month = 0;
    s21::Controller().start_model_annuity_calculation(credit_amount, month,
                                                      interest, &pay_for_month,
                                                      &total_payment, &overpay);

    ui->monthlyPayment->setText(
        QString::number(static_cast<double>(pay_for_month), 'g', 7));

  } else if (ui->diff->isChecked()) {
    long double pay_for_month_min = 0, pay_for_month_max = 0;
    s21::Controller().start_diff_calculation(
        credit_amount, month, interest, &pay_for_month_min, &pay_for_month_max,
        &total_payment, &overpay);

    ui->monthlyPayment->setText(QString::number(pay_for_month_max, 'g', 7) +
                                "..." +
                                QString::number(pay_for_month_min, 'g', 7));
  }

  QString overpay_res = QString::number(static_cast<double>(overpay), 'g', 7);
  QString total_payment_res =
      QString::number(static_cast<double>(total_payment), 'g', 7);

  ui->percentSum->setText(overpay_res);
  ui->totalPayment->setText(total_payment_res);
}
