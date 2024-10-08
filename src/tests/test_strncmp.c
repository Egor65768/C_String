#include "test.h"

START_TEST(strncmp_1) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World!";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello!";
  int n = 6;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  const char *str1 = "Hello!";
  const char *str2 = "Hello World!";
  int n = 6;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  const char *str1 = "Hi";
  const char *str2 = "Bay";
  int n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  const char *str1 = "Bay";
  const char *str2 = "Hi";
  int n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World!";
  int n = 26;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  const char *str1 = " Hello World!";
  const char *str2 = "Hello World!";
  int n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  const char *str1 = "Hello World! ";
  const char *str2 = "Hello World!";
  int n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World! ";
  int n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("\033[45m-=s21_strncmp=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, strncmp_1);
  tcase_add_test(tc_core, strncmp_2);
  tcase_add_test(tc_core, strncmp_3);
  tcase_add_test(tc_core, strncmp_4);
  tcase_add_test(tc_core, strncmp_5);
  tcase_add_test(tc_core, strncmp_6);
  tcase_add_test(tc_core, strncmp_7);
  tcase_add_test(tc_core, strncmp_8);
  tcase_add_test(tc_core, strncmp_9);
  suite_add_tcase(s, tc_core);

  return s;
}