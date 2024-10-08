#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int check = 0;
  for (int i = 0; *(str1 + i) != '\0'; i++) {
    for (int j = 0; *(str2 + j) != '\0'; j++) {
      if (check == 0 && *(str1 + i) == *(str2 + j)) {
        result = (char *)&(*(str1 + i));
        check = 1;
      }
    }
  }
  return result;
}
