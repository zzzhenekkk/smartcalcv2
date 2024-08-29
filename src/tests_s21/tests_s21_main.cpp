#include <gtest/gtest.h>

#include <cmath>  // Для использования NAN и INFINITY

#include "../model/s21_smartcalc.h"
using namespace s21;

#define S21_SIZE 1000

TEST(CalcModelTest, ComplexCalculation1) {
  char src[S21_SIZE] = "2458.324234*4.53345435-5^22.234324+123.4543/2.1212321";
  double expected = -3476366391885870.520000000000;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, ComplexCalculation122) {
  char src[S21_SIZE] =
      "2458.324234*4.53345435-5^22.234324+123.4543/2.1212321+x";
  double expected = -3476366391885870.520000000000;
  double result = 0;
  CalcModel().smart_calc(src, &result, 0);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, LogarithmicCalculation) {
  char src[S21_SIZE] = "log(45.236582*55522.85-583)";
  double expected = 6.39986071453;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, ComplexCalculation2) {
  char src[S21_SIZE] =
      "5226*6885-5185/5586/25522-684+(45222-54855/5452*3555)-256*44+2";
  double expected = 35978517.5617758098690562;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, TangentCalculation) {
  char src[S21_SIZE] = "tan(785852.355)";
  double expected = -4.24289256573;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, NaturalLogCalculation) {
  char src[S21_SIZE] = "ln(785.695233)";
  double expected = 6.66656897296;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, ComplexCalculation3) {
  char src[S21_SIZE] =
      "785-968*624-32.99996-(78541*88965.32-99856)+(855*6944-326.55)";
  double expected = -6981991828.669961;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-7);
}

TEST(CalcModelTest, ArctangentCalculation) {
  char src[S21_SIZE] = "atan234.235235";
  double expected = 1.566527;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, ArccosineCalculation) {
  char src[S21_SIZE] = "acos(0.123123213)";
  double expected = 1.447360;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, ArcsineCalculation) {
  char src[S21_SIZE] = "asin(0.4234234)";
  double expected = 0.437221;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, CosineCalculation) {
  char src[S21_SIZE] = "cos(0.4234234)";
  double expected = 0.911688;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, SquareRootCalculation) {
  char src[S21_SIZE] = "sqrt(234.423423432432432)";
  double expected = 15.310892;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, ModulusCalculation) {
  char src[S21_SIZE] = "10.00000mod3.0000000";
  double expected = 1.000000;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, NegativeOneCalculation) {
  char src[S21_SIZE] = "-1";
  double expected = -1;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, SineCalculation) {
  char src[S21_SIZE] = "sin89";
  double expected = 0.86006940581;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, PositiveOneCalculation) {
  char src[S21_SIZE] = "+1";
  double expected = 1;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, NegativeOneInParentheses) {
  char src[S21_SIZE] = "(-1)";
  double expected = -1;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, PositiveOneInParentheses) {
  char src[S21_SIZE] = "(+1)";
  double expected = 1;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, ModulusTwoCalculation) {
  char src[S21_SIZE] = "2mod2";
  double expected = 0;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, CosineOfFiveCalculation) {
  char src[S21_SIZE] = "(cos5)";
  double expected = 0.283662;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, NaturalLogOfEighteen) {
  char src[S21_SIZE] = "ln18.00";
  double expected = 2.8903717;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, DivisionByZero) {
  char src[S21_SIZE] = "2/0.0";
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_EQ(result, INFINITY);
}

TEST(CalcModelTest, ZeroDivisionByZero) {
  char src[S21_SIZE] = "0/0";
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_TRUE(std::isnan(result));
}

TEST(CalcModelTest, IncorrectBrackets) {
  char src[S21_SIZE] = ")(123 + 2)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, FAILURE);
}

TEST(CalcModelTest, EmptyString) {
  char src[S21_SIZE] = "";
  double expected = 0;
  double result = 0;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModelTest, UnmatchedOpeningBracket) {
  char src[S21_SIZE] = "((123 + 2)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, FAILURE);
}

TEST(CalcModelTest, MultiplicationByNegativeTwo) {
  char src[S21_SIZE] = "1*-2";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, FAILURE);
}

TEST(CalcModelTest, CosineMultiplicationByNegativeTwo) {
  char src[S21_SIZE] = "1*cos-2";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, FAILURE);
}

TEST(CalcModelTest, IncorrectDecimalPoints) {
  char src[S21_SIZE] = "123..123123 + 2";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, FAILURE);
}

TEST(CalcModelTest, DoubleNegativeOne) {
  char src[S21_SIZE] = "-(-1)";
  double expected = 1.;
  double result = 0.;
  CalcModel().smart_calc(src, &result);
  EXPECT_NEAR(result, expected, 1e-6);
}

TEST(CalcModel, Test1) {
  char src[S21_SIZE] = "255*6mod0";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CalcModel, Test2) {
  char src[S21_SIZE] = "sqrt(-20/5)+39.6";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CalcModel, Test3) {
  char src[S21_SIZE] = "228-0^(-2)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CalcModel, Test4) {
  char src[S21_SIZE] = "asin(9/10+4)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CalcModel, Test5) {
  char src[S21_SIZE] = "acos(-7)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CalcModel, Test6) {
  char src[S21_SIZE] = "ln(0.)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CalcModel, Test7) {
  char src[S21_SIZE] = "log(-5)*ln(-10)";
  double result = 0.;
  int status = CalcModel().smart_calc(src, &result);
  EXPECT_EQ(status, INCORRECT_VAL);
}

TEST(CreditCalculationTest, AnnuityPaymentCalculation) {
  long double pay_for_month = 0., total_payment = 0., overpay = 0.;
  CalcModel().s21_annuity_calculation(300000, 18, 15, &pay_for_month,
                                      &total_payment, &overpay);

  EXPECT_NEAR(pay_for_month, 18715.44, 1e-2);
  EXPECT_NEAR(overpay, 36877.92, 1e-2);
  EXPECT_NEAR(total_payment, 336877.92, 1e-2);
}

TEST(CreditCalculationTest, DiffPaymentCalculationMax) {
  long double pay_for_month_min = 0., pay_for_month_max = 0.,
              total_payment = 0., overpay = 0.;
  CalcModel().s21_diff_calculation(300000, 18, 15, &pay_for_month_min,
                                   &pay_for_month_max, &total_payment,
                                   &overpay);

  EXPECT_NEAR(pay_for_month_max, 20416.66,
              1e-2);  // Примерное ожидаемое значение для первого платежа
  EXPECT_NEAR(overpay, 35625,
              1e-2);  // Примерное ожидаемое значение для переплаты
  EXPECT_NEAR(total_payment, 335625,
              1e-2);  // Примерное ожидаемое значение для общего платежа
}

TEST(CreditCalculationTest, DiffPaymentCalculationMin) {
  long double pay_for_month_min = 0., pay_for_month_max = 0.,
              total_payment = 0., overpay = 0.;
  CalcModel().s21_diff_calculation(300000, 18, 15, &pay_for_month_min,
                                   &pay_for_month_max, &total_payment,
                                   &overpay);

  EXPECT_NEAR(pay_for_month_min, 16875,
              1e-2);  // Примерное ожидаемое значение для последнего платежа
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}