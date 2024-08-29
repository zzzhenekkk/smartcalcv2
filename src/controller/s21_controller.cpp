#include "s21_controller.h"

#include "../model/s21_smartcalc.h"

namespace s21 {

int Controller::start_model(char *src, double *result) {
  return model_.smart_calc(src, result);
}
int Controller::start_model(char *src, double *result, double x) {
  return model_.smart_calc(src, result, x);
}

void Controller::start_model_annuity_calculation(long double credit_amount,
                                                 long double month,
                                                 long double interest,
                                                 long double *pay_for_month,
                                                 long double *total_payment,
                                                 long double *overpay) {
  return model_.s21_annuity_calculation(credit_amount, month, interest,
                                        pay_for_month, total_payment, overpay);
}

void Controller::start_diff_calculation(long double credit_amount,
                                        long double month, long double interest,
                                        long double *pay_for_month_min,
                                        long double *pay_for_month_max,
                                        long double *total_payment,
                                        long double *overpay) {
  return model_.s21_diff_calculation(credit_amount, month, interest,
                                     pay_for_month_min, pay_for_month_max,
                                     total_payment, overpay);
}

}  // namespace s21
