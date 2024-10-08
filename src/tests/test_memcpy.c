#include "test.h"

START_TEST(memcpy_1) {
  char str1[] = "Привет, мир!";
  char str2[50];

  ck_assert_ptr_eq(s21_memcpy(str2, str1, strlen(str1) + 1),
                   memcpy(str2, str1, strlen(str1) + 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = "";
  char str2[50] = "Hello World";

  ck_assert_ptr_eq(s21_memcpy(str2, str1, strlen(str1) + 1),
                   memcpy(str2, str1, strlen(str1) + 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memcpy_3) {
  char str1[1000];
  for (int i = 0; i < 999; i++) {
    str1[i] = 'a';
  }
  str1[999] = '\0';
  char str2[1000];

  ck_assert_ptr_eq(s21_memcpy(str2, str1, strlen(str1) + 1),
                   memcpy(str2, str1, strlen(str1) + 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "Hello World";
  char str2[50] = "";
  size_t n = 5;
  ck_assert_ptr_eq(s21_memcpy(str2, str1, n), memcpy(str2, str1, n));
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(memcpy_5) {
  char str1[] = "Hello World";
  char str2[50] = "";
  size_t n = 0;
  ck_assert_ptr_eq(s21_memcpy(str2, str1, n), memcpy(str2, str1, n));
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(memcpy_6) {
  char str1[] = "Hello World";
  char str2[50] = "";
  size_t n = strlen(str1) + 1;

  ck_assert_ptr_eq(s21_memcpy(str2, str1, n), memcpy(str2, str1, n));
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(memcpy_7) {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {0};
  size_t n = sizeof(arr1);
  ck_assert_ptr_eq(s21_memcpy(arr2, arr1, n), memcpy(arr2, arr1, n));
  ck_assert_mem_eq(arr1, arr2, n);
}
END_TEST

START_TEST(memcpy_8) {
  int arr1[5] = {0};
  int arr2[5] = {1, 2, 3, 4, 5};
  size_t n = sizeof(arr1);
  ck_assert_ptr_eq(s21_memcpy(arr2, arr1, n), memcpy(arr2, arr1, n));
  ck_assert_mem_eq(arr1, arr2, n);
}
END_TEST

START_TEST(memcpy_9) {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {0};
  size_t n = sizeof(arr1);
  ck_assert_ptr_eq(s21_memcpy(arr2, arr1, n), memcpy(arr2, arr1, n));
  ck_assert_mem_eq(arr1, arr2, n);
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[45m-=s21_memcpy=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, memcpy_1);
  tcase_add_test(tc_core, memcpy_2);
  tcase_add_test(tc_core, memcpy_3);
  tcase_add_test(tc_core, memcpy_4);
  tcase_add_test(tc_core, memcpy_5);
  tcase_add_test(tc_core, memcpy_6);
  tcase_add_test(tc_core, memcpy_7);
  tcase_add_test(tc_core, memcpy_8);
  tcase_add_test(tc_core, memcpy_9);
  suite_add_tcase(s, tc_core);

  return s;
}