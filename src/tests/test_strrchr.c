#include "test.h"

START_TEST(strrchr_1) {
  char str1[] = "21324536a6bc";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_2) {
  char str1[] = "21324536a6bc";
  int n = '2';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_3) {
  char str1[] = "21324536a6bc";
  int n = '7';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_4) {
  char str1[] = "21324536a6bc";
  int n = ' ';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_5) {
  char str1[] = "";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_6) {
  char str1[] = "2";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_7) {
  char str1[] = "";
  int n = '\n';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_8) {
  char str1[3] = "adc";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_9) {
  char str1[] = "aoooooooooooooooa";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_10) {
  char str1[] = "aoooooooooooooooa";
  int n = 'h';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_11) {
  char str1[3] = "";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_12) {
  char str1[5] = "\0qefd";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[45m-=s21_strrchr=-\033[0m");
  TCase *tc = tcase_create("strrchr_test");
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);
  tcase_add_test(tc, strrchr_11);
  tcase_add_test(tc, strrchr_12);

  suite_add_tcase(s, tc);

  return s;
}