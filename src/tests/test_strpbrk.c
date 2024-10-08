#include "test.h"

START_TEST(strpbrk_test1) {
  char dest[] = "My name is Max";
  char src[] = "fjkse";
  ck_assert_pstr_eq(s21_strpbrk(dest, src), strpbrk(dest, src));
}
START_TEST(strpbrk_test2) {
  char dest[] = "My name is Max";
  char src[] = "";
  ck_assert_pstr_eq(s21_strpbrk(dest, src), strpbrk(dest, src));
}
START_TEST(strpbrk_test3) {
  char dest[] = "My name is Max";
  char src[] = "d";
  ck_assert_pstr_eq(s21_strpbrk(dest, src), strpbrk(dest, src));
}
START_TEST(strpbrk_test4) {
  char dest[] = "";
  char src[] = "dsdf";
  ck_assert_pstr_eq(s21_strpbrk(dest, src), strpbrk(dest, src));
}
START_TEST(strpbrk_test5) {
  char dest[] = "";
  char src[] = "";
  ck_assert_pstr_eq(s21_strpbrk(dest, src), strpbrk(dest, src));
}

Suite *test_strpbrk() {
  Suite *s = suite_create("\033[45m-=s21_strpbrk=-\033[0m");
  TCase *tc = tcase_create("strncpy_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strpbrk_test1);
  tcase_add_test(tc, strpbrk_test2);
  tcase_add_test(tc, strpbrk_test3);
  tcase_add_test(tc, strpbrk_test4);
  tcase_add_test(tc, strpbrk_test5);

  return s;
}