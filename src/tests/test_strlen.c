#include "test.h"

START_TEST(strlen_1) {
  const char *str = "";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  const char *str = "Zdorova";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  const char *str =
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  const char *str = "safd324234sdfsdf";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  const char *str = "\n";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  const char *str = "\0";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  const char *str =
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
      "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  const char *str = "“Привет, мир! 🌍”";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  const char *str = "  Hello World   ";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *test_strlen(void) {
  Suite *s = suite_create("\033[45m-=s21_strlen=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, strlen_1);
  tcase_add_test(tc_core, strlen_2);
  tcase_add_test(tc_core, strlen_3);
  tcase_add_test(tc_core, strlen_4);
  tcase_add_test(tc_core, strlen_5);
  tcase_add_test(tc_core, strlen_6);
  tcase_add_test(tc_core, strlen_7);
  tcase_add_test(tc_core, strlen_8);
  tcase_add_test(tc_core, strlen_9);
  suite_add_tcase(s, tc_core);

  return s;
}