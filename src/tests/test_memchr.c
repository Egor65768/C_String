#include "test.h"

START_TEST(memchr_1) {
  char str[] = "pampampam";
  int c = 'm';
  size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "pam";
  int c = 'm';
  size_t n = sizeof(str) - sizeof(char);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "pam";
  int c = 'a';
  size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "mpam";
  int c = 'm';
  size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "pam";
  int c = 'a';
  size_t n = sizeof(str) - 2 * sizeof(char);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "";
  int c = 'a';
  size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "abs";
  int c = 'a';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "asd";
  int c = ' ';
  size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "GNOiee";
  int c = 'i';
  size_t n = sizeof(str) - 4;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_10) {
  char str[13] = "GNOiee";
  int c = '\0';
  size_t n = 10;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s = suite_create("\033[45m-=s21_memchr=-\033[0m");
  TCase *tc = tcase_create("memchr_test");
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);

  suite_add_tcase(s, tc);

  return s;
}