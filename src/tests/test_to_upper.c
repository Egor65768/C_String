#include "test.h"

START_TEST(to_upper_1) {
  char str[] = "Washington D.C.";
  char str_upper[] = "WASHINGTON D.C.";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, str_upper);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_2) {
  char str[] = "1234567890";
  char str_upper[] = "1234567890";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, str_upper);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_3) {
  char str[] = "aBcDeFgHiJkLmNoPqRsTuVwXyZ";
  char str_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, str_upper);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_4) {
  char str[] = "";
  char str_upper[] = "";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, str_upper);
  if (res) free(res);
}
END_TEST

START_TEST(to_upper_5) {
  char str[] = "de3f234f23g4f4g234tqf234f42h77G)*&G*^Ggpreggpw";
  char str_upper[] = "DE3F234F23G4F4G234TQF234F42H77G)*&G*^GGPREGGPW";
  char *res = s21_to_upper(str);
  ck_assert_str_eq(res, str_upper);
  if (res) free(res);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("\033[45m-=s21_to_upper=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, to_upper_1);
  tcase_add_test(tc_core, to_upper_2);
  tcase_add_test(tc_core, to_upper_3);
  tcase_add_test(tc_core, to_upper_4);
  tcase_add_test(tc_core, to_upper_5);
  suite_add_tcase(s, tc_core);

  return s;
}