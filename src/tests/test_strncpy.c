#include "test.h"

START_TEST(strncpy_test1) {
  char dest[] = "My name is Max";
  char src[] = "fjkse";
  size_t count = 5;
  ck_assert_pstr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
START_TEST(strncpy_test2) {
  char dest[] = "111111111";
  char src[] = "2345678903";
  size_t count = 4;
  ck_assert_pstr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
START_TEST(strncpy_test3) {
  char dest[] = "111111111";
  char src[] = "234\000678903";
  size_t count = 9;
  ck_assert_pstr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
START_TEST(strncpy_test4) {
  char dest[] = "qwertasdf";
  char src[] = "e";
  size_t count = 5;
  ck_assert_pstr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}
START_TEST(strncpy_test5) {
  char dest[] = "qwerff";
  char src[] = "\n";
  size_t count = 5;
  ck_assert_pstr_eq(s21_strncpy(dest, src, count), strncpy(dest, src, count));
}

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[45m-=s21_strncpy=-\033[0m");
  TCase *tc = tcase_create("strncpy_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncpy_test1);
  tcase_add_test(tc, strncpy_test2);
  tcase_add_test(tc, strncpy_test3);
  tcase_add_test(tc, strncpy_test4);
  tcase_add_test(tc, strncpy_test5);

  return s;
}