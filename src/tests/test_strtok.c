#include "test.h"

START_TEST(strtok_1) {
  char str[] = "8-996-999-65-98";
  char str2[] = "8-996-999-65-98";
  char *tmp;
  char *tmp2;
  const char *delim = "-";
  tmp = strtok(str, delim);
  tmp2 = s21_strtok(str2, delim);
  while (tmp || tmp2) {
    ck_assert_str_eq(tmp, tmp2);
    tmp = strtok(NULL, delim);
    tmp2 = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(strtok_2) {
  char str[] = "8-996-999-65-98 8-996-999-65-98";
  char str2[] = "8-996-999-65-98 8-996-999-65-98";
  char *tmp;
  char *tmp2;
  const char *delim = "- ";
  tmp = strtok(str, delim);
  tmp2 = s21_strtok(str2, delim);
  while (tmp || tmp2) {
    ck_assert_str_eq(tmp, tmp2);
    tmp = strtok(NULL, delim);
    tmp2 = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(strtok_3) {
  char str[] = "";
  const char *delim = "-";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "-8-996-999-65-98-";
  char str2[] = "-8-996-999-65-98-";
  char *tmp;
  char *tmp2;
  const char *delim = "-";
  tmp = strtok(str, delim);
  tmp2 = s21_strtok(str2, delim);
  while (tmp || tmp2) {
    ck_assert_str_eq(tmp, tmp2);
    tmp = strtok(NULL, delim);
    tmp2 = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(strtok_5) {
  char str[] = "8--996---999----65-----98";
  char str2[] = "8--996---999----65-----98";
  char *tmp;
  char *tmp2;
  const char *delim = "-";
  tmp = strtok(str, delim);
  tmp2 = s21_strtok(str2, delim);
  while (tmp || tmp2) {
    ck_assert_str_eq(tmp, tmp2);
    tmp = strtok(NULL, delim);
    tmp2 = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(strtok_6) {
  char str[] = "8--996---9.9>9----6,5-----98";
  char str2[] = "8--996---9.9>9----6,5-----98";
  char *tmp;
  char *tmp2;
  const char *delim = "- . ,";
  tmp = strtok(str, delim);
  tmp2 = s21_strtok(str2, delim);
  while (tmp || tmp2) {
    ck_assert_str_eq(tmp, tmp2);
    tmp = strtok(NULL, delim);
    tmp2 = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(strtok_7) {
  char str[] = "Hello world!";
  const char *delim = " ";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_8) {
  char str[] = "Hello world!";
  const char *delim = "+";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_9) {
  char str[] =
      "Hello world!                                                            "
      "                 ";
  const char *delim = " ";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("\033[45m-=s21_strtok=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, strtok_1);
  tcase_add_test(tc_core, strtok_2);
  tcase_add_test(tc_core, strtok_3);
  tcase_add_test(tc_core, strtok_4);
  tcase_add_test(tc_core, strtok_5);
  tcase_add_test(tc_core, strtok_6);
  tcase_add_test(tc_core, strtok_7);
  tcase_add_test(tc_core, strtok_8);
  tcase_add_test(tc_core, strtok_9);
  suite_add_tcase(s, tc_core);

  return s;
}