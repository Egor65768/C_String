#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *backup_string;
  if (!str) {
    if (!backup_string || *backup_string == '\0') {
      return s21_NULL;
    }
    str = backup_string;
  }
  while (*str && s21_strchr(delim, *str)) {
    ++str;
  }
  if (*str == '\0') {
    return s21_NULL;
  }
  char *ret = str;
  char *next_delim = s21_strpbrk(str, delim);
  if (next_delim) {
    *next_delim = '\0';
    backup_string = next_delim + 1;
  } else {
    backup_string = str + s21_strlen(str);
  }
  return ret;
}
