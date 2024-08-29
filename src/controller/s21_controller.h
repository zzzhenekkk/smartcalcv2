#ifndef S21_CONTROLLER
#define S21_CONTROLLER

#include "../model/s21_smartcalc.h"

namespace s21 {

class Controller {
 public:
  int start_model(char *src, double *result);
  int start_model(char *src, double *result, double x);

  void start_model_annuity_calculation(long double credit_amount,
                                       long double month, long double interest,
                                       long double *pay_for_month,
                                       long double *total_payment,
                                       long double *overpay);
  void start_diff_calculation(long double credit_amount, long double month,
                              long double interest,
                              long double *pay_for_month_min,
                              long double *pay_for_month_max,
                              long double *total_payment, long double *overpay);

 private:
  s21::CalcModel model_;
};

}  // namespace s21

#endif
