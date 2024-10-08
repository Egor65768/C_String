#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  if (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src)) {
  } else {
    s21_size_t len_src = s21_strlen(str) + s21_strlen(src);
    res = (char *)malloc(sizeof(char) * (len_src + 1));
    s21_size_t i = 0, j = 0, k = 0;
    while (src[i] != '\0') {
      if (i == start_index) {
        while (str[j] != '\0') {
          res[k] = str[j];
          k++;
          j++;
        }
      }
      res[k] = src[i];
      k++;
      i++;
    }
    res[k] = '\0';
  }
  return res;
}