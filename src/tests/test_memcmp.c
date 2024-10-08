#include "test.h"

START_TEST(memcmp_1) {
  char src[5] = "12340";
  char srd[5] = "1234 ";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}

START_TEST(memcmp_2) {
  char src[5] = "12340";
  char srd[5] = "1234-";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}

START_TEST(memcmp_3) {
  char src[5] = "12341";
  char srd[5] = "1234-";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}

START_TEST(memcmp_4) {
  char src[0] = "";
  char srd[0] = "";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}

Suite *test_memcmp(void) {
  Suite *s = suite_create("\033[45m-=s21_memcmp=-\033[0m");
  TCase *tc = tcase_create("memcmp_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);

  return s;
}