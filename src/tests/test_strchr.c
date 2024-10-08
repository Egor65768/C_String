#include "test.h"

START_TEST(strchr_1) {
  char src[5] = "12340";
  int n = '1';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_2) {
  char src[5] = "12340";
  int n = 'k';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_3) {
  char src[5] = "12341";
  int n = 4;
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

// START_TEST(strchr_4) {
//   char src[0] = "";
//   int n = 'k';
//   ck_assert_pstr_eq(s21_strchr(src, n), s21_NULL);
// }
// END_TEST

START_TEST(strchr_5) {
  char src[7] = "123a4a";
  int n = 'a';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_6) {
  char src[7] = "123aaa";
  int n = 0;
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_7) {
  char src[20] = "aaaaAAAAaaa";
  int n = '\0';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_8) {
  char src[20] = "aaaaAAAAaaa";
  int n = 'A';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_9) {
  char src[20] = "aaaa\000AAaaa";
  int n = 'A';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_10) {
  char src[20] = "aaaa\000AAaaa";
  int n = '\0';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[45m-=s21_strchr=-\033[0m");
  TCase *tc = tcase_create("strchr_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  // tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);
  return s;
}