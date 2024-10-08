#include "test.h"

START_TEST(trim_1) {
  char src[] = "  Hello, World!  ";
  char trim_chars[] = " ";
  char *res = s21_trim(src, trim_chars);
  char str_res[] = "Hello, World!";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(trim_2) {
  char src[] = "..Hello**";
  char trim_chars[] = ".*";
  char *res = s21_trim(src, trim_chars);
  char str_res[] = "Hello";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(trim_3) {
  char src[] = "";
  char trim_chars[] = "";
  char *res = s21_trim(src, trim_chars);
  char str_res[] = "";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(trim_4) {
  char src[] = "..**";
  char trim_chars[] = ".*";
  char *res = s21_trim(src, trim_chars);
  char str_res[] = "";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(trim_5) {
  char src[] = "..F**";
  char trim_chars[] = ".*";
  char *res = s21_trim(src, trim_chars);
  char str_res[] = "F";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(trim_6) {
  char *src = NULL;
  char trim_chars[] = ".*";
  char *res = s21_trim(src, trim_chars);
  ck_assert_ptr_null(res);
  if (res) free(res);
}
END_TEST

START_TEST(trim_7) {
  char src[] = "    ";
  char trim_chars[] = ".*";
  char *res = s21_trim(src, trim_chars);
  char str_res[] = "    ";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("\033[45m-=s21_trim=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, trim_1);
  tcase_add_test(tc_core, trim_2);
  tcase_add_test(tc_core, trim_3);
  tcase_add_test(tc_core, trim_4);
  tcase_add_test(tc_core, trim_5);
  tcase_add_test(tc_core, trim_6);
  tcase_add_test(tc_core, trim_7);
  suite_add_tcase(s, tc_core);

  return s;
}