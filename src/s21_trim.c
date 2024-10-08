#include "s21_string.h"

int fstart(const char *src, const char *trim_chars, int ind_start) {
  int res = 0;
  s21_size_t len = s21_strlen(trim_chars);
  for (s21_size_t i = 0; i < len; i++) {
    if (src[ind_start] == '\0') {
      break;
    }
    if (src[ind_start] == trim_chars[i]) {
      res = 1;
    }
  }
  return res;
}

int fend(const char *src, const char *trim_chars, int ind_end) {
  int res = 0;
  s21_size_t len = s21_strlen(trim_chars);
  for (s21_size_t i = 0; i < len; i++) {
    if (ind_end < 0) {
      break;
    }
    if (src[ind_end] == trim_chars[i]) {
      res = 1;
    }
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src && trim_chars) {
    if (src != s21_NULL && trim_chars != s21_NULL) {
      int ind_start = 0;
      int ind_end = s21_strlen(src) - 1;
      while (fstart(src, trim_chars, ind_start)) {
        ind_start++;
      }
      while (fend(src, trim_chars, ind_end)) {
        ind_end--;
      }
      if (ind_start <= ind_end) {
        int i;
        res = (char *)malloc(sizeof(char) * ((ind_end - ind_start) + 2));
        for (i = 0; ind_start <= ind_end; i++) {
          res[i] = src[ind_start];
          ind_start++;
        }
        res[i] = '\0';
      } else {
        res = (char *)malloc(sizeof(char) * 1);
        res[0] = '\0';
      }
    }
  }
  return res;
}