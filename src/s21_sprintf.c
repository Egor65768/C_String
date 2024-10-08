#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *str1 = str;
  va_list arg;
  va_start(arg, format);
  while (*format) {
    if (*format == '%') {
      format++;
      Spec specs = {0};
      specs.accuracy = -1;
      format = parsing_flag(format, &specs);
      format = parsing_wigh(format, &specs);
      format = parsing_lengh(format, &specs);
      str = parsing_specifier(format, specs, str, &arg);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(arg);
  return (str - str1);
}

const char *parsing_flag(const char *format, Spec *specs) {
  int flag = 1;
  while (flag == 1) {
    if (*format == ' ' && specs->space == 0) {
      specs->space = 1;
      format++;
    } else if (*format == '+') {
      specs->plus = 1;
      format++;
    } else if (*format == '-') {
      specs->minus = 1;
      format++;
    } else if (*format == '#') {
      specs->decpoint = 1;
      format++;
    } else if (*format == '0') {
      specs->zero = 1;
      format++;
    } else if (*format == '*') {
      specs->flag_wight = 1;
      format++;
    } else {
      flag = 0;
    }
  }
  return format;
}

const char *parsing_wigh(const char *format, Spec *specs) {
  int flag = 1;
  int flag_accuracy = 0;
  int res = 0;
  while (flag == 1) {
    if (flag_accuracy == 1 && *format == '*') {
      specs->flag_accuracy = 1;
      flag = 0;
      format++;
    }
    if (*format >= '0' && *format <= '9') {
      res = res * 10 + (*format - '0');
      if (flag_accuracy == 0) {
        specs->width = res;
        specs->inwidth = 1;
      } else {
        specs->accuracy = res;
      }
      format++;
    } else if (*format == '.') {
      flag_accuracy = 1;
      specs->flag_pointer = 1;
      res = 0;
      format++;
    } else {
      flag = 0;
    }
  }
  return format;
}

const char *parsing_lengh(const char *format, Spec *specs) {
  if (*format == Argument_long_int) {
    specs->length = Argument_long_int;
    format++;
  } else if (*format == Argument_long_double) {
    specs->length = Argument_long_double;
    format++;
  } else if (*format == Argument_short_int) {
    specs->length = Argument_short_int;
    format++;
  }
  return format;
}

char *parsing_specifier(const char *format, Spec specs, char *str,
                        va_list *arg) {
  if (specs.flag_wight == 1) {
    specs.width = va_arg(*arg, int);
  }
  if (specs.flag_accuracy == 1) {
    specs.accuracy = va_arg(*arg, int);
  }
  if (*format == Character) {
    if (specs.length == Argument_long_int) {
      setlocale(LC_ALL, "");
      char buf[9];
      wchar_t wstr = va_arg(*arg, wchar_t);
      const wchar_t *wcsIndirectString = &wstr;
      wcsrtombs(buf, &wcsIndirectString, 8, NULL);
      specs.spec = String;
      buf[5] = '\0';
      str = add_string(str, buf, specs);
    } else {
      char a = va_arg(*arg, int);
      specs.spec = Character;
      specs.zero = 0;
      str = add_char(str, specs, a);
    }
  } else if (*format == String) {
    specs.spec = String;
    char buf[2048];
    char *formated_buf_string = buf;
    if (specs.length == Argument_long_int) {
      setlocale(LC_ALL, "");
      wchar_t *wstr = va_arg(*arg, wchar_t *);
      const wchar_t *wcsIndirectString = wstr;
      wcsrtombs(formated_buf_string, &wcsIndirectString, 2048, NULL);
    } else {
      char *buf1 = va_arg(*arg, char *);
      formated_buf_string = buf1;
    }
    str = add_string(str, formated_buf_string, specs);
  } else if (*format == Signed_decimal_integer ||
             *format == Signed_decimal_integer_i) {
    specs.spec = Signed_decimal_integer;
    str = add_int_to_string(arg, specs, str);
  } else if (*format == Unsigned_dec_int) {
    specs.spec = Unsigned_dec_int;
    specs.plus = 0;
    specs.space = 0;
    str = add_unsigned_to_string(arg, specs, str);
  } else if (*format == Unsigned_octal || *format == Unsigned_hexadec_int ||
             *format == Unsigned_upp_hexadec_int) {
    specs.spec = *format;
    specs.plus = 0;
    specs.space = 0;
    str = add_unsigned_to_string(arg, specs, str);
  } else if (*format == Pointer_address) {
    specs.spec = *format;
    if (specs.width < specs.accuracy) {
      specs.width = specs.accuracy;
      specs.length = 'm';
    }
    str = add_pointer_to_string(arg, specs, str);
  } else if (*format == Decimal_float) {
    specs.spec = Decimal_float;
    str = add_float_to_string(arg, str, specs);
  } else if (*format == Scientific_notation ||
             *format == Scientific_upper_notation) {
    specs.spec = *format;
    str = handle_exponential_specifier(arg, specs, str);
  } else if (*format == Short_decimal_float_upp ||
             *format == Short_decimal_float) {
    specs.spec = *format;
    specs.flag_g = 1;
    str = flag_g_view(arg, specs, str);
  } else if (*format == '%') {
    specs.spec = Character;
    str = add_char(str, specs, '%');
  }
  return str;
}

char *add_char(char *str, Spec specs, char a) {
  if (specs.width == 0 || specs.width == 1) {
    *str = a;
    str++;
  } else if (specs.minus == 0) {
    if (specs.zero == 0) {
      for (int i = 0; i < specs.width - 1; i++) {
        *str = ' ';
        str++;
      }
    } else {
      str = padding_zero(str, specs, 1);
    }
    *str = a;
    str++;
  } else if (specs.minus == 1) {
    *str = a;
    str++;
    for (int i = 0; i < specs.width - 1; i++) {
      *str = ' ';
      str++;
    }
  }
  return str;
}

char *add_string(char *str, char *formated_buf_string, Spec specs) {
  int lenspace;
  if (specs.accuracy == -1 ||
      (int)s21_strlen(formated_buf_string) < specs.accuracy) {
    lenspace = specs.width - s21_strlen(formated_buf_string);
  } else {
    lenspace = specs.width - specs.accuracy;
  }
  str = format_formated_buf_stringer_with_padding(lenspace, specs, str,
                                                  formated_buf_string);
  return str;
}

char *add_int_to_string(va_list *arg, Spec specs, char *str) {
  long int number = 0;
  int flag_minus = 0;
  int lengh_int;
  if (specs.length == Argument_long_int) {
    number = va_arg(*arg, long int);
  } else if (specs.length == Argument_short_int) {
    number = (short)va_arg(*arg, int);
  } else {
    number = (int)va_arg(*arg, int);
  }
  char *formated_buf_string = '\0';
  if (number < 0) {
    flag_minus = 1;
    number *= -1;
  }
  lengh_int = size_decimal(number);
  char buf[512];
  checking_for_max_scale(&specs);
  formated_buf_string = int_to_str(number, specs, buf, lengh_int, flag_minus);
  str = add_int(str, formated_buf_string, specs);
  return str;
}

void checking_for_max_scale(Spec *specs) {
  if (specs->accuracy > 510) {
    specs->accuracy = 510;
  }
  if (specs->width > 500) {
    specs->width = 500;
  }
}

char *add_unsigned_to_string(va_list *arg, Spec specs, char *str) {
  int lengh_u = 0, flag_minus = 0;
  unsigned long int number = 0;
  if (specs.length == Argument_long_int) {
    number = (unsigned long int)va_arg(*arg, unsigned long int);
  } else if (specs.length == Argument_short_int) {
    number = (short unsigned int)va_arg(*arg, int);
  } else {
    number = (unsigned int)va_arg(*arg, unsigned int);
  }
  char *formated_buf_string = '\0';
  lengh_u = size_decimal(number);
  char buf[512];
  checking_for_max_scale(&specs);
  formated_buf_string = int_to_str(number, specs, buf, lengh_u, flag_minus);
  str = add_int(str, formated_buf_string, specs);
  return str;
}

char *add_pointer_to_string(va_list *arg, Spec specs, char *str) {
  unsigned long int number = (unsigned long int)va_arg(*arg, unsigned long int);
  char *formated_buf_string = '\0';
  int lengh_p = size_decimal(number);
  checking_for_max_scale(&specs);
  if (specs.width > lengh_p) {
    lengh_p = specs.width;
  }
  char buf[512];
  if (number != 0) {
    formated_buf_string = pointer_to_string(number, specs, buf);
    if (specs.space == 1 &&
        specs.width > (int)s21_strlen(formated_buf_string)) {
      specs.space = 0;
    }
    str = add_int(str, formated_buf_string, specs);
  } else {
    str = add_string(str, "(nil)", specs);
  }
  return str;
}

char *add_float_to_string(va_list *arg, char *str, Spec specs) {
  int isNegative = 0;
  long double number = 0.0;
  if (specs.length == Argument_long_double) {
    number = va_arg(*arg, long double);
  } else {
    number = (double)va_arg(*arg, double);
  }
  if (specs.accuracy == -1 && specs.flag_pointer == 1) {
    specs.accuracy = 0;
  }
  specs.accuracy = (specs.accuracy == -1) ? 6 : specs.accuracy;
  str = convert_float_to_str(specs, number, str, isNegative);
  return str;
}

char *convert_float_to_str(Spec specs, long double f, char *str,
                           int isNegative) {
  long double ipart;
  long double fpart;
  int lengh_f = 0;
  checking_for_max_scale(&specs);
  int size_buf = specs.width;
  analyze_float(specs, f, &isNegative, &ipart, &fpart, &size_buf);
  char formated_buf_string[512];
  char *buf = formated_buf_string;
  buf = float_int_to_str(ipart, &lengh_f, buf, isNegative, specs);
  if (specs.flag_g) {
    specs.space = 0;
  }
  backwards_str(buf, lengh_f);
  buf = format_float_with_specs(buf, &lengh_f, specs, fpart);
  *buf = '\0';
  buf = buf - lengh_f;
  if (specs.flag_g == 1 && specs.inwidth == 0) {
    specs.width = s21_strlen(buf);
  }
  str = add_int(str, buf, specs);
  return str;
}

char *handle_exponential_specifier(va_list *arg, Spec specs, char *str) {
  long double number = 0.0;
  int counter = 0;
  int isNegative = 0;
  if (specs.length == Argument_long_double) {
    number = (long double)va_arg(*arg, long double);
  } else {
    number = (double)va_arg(*arg, double);
  }
  if (number < 0) {
    isNegative = 1;
    number = -number;
  }
  if (specs.accuracy == -1 && specs.flag_pointer == 1) {
    specs.accuracy = 0;
  }
  specs.accuracy = (specs.accuracy == -1) ? 6 : specs.accuracy;
  counter = counter_for_pow(&number);
  str = format_float_with_exponent(specs, number, str, counter, isNegative);

  return str;
}

char *format_float_with_exponent(Spec specs, long double number, char *str,
                                 int counter, int isNegative) {
  long double ipart, fpart;
  int size_buf = 0, lengh_f = 0;
  checking_for_max_scale(&specs);
  analyze_float(specs, number, &isNegative, &ipart, &fpart, &size_buf);
  if (ipart >= 10.0) {
    ipart = ipart / 10;
    counter++;
  }
  char formated_buf_string[512];
  char *buf = formated_buf_string;
  buf = float_int_to_str(ipart, &lengh_f, buf, isNegative, specs);
  if (specs.flag_g == 1) {
    specs.space = 0;
  }
  backwards_str(buf, lengh_f);
  buf = format_float_with_specs(buf, &lengh_f, specs, fpart);
  buf = add_exptostr(specs, buf, counter, &lengh_f);
  if (specs.flag_g == 1 && specs.inwidth == 0) {
    specs.width = s21_strlen(buf);
  }
  str = add_int(str, buf, specs);
  return str;
}

char *flag_g_view(va_list *arg, Spec specs, char *str) {
  if (specs.width == 0) {
    specs.width = DEFAULT_WIDTH;
  }
  long double number = 0.0;
  int counter = 0;
  int isNegative = 0;
  if (specs.length == Argument_long_double) {
    number = va_arg(*arg, long double);
  } else {
    number = (double)va_arg(*arg, double);
  }
  if (number < 0) {
    isNegative = 1;
    number = -number;
  }
  long double number1 = number;
  counter = counter_for_pow(&number);
  if ((counter >= -5 && counter <= 5) ||
      (specs.accuracy > counter && counter > 0)) {
    if ((specs.accuracy == -1 || specs.accuracy == 0) &&
        specs.flag_pointer == 1) {
      specs.accuracy = 1 - counter - 1;
      specs.flag_accuracy = 1;
    } else if (specs.accuracy == -1) {
      specs.accuracy = DEFAULT_WIDTH - counter - 1;
    } else {
      specs.accuracy = specs.accuracy - counter - 1;
      specs.flag_accuracy = 1;
    }
    specs.spec = Decimal_float;
    double scalingFacto = pow(10, specs.accuracy);
    number1 = round(number1 * scalingFacto) / scalingFacto;
    str = convert_float_to_str(specs, number1, str, isNegative);
  } else {
    if (specs.spec == Short_decimal_float) {
      specs.spec = Scientific_notation;
    } else {
      specs.spec = Scientific_upper_notation;
    }
    if (specs.accuracy == -1) {
      specs.accuracy = DEFAULT_WIDTH - 1;
    } else {
      specs.accuracy = specs.accuracy - 1;
      specs.flag_accuracy = 1;
    }
    double scalingFacto = pow(10, specs.accuracy);
    number = round(number * scalingFacto) / scalingFacto;
    str = format_float_with_exponent(specs, number, str, counter, isNegative);
  }
  return str;
}

char *padding_zero(char *buf, Spec specs, int lengh_int) {
  int width = specs.width;
  if (specs.flag_g == 1) {
    width = lengh_int;
    lengh_int = 0;
  }
  if (specs.spec == Pointer_address) {
    width = specs.accuracy;
  }
  if (specs.length == 'm') {
    lengh_int = lengh_int - 2;
  }
  while (width != lengh_int) {
    lengh_int++;
    *buf = '0';
    buf++;
  }
  return buf;
}

char *format_formated_buf_stringer_with_padding(int lenspace, Spec specs,
                                                char *str,
                                                char *formated_buf_string) {
  if (specs.flag_g == 1 && specs.minus == 0 && lenspace != 0 &&
      specs.zero == 1) {
    specs.accuracy = specs.width - s21_strlen(formated_buf_string);
  }
  if (lenspace > 0) {
    if (specs.minus == 0 &&
        (specs.zero == 0 ||
         (specs.zero == 1 && specs.minus == 0 && specs.flag_g != 1))) {
      str = space_to_str(str, lenspace);
      str = buf_to_str(str, formated_buf_string, specs);
    } else if (specs.minus == 0 && specs.zero == 1 &&
               (specs.spec == String || specs.flag_g == 1)) {
      str = padding_zero(str, specs, specs.accuracy);
      str = buf_to_str(str, formated_buf_string, specs);
    } else {
      str = buf_to_str(str, formated_buf_string, specs);
      str = space_to_str(str, lenspace);
    }
  } else {
    str = buf_to_str(str, formated_buf_string, specs);
  }
  return str;
}

char *space_to_str(char *str, int lenspace) {
  for (int i = 0; i < lenspace; i++) {
    *str = ' ';
    str++;
  }
  return str;
}

char *buf_to_str(char *str, char *formated_buf_string, Spec specs) {
  int i = -1;
  int res = -10;
  if (specs.accuracy != -1) {
    i = 1;
    res = 0;
  }
  if (formated_buf_string != s21_NULL) {
    if (specs.accuracy < (int)s21_strlen(formated_buf_string) &&
        (specs.spec == Signed_decimal_integer ||
         specs.spec == Unsigned_dec_int || specs.spec == Unsigned_octal ||
         specs.spec == Unsigned_hexadec_int ||
         specs.spec == Unsigned_upp_hexadec_int ||
         specs.spec == Pointer_address || specs.spec == Decimal_float ||
         specs.spec == Scientific_notation ||
         specs.spec == Scientific_upper_notation)) {
      specs.accuracy = s21_strlen(formated_buf_string);
    }
    while (*formated_buf_string && res < specs.accuracy) {
      if (specs.spec == Unsigned_upp_hexadec_int &&
          (*formated_buf_string >= 97 && *formated_buf_string <= 102)) {
        *formated_buf_string = *formated_buf_string - 32;
      }
      *str = *formated_buf_string;
      res = res + i;
      str++;
      formated_buf_string++;
    }
  }
  return str;
}

int size_decimal(long int num) {
  int i = 0;
  if (num == 0) {
    i = 1;
  } else {
    while (num > 0) {
      num = num / 10;
      i++;
    }
  }
  return i;
}

char *int_to_str(long int num, Spec specs, char *buf, int lengh_int1,
                 int flag_minus) {
  int lengh_int = lengh_int1;
  int flag_zero = 0;
  if (num == 0) {
    flag_zero = 1;
  }
  buf = format_formated_buf_stringer_with_padding_int_to_string(specs, num, buf,
                                                                &lengh_int);
  buf = helpaddzero_add_int_to_string(specs, buf, &lengh_int, flag_minus);
  buf = helpaddflagtostr_add_int_to_string(flag_minus, buf, &lengh_int, specs,
                                           flag_zero);
  *buf = '\0';
  buf = buf - lengh_int;
  backwards_str(buf, lengh_int);
  return buf;
}

char *format_formated_buf_stringer_with_padding_int_to_string(Spec specs,
                                                              long int num,
                                                              char *buf,
                                                              int *lengh_int) {
  int notation = 10;
  int lengh_no10notation = 0;
  if (specs.spec == Unsigned_octal) {
    notation = 8;
  } else if (specs.spec == Unsigned_hexadec_int ||
             specs.spec == Unsigned_upp_hexadec_int) {
    notation = 16;
  }
  if (num < 9) {
    *buf = num + '0';
    lengh_no10notation++;
    buf++;
  } else {
    while (num > 0) {
      *buf = transnumber[num % notation];
      buf++;
      num = num / notation;
      lengh_no10notation++;
    }
  }
  if (specs.spec != Signed_decimal_integer) {
    *lengh_int = lengh_no10notation;
  }
  return buf;
}

char *helpaddzero_add_int_to_string(Spec specs, char *buf, int *lengh_int,
                                    int flag_minus) {
  if (specs.accuracy > *lengh_int) {
    while (specs.accuracy != *lengh_int) {
      *lengh_int = *lengh_int + 1;
      *buf = '0';
      buf++;
    }
  } else if (specs.zero == 1 && specs.width != 0 && specs.minus == 0 &&
             specs.accuracy == -1) {
    int k = 0;
    if (flag_minus == 1 || specs.plus == 1) {
      k = 1;
    }
    buf = padding_zero(buf, specs, *lengh_int + k);
    *lengh_int = specs.width - k;
  }
  return buf;
}

char *helpaddflagtostr_add_int_to_string(int flag_minus, char *buf,
                                         int *lengh_int, Spec specs,
                                         int flag_zero) {
  if (flag_minus == 1) {
    *buf = '-';
    (*lengh_int)++;
    buf++;
  } else if (flag_minus == 0 && specs.plus == 1) {
    *buf = '+';
    (*lengh_int)++;
    buf++;
  }
  if (specs.decpoint == 1 && flag_zero == 0 && specs.spec == Unsigned_octal) {
    *buf = '0';
    (*lengh_int)++;
    buf++;
  } else if (specs.decpoint == 1 && flag_zero == 0 &&
             (specs.spec == Unsigned_hexadec_int ||
              specs.spec == Unsigned_upp_hexadec_int)) {
    *buf = specs.spec;
    buf++;
    *buf = '0';
    buf++;
    *lengh_int = *lengh_int + 2;
  }
  return buf;
}

void backwards_str(char *buf, int lengh_int) {
  char *start = buf;
  char *end = buf + lengh_int - 1;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

char *add_int(char *str, char *formated_buf_string, Spec specs) {
  if (formated_buf_string[0] == '0' && specs.accuracy == 0 &&
      s21_strlen(formated_buf_string) == 1 && specs.spec != Decimal_float) {
    formated_buf_string++;
  } else if (formated_buf_string[0] == '+' && formated_buf_string[1] == '0' &&
             specs.accuracy == 0) {
    formated_buf_string++;
    *formated_buf_string = '+';
  }
  int lenspace = 0;
  if (specs.space == 1 && specs.plus == 0 && formated_buf_string[0] != '-' &&
      specs.width <= (int)s21_strlen(formated_buf_string)) {
    lenspace = 1;
    specs.minus = 0;

  } else if (specs.width > (int)s21_strlen(formated_buf_string)) {
    lenspace = specs.width - s21_strlen(formated_buf_string);
  }
  str = format_formated_buf_stringer_with_padding(lenspace, specs, str,
                                                  formated_buf_string);
  return str;
}

char *pointer_to_string(unsigned long int num, Spec specs, char *buf) {
  int notation = 16;
  int lengh = 2;
  if (specs.plus == 1) {
    lengh++;
  }
  if (num < 9) {
    *buf = num + '0';
    lengh++;
    buf++;
  } else {
    while (num > 0) {
      *buf = transnumber[num % notation];
      buf++;
      num = num / notation;
      lengh++;
    }
  }
  if (specs.zero == 1 && specs.accuracy == -1) {
    specs.accuracy = specs.width;
  }
  if (specs.accuracy > lengh && (specs.zero == 1 || specs.length == 'm')) {
    buf = padding_zero(buf, specs, lengh);
    if (specs.width > lengh) {
      lengh = specs.width;
    }
    if (specs.length == 'm') {
      lengh = lengh + 2;
    }
  }
  *buf = Unsigned_hexadec_int;
  buf++;
  *buf = '0';
  buf++;
  if (specs.plus == 1) {
    *buf = '+';
    buf++;
  }
  *buf = '\0';
  buf = buf - lengh;
  backwards_str(buf, lengh);
  return buf;
}

void analyze_float(Spec specs, long double f, int *isNegative,
                   long double *ipart, long double *fpart, int *size_buf) {
  double fact = pow(10, specs.accuracy);
  f = round(f * fact) / fact;
  if (f < 0) {
    *isNegative = 1;
    f = -f;
  }
  *fpart = modfl(f, ipart);
  int len_d = size_decimal(*ipart);
  if ((len_d + specs.accuracy + 3) > specs.width) {
    *size_buf = len_d + specs.accuracy + 3;
  }
}

char *float_int_to_str(long int ipart, int *lengh_f, char *buf, int isNegative,
                       Spec specs) {
  if (ipart == 0) {
    *lengh_f = *lengh_f + 1;
    *buf = ipart % 10 + '0';
    buf++;
  }
  if (specs.decpoint == 1 || specs.accuracy != 0) {
    *lengh_f = *lengh_f + 1;
  }
  if (isNegative || specs.plus == 1) {
    *lengh_f = *lengh_f + 1;
  }
  while (ipart != 0) {
    *lengh_f = *lengh_f + 1;
    *buf = ipart % 10 + '0';
    buf++;
    ipart /= 10;
  }
  int len = specs.accuracy + *lengh_f;
  if (specs.spec == Scientific_notation ||
      specs.spec == Scientific_upper_notation) {
    len = len + 4;
  }
  if (specs.width > len && specs.minus == 0 && specs.zero == 1) {
    while (specs.width != len) {
      *buf = '0';
      buf++;
      len++;
      *lengh_f = *lengh_f + 1;
    }
  }
  if (isNegative) {
    *buf = '-';
    buf++;
  } else if (specs.plus == 1) {
    *buf = '+';
    buf++;
  } else if (specs.space == 1 && specs.flag_g == 1) {
    *buf = ' ';
    specs.space = 0;
    buf++;
    *lengh_f = *lengh_f + 1;
  }
  if (specs.decpoint == 1 || specs.accuracy != 0) {
    *lengh_f = *lengh_f - 1;
  }
  buf = buf - *lengh_f;
  return buf;
}

char *format_float_with_specs(char *buf, int *lengh_f, Spec specs,
                              long double fpart) {
  buf = buf + *lengh_f;
  int acc = 0;
  long double fpart1 = fpart;
  if (specs.flag_g == 1 && (specs.spec == Scientific_notation ||
                            specs.spec == Scientific_upper_notation ||
                            specs.spec == Decimal_float)) {
    for (int j = 0; j < specs.accuracy; j++) {
      fpart1 = fpart1 + DELTA;
      fpart1 *= 10;
      int digit = fpart1;
      if (digit != 0) {
        acc = j + 1;
      }
      fpart1 -= digit;
    }
    if (acc == 0 && specs.decpoint == 1 && specs.flag_g == 1 &&
        specs.accuracy != 0 && specs.flag_accuracy) {
      acc = 1;
    }
    if (specs.decpoint == 1 && specs.flag_g == 1 &&
        ((int)s21_strlen(buf) >= specs.width || specs.inwidth == 1)) {
      acc = specs.accuracy;
    }
    specs.accuracy = acc;
  }
  if (specs.accuracy != 0 || specs.decpoint == 1) {
    *lengh_f = *lengh_f + 1;
    *buf = '.';
    buf++;
  }
  int argument = 11;
  if (specs.spec == Decimal_float || specs.accuracy >= 16) {
    argument = 10;
  }
  for (int j = 0; j < specs.accuracy; j++) {
    *lengh_f = *lengh_f + 1;

    if (specs.accuracy >= 10) {
      fpart = fpart + pow(10, -(argument + (specs.accuracy - 10)));
    } else {
      fpart = fpart + DELTA1;
    }
    fpart *= 10;
    int digit = fpart;
    if (digit == 0) {
      *buf = '0';
    } else {
      *buf = digit + '0';
    }
    buf++;
    fpart -= digit;
  }
  return buf;
}

int counter_for_pow(long double *number) {
  int counter = 0;
  if (*number != 0) {
    if (*number < 1) {
      while (*number < 1) {
        *number = *number * 10;
        counter = counter - 1;
      }
    } else {
      while (*number >= 10) {
        *number = *number / 10;
        counter++;
      }
    }
  }
  return counter;
}

char *add_exptostr(Spec specs, char *buf, int counter, int *lengh_f) {
  *buf = specs.spec;
  buf++;
  *lengh_f = *lengh_f + 2;
  if (counter >= 0) {
    *buf = '+';
    buf++;
  } else {
    counter = -counter;
    *buf = '-';
    buf++;
  }
  if (counter >= 100) {
    *buf = '0' + counter / 100;
    counter = counter - (counter / 100) * 100;
    buf++;
    *lengh_f = *lengh_f + 1;
  }
  *buf = '0' + counter / 10;
  buf++;
  *buf = '0' + counter % 10;
  buf++;
  *lengh_f = *lengh_f + 2;
  *buf = '\0';
  buf = buf - *lengh_f;
  return buf;
}
