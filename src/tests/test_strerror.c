#include "test.h"

START_TEST(strerror_1) {
  for (int i = 0; i < 107; i++) {
    ck_assert_pstr_eq(s21_strerror(i), strerror(i));
  }
}

START_TEST(strerror_2) {
  ck_assert_pstr_eq(s21_strerror(-1), "Unknown error: -1");
}

START_TEST(strerror_3) { ck_assert_pstr_eq(s21_strerror(0), strerror(0)); }

START_TEST(strerror_4) { ck_assert_pstr_eq(s21_strerror(130), strerror(130)); }

Suite *test_strerror(void) {
  Suite *s = suite_create("\033[45m-=s21_strerror=-\033[0m");
  TCase *tc = tcase_create("strerror_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);

  return s;
}