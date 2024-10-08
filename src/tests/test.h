#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *test_strlen(void);
Suite *test_memcpy(void);
Suite *test_strncmp(void);
Suite *test_strtok(void);
Suite *test_to_upper(void);
Suite *test_to_lower(void);
Suite *test_insert(void);
Suite *test_trim(void);
Suite *test_memcmp(void);
Suite *test_strchr(void);
Suite *test_strerror(void);
Suite *test_strstr(void);
Suite *test_strpbrk();
Suite *test_memset();
Suite *test_strncpy();
Suite *test_memchr(void);
Suite *test_strncat(void);
Suite *test_strcspn(void);
Suite *test_strrchr(void);
Suite *test_sprintf(void);

#endif
