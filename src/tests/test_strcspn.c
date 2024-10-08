#include "test.h"

START_TEST(strcspn_1) {
  char str1[] = "qwe";
  char str2[] = "qwer";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "abc";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "wnhgo3rwejfpwffvr";
  char str2[] = "4";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "irejp jmvoi3fiejger ngondsv ge";
  char str2[] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char str1[] = "Running suite(s): -=s21_memchr=-";
  char str2[] = "-=s21_memchr=-";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char str1[] = "1234567890";
  char str2[] = "1";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char str1[] = "\n\n\n\n\n\nn\\n\n\n\n\\n\n\n\n\n\n\n\n\n";
  char str2[] = "n";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  char str1[] = "\n\n\n\n\n\nn\\n\n\n\n\\n\n\n\n\n\n\n\n\n";
  char str2[] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  char str1[] = "\n\n\n\n\n\nn\\n\n\n\n\\n\n\n\n\n\n\n\n\n";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s = suite_create("\033[45m-=s21_strcspn=-\033[0m");
  TCase *tc = tcase_create("strcspn_test");
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);

  suite_add_tcase(s, tc);

  return s;
}