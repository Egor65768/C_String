#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  char* res = s21_NULL;
  if (*needle == '\0') {
    res = (char*)haystack;
  } else {
    while (*haystack != '\0') {
      if (*haystack == *needle) {
        char* t = (char*)haystack;
        char* p = (char*)needle;

        while (*t != '\0' && *p != '\0' && *t == *p) {
          t++;
          p++;
        }
        if (*p == '\0') res = (char*)haystack;
      }
      haystack++;
    }
  }
  return res;
}
