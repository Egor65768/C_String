#include "test.h"

START_TEST(insert_1) {
  char str[] = "Hello, World!";
  char str_insert[] = "Beautiful ";
  size_t start_index = 7;
  char *res = s21_insert(str, str_insert, start_index);
  char str_res[] = "Hello, Beautiful World!";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_2) {
  char str[] = "Hello !";
  char str_insert[] = "Beautiful";
  size_t start_index = 6;
  char *res = s21_insert(str, str_insert, start_index);
  char str_res[] = "Hello Beautiful!";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_3) {
  char str[] = "Hello, World!";
  char str_insert[] = " Hello, World!";
  size_t start_index = 12;
  char *res = s21_insert(str, str_insert, start_index);
  char str_res[] = "Hello, World Hello, World!!";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_4) {
  char str[] = "";
  char str_insert[] = "";
  size_t start_index = 0;
  char *res = s21_insert(str, str_insert, start_index);
  char str_res[] = "";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_5) {
  char str[] = "Hello, World!";
  char str_insert[] = "Beautiful ";
  size_t start_index = 0;
  char *res = s21_insert(str, str_insert, start_index);
  char str_res[] = "Beautiful Hello, World!";
  ck_assert_str_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_6) {
  char str[] = "Hello, World!";
  char str_insert[] = "Beautiful ";
  size_t start_index = 100;
  char *res = s21_insert(str, str_insert, start_index);
  ck_assert_ptr_null(res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_7) {
  char *str = NULL;
  char str_insert[] = "Beautiful ";
  size_t start_index = 33;
  char *res = s21_insert(str, str_insert, start_index);
  ck_assert_ptr_null(res);
  if (res) free(res);
}
END_TEST

START_TEST(insert_8) {
  char str[] = "Hello, World!";
  char *str_insert = NULL;
  size_t start_index = 33;
  char *res = s21_insert(str, str_insert, start_index);
  ck_assert_ptr_null(res);
  if (res) free(res);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m-=s21_insert=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, insert_1);
  tcase_add_test(tc_core, insert_2);
  tcase_add_test(tc_core, insert_3);
  tcase_add_test(tc_core, insert_4);
  tcase_add_test(tc_core, insert_5);
  tcase_add_test(tc_core, insert_6);
  tcase_add_test(tc_core, insert_7);
  tcase_add_test(tc_core, insert_8);
  suite_add_tcase(s, tc_core);

  return s;
}