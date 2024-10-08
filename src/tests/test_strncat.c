#include "test.h"

START_TEST(strncat_1) {
  char str1[10] = "abc";
  char str2[9] = "abc";
  char sstr1[10] = "abc";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_2) {
  char str1[10] = "ab\nc";
  char str2[10] = "ab\nc";
  char sstr1[10] = "ab\nc";
  int n = 0;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_3) {
  char str1[9] = "kpa";
  char str2[9] = "??";
  char sstr1[9] = "kpa";
  int n = 2;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_4) {
  char str1[9] = "fuc";
  char str2[9] = "k";
  char sstr1[9] = "fuc";
  int n = 4;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_5) {
  char str1[9] = " ";
  char str2[9] = "";
  char sstr1[9] = " ";
  int n = 0;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_6) {
  char str1[9] = " ";
  char str2[9] = "";
  char sstr1[9] = " ";
  int n = 1;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_7) {
  char str1[9] = "hu";
  char str2[9] = "eta";
  char sstr1[9] = "hu";
  int n = 3;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_8) {
  char str1[9] = "hu";
  char str2[9] = "e33ta";
  char sstr1[9] = "hu";
  int n = 3;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_9) {
  char str1[9] = "qerg";
  char str2[9] = "eta";
  char sstr1[9] = "qerg";
  int n = 3;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(sstr1, str2, n));
}
END_TEST

START_TEST(strncat_10) {
  char str1[9] = "hu";
  char str2[9] = "eta";
  int n = 5;
  ck_assert_str_eq(strncat(str1, str2, n), s21_strncat(str1, str2, n));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m-=s21_strncat=-\033[0m");
  TCase *tc = tcase_create("strncat_test");
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);

  suite_add_tcase(s, tc);

  return s;
}