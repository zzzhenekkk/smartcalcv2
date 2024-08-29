#ifndef S21_SMARTCALC
#define S21_SMARTCALC

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUCCESS 1
#define FAILURE 0
#define INCORRECT_VAL -1
#define NOT_SRC -2
#define GRAPH_X -3

#define GRAPH_ON 1
#define GRAPH_OFF 0

namespace s21 {
class CalcModel {
 public:
  // CalcModel(){}

  typedef enum {
    EMPTY = -1,
    NUMBER,
    X_NUMBER,
    // 1 плюсы минусы
    BINARY_PLUS,
    BINARY_MINUS,
    UNARY_MINUS,
    UNARY_PLUS,
    // 2 умножение деление остаток
    MULT,
    DIV,
    MOD,
    // 3 функции
    COS,
    SIN,
    TAN,
    ACOS,
    ASIN,
    ATAN,
    SQRT,
    LN,
    LOG,
    // 4 степень
    POW,
    // 5 скобки
    OPEN_BRACKET,
    CLOSE_BRACKET,
  } token_type;

  typedef struct token {
    token_type type;
    double num;
  } token_t;

  typedef struct node {
    struct node *prev;
    struct node *next;
    token_t token;
  } node_t;

  /******************** РАБОТА СО СПИСКАМИ ****************************/

  // задаем новый список
  node_t *init_node();

  // добавить элемент в конец списка, с указателем на предыдущий токен,
  // значением и типом, отдает указатель на текущий
  node_t *add_elem(node_t *prev, double num, token_type type);

  // удалить элемент с конца списка, отдает ссылку на предыдущий элемент или
  // null
  node_t *del_elem(node_t *cur);

  // заполнение входного списка лексемами из строки
  int input_input_list(node_t **input_list, char **src);

  // полностью очистить список с любого элемента
  void remove_node(node_t *cur);

  // вывод всего листа
  // void printNode(node_t *head);

  /********************* ФУНКЦИИ ПРОВЕРОК ********************************/

  // возвращает приоритет у лексемы
  int priority(node_t *cur);

  // проверка на корректность введенных скобок
  // int check_brackets(node_t *input_head);

  // проверяет бинарный ли перед нами оператор, 1 - да
  int is_binary(node_t *cur);

  // ищет две точки в числе по длине len
  int two_doubles(char *str, int len);

  // основная функция
  int smart_calc(char *src, double *result);
  int smart_calc(char *src, double *result, double x);

  // перевод в польскую нотцию
  int polish_notattion(node_t *input_list, node_t **output_list);

  int for_binary(double *res, node_t *stack, double num_1, double num_2);

  int for_unary(double *res, node_t *stack, double num_1);

  void skip_space(char **src);

  // определение функции из 1 символа
  void find_one_char(node_t **input_list, char **src);

  // определение функции из 2-4 символов
  int find_func(node_t **input_list, char **src);

  // определение числа
  int find_number(node_t **input_list, char **src);

  // подсчет выражения по полученной польской нотации
  int calculate(node_t *output_list, double *result, double x, int graph);

  // отдельно считаем польскую нотацию из строки, и отдаем список c обртной пн
  int convert_polish_notation(node_t **output_list, char *src);

  void s21_annuity_calculation(long double credit_amount, long double month,
                               long double interest, long double *pay_for_month,
                               long double *total_payment,
                               long double *overpay);

  void s21_diff_calculation(long double credit_amount, long double month,
                            long double interest,
                            long double *pay_for_month_min,
                            long double *pay_for_month_max,
                            long double *total_payment, long double *overpay);
};
}  // namespace s21

#endif
