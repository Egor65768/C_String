#include "test.h"

START_TEST(to_lower_1) {
  char str[] = "Washington D.C.";
  char str_lower[] = "washington d.c.";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, str_lower);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_2) {
  char str[] = "1234567890";
  char str_lower[] = "1234567890";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, str_lower);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_3) {
  char str[] = "aBcDeFgHiJkLmNoPqRsTuVwXyZ";
  char str_lower[] = "abcdefghijklmnopqrstuvwxyz";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, str_lower);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_4) {
  char str[] = "";
  char str_lower[] = "";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, str_lower);
  if (res) free(res);
}
END_TEST

START_TEST(to_lower_5) {
  char str[] = "de3f234f23g4f4g234tqf234f42h77G)*&G*^Ggpreggpw";
  char str_lower[] = "de3f234f23g4f4g234tqf234f42h77g)*&g*^ggpreggpw";
  char *res = s21_to_lower(str);
  ck_assert_str_eq(res, str_lower);
  if (res) free(res);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("\033[45m-=s21_to_lower=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, to_lower_1);
  tcase_add_test(tc_core, to_lower_2);
  tcase_add_test(tc_core, to_lower_3);
  tcase_add_test(tc_core, to_lower_4);
  tcase_add_test(tc_core, to_lower_5);
  suite_add_tcase(s, tc_core);

  return s;
}