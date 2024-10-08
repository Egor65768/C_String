#include "test.h"

int main() {
  int failed = 0;
  Suite *s21_string_test[] = {test_memchr(),   test_strncat(),  test_strcspn(),
                              test_strrchr(),  test_memset(),   test_strncpy(),
                              test_strpbrk(),  test_memcmp(),   test_strchr(),
                              test_strerror(), test_strstr(),   test_strlen(),
                              test_memcpy(),   test_strncmp(),  test_strtok(),
                              test_to_upper(), test_to_lower(), test_insert(),
                              test_trim(),     test_sprintf(),  NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
