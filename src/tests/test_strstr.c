#include "test.h"

START_TEST(strstr_1) {
  char *src = "asdfght";
  char *src1 = "asdfght";
  ck_assert_pstr_eq(s21_strstr(src, src1), strstr(src, src1));
}

START_TEST(strstr_2) {
  char *src = "asdfght";
  char *src1 = "t";
  ck_assert_pstr_eq(s21_strstr(src, src1), strstr(src, src1));
}

START_TEST(strstr_3) {
  char *src = "asdfght";
  char *src1 = "a";
  ck_assert_pstr_eq(s21_strstr(src, src1), strstr(src, src1));
}

START_TEST(strstr_4) {
  char *src = "";
  char *src1 = "";
  ck_assert_pstr_eq(s21_strstr(src, src1), strstr(src, src1));
}

START_TEST(strstr_5) {
  char *src = "asd";
  char *src1 = "f";
  ck_assert(s21_strstr(src, src1) == s21_NULL);
}

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45m-=s21_strstr=-\033[0m");
  TCase *tc = tcase_create("strstr_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);

  return s;
}