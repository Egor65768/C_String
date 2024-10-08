#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "s21_string.h"

#define DEFAULT_WIDTH 6
#define DELTA 0.000000000001
#define DELTA1 0.0000000001

typedef struct {
  int plus;           //+
  int minus;          //-
  int space;          //' '
  int width;          // ширина
  int accuracy;       // точность
  int zero;           // 0
  int decpoint;       // #
  char length;        // длина
  char spec;          // тип который рассматриваем
  int flag_wight;     // * ширина
  int flag_accuracy;  // * точность
  int flag_g;         // g или G
  int inwidth;        // задана ли ширина явно
  int flag_pointer;
} Spec;

enum Specifiers {
  Character = 'c',
  Signed_decimal_integer = 'd',
  Signed_decimal_integer_i = 'i',
  Scientific_notation = 'e',
  Scientific_upper_notation = 'E',
  Decimal_float = 'f',
  Short_decimal_float = 'g',
  Short_decimal_float_upp = 'G',
  Unsigned_octal = 'o',
  String = 's',
  Unsigned_dec_int = 'u',
  Unsigned_hexadec_int = 'x',
  Unsigned_upp_hexadec_int = 'X',
  Pointer_address = 'p',
  Argument_short_int = 'h',
  Argument_long_int = 'l',
  Argument_long_double = 'L'
};

char transnumber[] = "0123456789abcdef";

int s21_sprintf(char *str, const char *format, ...);

// парсинг
const char *parsing_wigh(const char *format, Spec *specs);
// парсинг ширины и точности
const char *parsing_flag(const char *format, Spec *specs);
// парсинг флагов
const char *parsing_lengh(const char *format, Spec *specs);
// парсинг длины(l,h,L)
char *parsing_specifier(const char *format, Spec specs, char *str,
                        va_list *arg);
// парсинг спецификаторов

// обработка спецификаторов
char *add_char(char *str, Spec specs, char a);
// обработка спецификатора с
char *add_string(char *str, char *formated_buf_string, Spec specs);
// обработка спицификатора s
char *add_int_to_string(va_list *arg, Spec specs, char *str);
// обработка спецификатора d
char *add_unsigned_to_string(va_list *arg, Spec specs, char *str);
// обработка спецификаторов u o x X
char *add_pointer_to_string(va_list *arg, Spec specs, char *str);
// обработка спецификтаора р
char *add_float_to_string(va_list *arg, char *str, Spec specs);
// обработка спецификатора f
char *handle_exponential_specifier(va_list *arg, Spec specs, char *str);
// обработка спецификатора е Е
char *flag_g_view(va_list *arg, Spec specs, char *str);
// обработка спецификатора g G

char *padding_zero(char *buf, Spec specs, int lengh_int);
// обработка флага 0, заполняет буфферный массив нулями

char *format_formated_buf_stringer_with_padding(int lenspace, Spec specs,
                                                char *str,
                                                char *formated_buf_string);
// вставляет буферную строку в исходную строку
char *buf_to_str(char *str, char *formated_buf_string, Spec specs);
// тупо вставляет буферную строку в исходную строку
char *space_to_str(char *str, int lenspace);
// вставляет пробелы в исходную сроку

int size_decimal(long int num);
// вычисляет размер целого числа
char *int_to_str(long int num, Spec specs, char *buf, int lengh_int1,
                 int flag_minus);
// переводит целое число в строку
char *format_formated_buf_stringer_with_padding_int_to_string(Spec specs,
                                                              long int num,
                                                              char *buf,
                                                              int *lengh_int);
// переводит число в буферную строку в зависимости от системы счисления и
// вычиляет его длину
char *helpaddzero_add_int_to_string(Spec specs, char *buf, int *lengh_int,
                                    int flag_minus);
// проверяет надо ли заполнять строку с числами нулями и если надо то заполняет
char *helpaddflagtostr_add_int_to_string(int flag_minus, char *buf,
                                         int *lengh_int, Spec specs,
                                         int flag_zero);
// добавляет в знак или начло (для 8 и 16 системы счисления) разное если надо
void backwards_str(char *buf, int lengh_int);
// переворачивает строку. Пример : на вход в функцию "426-" на выход "-624"
char *add_int(char *str, char *formated_buf_string, Spec specs);
// добавляет число в строку

char *pointer_to_string(unsigned long int num, Spec specs, char *buf);
// переводит адресс в строку

void analyze_float(Spec specs, long double f, int *isNegative,
                   long double *ipart, long double *fpart, int *size_buf);
// находит целую и дробную часть числа а так же его размер
char *float_int_to_str(long int ipart, int *lengh_f, char *buf, int isNegative,
                       Spec specs);
// целую часть дробного числа в буферную строку
char *format_float_with_specs(char *buf, int *lengh_f, Spec specs,
                              long double fpart);
// дробную часть дробного числа в буферную строку

int counter_for_pow(long double *number);
// степень десятки
char *add_exptostr(Spec specs, char *buf, int counter, int *lengh_f);
// добавление степени десятки в буферную строку

void checking_for_max_scale(Spec *specs);

char *format_float_with_exponent(Spec specs, long double number, char *str,
                                 int counter, int isNegative);
char *convert_float_to_str(Spec specs, long double f, char *str,
                           int isNegative);

#endif