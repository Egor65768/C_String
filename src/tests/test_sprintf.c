#include "test.h"

START_TEST(sprintf1_c) {
  char str1[128];
  char str2[128];

  char *format = "pan pan % c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_c) {
  char str1[128];
  char str2[128];

  char *format = "pan pan % -+4c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_c) {
  char str1[128];
  char str2[128];

  char *format = "pan pan % -+4.1c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_c) {
  char str1[128];
  char str2[128];

  char *format = "%c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_c) {
  char str1[128];
  char str2[128];

  char *format = "%.0c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_s) {
  char str1[128];
  char str2[128];

  char *format = "%+-3.4s kfgl %s";
  ck_assert_int_eq(s21_sprintf(str1, format, "pwfeprke", "effwlk ff"),
                   sprintf(str2, format, "pwfeprke", "effwlk ff"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_s) {
  char str1[128];
  char str2[128];

  char *format = "%.0s kfgl %.0s";
  ck_assert_int_eq(s21_sprintf(str1, format, "pwfeprke", "effwlk ff"),
                   sprintf(str2, format, "pwfeprke", "effwlk ff"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_s) {
  char str1[128];
  char str2[128];

  char *format = "%-24s kfgl %-5s";
  ck_assert_int_eq(s21_sprintf(str1, format, "pwfeprke", "effwlk ff"),
                   sprintf(str2, format, "pwfeprke", "effwlk ff"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_s) {
  char str1[128];
  char str2[128];

  char *format = "%+-3.4s kfgl % s";
  ck_assert_int_eq(s21_sprintf(str1, format, "pwfeprke", "effwlk ff"),
                   sprintf(str2, format, "pwfeprke", "effwlk ff"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_s) {
  char str1[128];
  char str2[128];

  char *format = "%+-3.4s kfgl % .3s";
  ck_assert_int_eq(s21_sprintf(str1, format, "pwfeprke", "effwlk ff"),
                   sprintf(str2, format, "pwfeprke", "effwlk ff"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_d) {
  char str1[128];
  char str2[128];

  char *format = "%d kfgl %d";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, -134567),
                   sprintf(str2, format, 123, -134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_d) {
  char str1[128];
  char str2[128];

  char *format = "% d kfgl % +-d";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, -134567),
                   sprintf(str2, format, 123, -134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_d) {
  char str1[128];
  char str2[128];

  char *format = "%-12d kfgl % +-.5d";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, -134567),
                   sprintf(str2, format, 0, -134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_d) {
  char str1[128];
  char str2[128];

  char *format = "% d kfgl %+- 12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, -134567),
                   sprintf(str2, format, 123, -134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_d) {
  char str1[128];
  char str2[128];

  char *format = "%+-d kfgl %+-12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, -13),
                   sprintf(str2, format, 13, -13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_d) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4d kfgl %+- 12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, -13),
                   sprintf(str2, format, 13, -13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4d kfgl % s %+- 12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, "her", -13),
                   sprintf(str2, format, 13, "her", -13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4d kfgl % -.7s %+- 12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, "her", -13),
                   sprintf(str2, format, 13, "her", -13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4d fgtrke %+-3.5s %+- 12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, "her", -13),
                   sprintf(str2, format, 13, "her", -13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4d fgtrke %+-3.5s %+- .12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, "her", -0),
                   sprintf(str2, format, 0, "her", -0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.0d fgtrke %+-3.0s %+- .12d";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, "heeeeer", 0),
                   sprintf(str2, format, 0, "heeeeer", 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.0d fgtrke %+-3.0s %+- .0d";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, "heeeeer", 0),
                   sprintf(str2, format, 0, "heeeeer", 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_csd) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.0d fgtrke %+-3.0s %+- .0d";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, "heeeeer", 0),
                   sprintf(str2, format, 0, "heeeeer", 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_u) {
  char str1[128];
  char str2[128];

  char *format = "%u kfgl %u";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_u) {
  char str1[128];
  char str2[128];

  char *format = "% u kfgl % +-u";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_u) {
  char str1[128];
  char str2[128];

  char *format = "%-12u kfgl % +-.5u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 4567),
                   sprintf(str2, format, 0, 4567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_u) {
  char str1[128];
  char str2[128];

  char *format = "% u kfgl %+- 12u";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_u) {
  char str1[128];
  char str2[128];

  char *format = "%+-u kfgl %+-12u";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_u) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4u kfgl %+- 12u";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_o) {
  char str1[128];
  char str2[128];

  char *format = "%o kfgl %o";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_o) {
  char str1[128];
  char str2[128];

  char *format = "% o kfgl % +-o";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_o) {
  char str1[128];
  char str2[128];

  char *format = "%-12o kfgl % +-.5o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 4567),
                   sprintf(str2, format, 0, 4567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_o) {
  char str1[128];
  char str2[128];

  char *format = "% o kfgl %+- 12o";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_o) {
  char str1[128];
  char str2[128];

  char *format = "%+-o kfgl %+-12o";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_o) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4o kfgl %+- 12o";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_x) {
  char str1[128];
  char str2[128];

  char *format = "%x kfgl %x";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_x) {
  char str1[128];
  char str2[128];

  char *format = "% x kfgl % +-x";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_x) {
  char str1[128];
  char str2[128];

  char *format = "%-12x kfgl % +-.5x";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_x) {
  char str1[128];
  char str2[128];

  char *format = "% x kfgl %+- 12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_x) {
  char str1[128];
  char str2[128];

  char *format = "%+-x kfgl %+-12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_x) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4x kfgl %+- 12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_X) {
  char str1[128];
  char str2[128];

  char *format = "%X kfgl %X";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_X) {
  char str1[128];
  char str2[128];

  char *format = "% X kfgl % +-X";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_X) {
  char str1[128];
  char str2[128];

  char *format = "%-12X kfgl % +-.5X";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_X) {
  char str1[128];
  char str2[128];

  char *format = "% X kfgl %+- 12X";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_X) {
  char str1[128];
  char str2[128];

  char *format = "%+-X kfgl %+-12X";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_X) {
  char str1[128];
  char str2[128];

  char *format = "%+-2.4X kfgl %+- 12X";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// тесты с #
START_TEST(sprintf1_sharp) {
  char str1[128];
  char str2[128];
  char *format = "%+-#2.4x kfgl %+- #12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_sharp) {
  char str1[128];
  char str2[128];

  char *format = "% #x kfgl % #+-x";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_sharp) {
  char str1[128];
  char str2[128];

  char *format = "%-12x kfgl % +-#.5x";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_sharp) {
  char str1[128];
  char str2[128];

  char *format = "% #x kfgl %+- #12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_sharp) {
  char str1[128];
  char str2[128];

  char *format = "% #X kfgl %+- #12X";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_sharp) {
  char str1[128];
  char str2[128];

  char *format = "% #o kfgl %+- #12o";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_sharp) {
  char str1[128];
  char str2[128];

  char *format = "% #X kfgl % #+-X";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8_sharp) {
  char str1[128];
  char str2[128];

  char *format = "% #o kfgl % #+-o";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9_sharp) {
  char str1[128];
  char str2[128];

  char *format = "%-12X kfgl % +-#.5X";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10_sharp) {
  char str1[128];
  char str2[128];

  char *format = "%-12o kfgl % +-#.5o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// тесты с 0

START_TEST(sprintf1_zero) {
  char str1[128];
  char str2[128];
  char *format = "%+-#02.4d kfgl %+- #012d";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_zero) {
  char str1[128];
  char str2[128];

  char *format = "%014d kfgl %0#+-d";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_zero) {
  char str1[128];
  char str2[128];

  char *format = "%-012.0d kfgl % +-#0.5d";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_zero) {
  char str1[128];
  char str2[128];

  char *format = "%0+-#s kfgl %+-#0.12s";
  ck_assert_int_eq(s21_sprintf(str1, format, "obleamiinedumali", "huetahueta"),
                   sprintf(str2, format, "obleamiinedumali", "huetahueta"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_zero) {
  char str1[128];
  char str2[128];

  char *format = "%0+-#s kfgl %+-#032s";
  ck_assert_int_eq(s21_sprintf(str1, format, "obleamiinedumali", "huetahueta"),
                   sprintf(str2, format, "obleamiinedumali", "huetahueta"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_zero) {
  char str1[128];
  char str2[128];

  char *format = "% 0#s kfgl %+- 0#12s";
  ck_assert_int_eq(s21_sprintf(str1, format, "121233", "3114567"),
                   sprintf(str2, format, "121233", "3114567"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_zero) {
  char str1[128];
  char str2[128];

  char *format = "% #0s kfgl %+-#12s";
  ck_assert_int_eq(s21_sprintf(str1, format, "121233", "3114567"),
                   sprintf(str2, format, "121233", "3114567"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8_zero) {
  char str1[128];
  char str2[128];

  char *format = "% #0c kfgl %+-#12c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a', 'a'),
                   sprintf(str2, format, 'a', 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10_zero) {
  char str1[128];
  char str2[128];

  char *format = "%0.3c kfgl %0c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a', 'a'),
                   sprintf(str2, format, 'a', 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_zerou) {
  char str1[128];
  char str2[128];

  char *format = "%0u kfgl %0u";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_zerou) {
  char str1[128];
  char str2[128];

  char *format = "% 0u kfgl % +-0u";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_zerou) {
  char str1[128];
  char str2[128];

  char *format = "%-012u kfgl % +-0.5u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 4567),
                   sprintf(str2, format, 0, 4567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_zerou) {
  char str1[128];
  char str2[128];

  char *format = "% 0u kfgl %+- 012u";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_zerou) {
  char str1[128];
  char str2[128];

  char *format = "%0+-u kfgl %+-012u";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_zerou) {
  char str1[128];
  char str2[128];

  char *format = "%+-02.4u kfgl %+-0 12u";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_zeroo) {
  char str1[128];
  char str2[128];

  char *format = "%0o kfgl %0o";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_zeroo) {
  char str1[128];
  char str2[128];

  char *format = "% 0o kfgl % +-0o";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_zeroo) {
  char str1[128];
  char str2[128];

  char *format = "%-012o kfgl % +-0.5o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 4567),
                   sprintf(str2, format, 0, 4567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_zeroo) {
  char str1[128];
  char str2[128];

  char *format = "% 0o kfgl %+- 012o";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_zeroo) {
  char str1[128];
  char str2[128];

  char *format = "%0+-o kfgl %+-012o";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_zeroo) {
  char str1[128];
  char str2[128];

  char *format = "%+-02.4o kfgl %+- 012o";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_zerox) {
  char str1[128];
  char str2[128];

  char *format = "%0x kfgl %0x";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_zerox) {
  char str1[128];
  char str2[128];

  char *format = "% 0x kfgl % +0-x";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_zerox) {
  char str1[128];
  char str2[128];

  char *format = "%-012x kfgl % +0-.5x";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_zerox) {
  char str1[128];
  char str2[128];

  char *format = "%0 x kfgl %+- 012x";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_zerox) {
  char str1[128];
  char str2[128];

  char *format = "%+0-x kfgl %0+-12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_zerox) {
  char str1[128];
  char str2[128];

  char *format = "%+-02.4x kfgl %+-0 12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_zeroX) {
  char str1[128];
  char str2[128];

  char *format = "%0X kfgl %0X";
  ck_assert_int_eq(s21_sprintf(str1, format, 23, 134567),
                   sprintf(str2, format, 23, 134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_zeroX) {
  char str1[128];
  char str2[128];

  char *format = "% 0X kfgl % +-0X";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34567),
                   sprintf(str2, format, 123, 34567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_zeroX) {
  char str1[128];
  char str2[128];

  char *format = "%-012X kfgl % +-0.5X";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 458538967),
                   sprintf(str2, format, 0, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_zeroX) {
  char str1[128];
  char str2[128];

  char *format = "%0 X kfgl %+- 012X";
  ck_assert_int_eq(s21_sprintf(str1, format, 121233, 3114567),
                   sprintf(str2, format, 121233, 3114567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_zeroX) {
  char str1[128];
  char str2[128];

  char *format = "%+-0X kfgl %+-012X";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 13),
                   sprintf(str2, format, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_zeroX) {
  char str1[128];
  char str2[128];

  char *format = "%+-02.4X kfgl %+- 012X";
  ck_assert_int_eq(s21_sprintf(str1, format, 13121312, 13121312),
                   sprintf(str2, format, 13121312, 13121312));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_star) {
  char str1[128];
  char str2[128];
  char *format = "%+-*.*s kfgl %+-*.*s";
  ck_assert_int_eq(
      s21_sprintf(str1, format, 20, 12, "obleamiinedumali", 13, 1,
                  "huetahueta"),
      sprintf(str2, format, 20, 12, "obleamiinedumali", 13, 1, "huetahueta"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_star) {
  char str1[128];
  char str2[128];
  char *format = "%+-#*.*s kfgl %+#-*.*s";
  ck_assert_int_eq(
      s21_sprintf(str1, format, 50, 12, "obleamiinedumali", 13, 1,
                  "huetahueta"),
      sprintf(str2, format, 50, 12, "obleamiinedumali", 13, 1, "huetahueta"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_star) {
  char str1[128];
  char str2[128];
  char *format = "%+-0*.*s kfgl %+-0*.*s";
  ck_assert_int_eq(
      s21_sprintf(str1, format, 50, 12, "obleamiinedumali", 50, 1,
                  "huetahueta"),
      sprintf(str2, format, 50, 12, "obleamiinedumali", 50, 1, "huetahueta"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_star) {
  char str1[128];
  char str2[128];

  char *format = "pan pan % *.*c";
  ck_assert_int_eq(s21_sprintf(str1, format, 13, 2, 'a'),
                   sprintf(str2, format, 13, 2, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_star) {
  char str1[128];
  char str2[128];

  char *format = "%0+-#*.*d kfgl %*.*d";
  ck_assert_int_eq(s21_sprintf(str1, format, 12, 4, 123, 7, 4, -134567),
                   sprintf(str2, format, 12, 4, 123, 7, 4, -134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_star) {
  char str1[128];
  char str2[128];

  char *format = "%0+-#*.*d kfgl %*.*d";
  ck_assert_int_eq(s21_sprintf(str1, format, 12, 12, 123, 12, 12, -134567),
                   sprintf(str2, format, 12, 12, 123, 12, 12, -134567));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_star) {
  char str1[128];
  char str2[128];

  char *format = "%0+-*u kfgl %+-012.*u";
  ck_assert_int_eq(s21_sprintf(str1, format, 5, 13, 5, 13),
                   sprintf(str2, format, 5, 13, 5, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8_star) {
  char str1[128];
  char str2[128];

  char *format = "%+0-*.*x kfgl %0+-12x";
  ck_assert_int_eq(s21_sprintf(str1, format, 4, 4, 13, 13),
                   sprintf(str2, format, 4, 4, 13, 13));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9_star) {
  char str1[128];
  char str2[128];

  char *format = "%-012.*X kfgl % +-0*.5X";
  ck_assert_int_eq(s21_sprintf(str1, format, 4, 0, 10, 458538967),
                   sprintf(str2, format, 4, 0, 10, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10_star) {
  char str1[128];
  char str2[128];

  char *format = "%-012.*X kfgl % +-0*.5X";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 0, 10, 458538967),
                   sprintf(str2, format, 0, 0, 10, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf11_star) {
  char str1[128];
  char str2[128];

  char *format = "%-+012.*X kfgl % +-0*.5X";
  ck_assert_int_eq(s21_sprintf(str1, format, 4, 2345, 10, 458538967),
                   sprintf(str2, format, 4, 2345, 10, 458538967));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_pointer) {
  char str1[128];
  char str2[128];
  int x = 183;
  char het = 'a';
  char *format = "%p kfgl %p";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, &het),
                   sprintf(str2, format, &x, &het));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_pointer) {
  char str1[128];
  char str2[128];
  int x = 183;
  char het = 'a';
  char *format = "%20p kfgl %-12p";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, &het),
                   sprintf(str2, format, &x, &het));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_pointer) {
  char str1[128];
  char str2[128];
  int x = 183;
  char het = 'a';
  char *format = "%-022.12p kfgl %-12p";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, &het),
                   sprintf(str2, format, &x, &het));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_pointer) {
  char str1[128];
  char str2[128];
  int x = 183;
  char het = 'a';
  char *format = "%#20p kfgl %-12p";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, &het),
                   sprintf(str2, format, &x, &het));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_space) {
  char str1[128];
  char str2[128];

  char *format = "% d kfgl % 20d";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 34),
                   sprintf(str2, format, 123, 34));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_float) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 0.001;
  char *format = "%f kfgl %f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_float) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 0.001;
  char *format = "%+12.3f kfgl %#.1f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_float) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 0;
  char *format = "% +-#0*.*f kfgl %012.3f";
  ck_assert_int_eq(s21_sprintf(str1, format, 12, 4, x, y),
                   sprintf(str2, format, 12, 4, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_float) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 0;
  char *format = "% +-#0*.*f kfgl %012.3f";
  ck_assert_int_eq(s21_sprintf(str1, format, 12, 4, x, y),
                   sprintf(str2, format, 12, 4, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf6_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%.5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf7_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf8_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5.5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf9_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf11_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf12_float) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(sprintf13_float) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 13.543;
  char *format = "% f kfgl %012.3f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf14_float) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 0;
  char *format = "% +-#014.4f kfgl %12.8f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf15_float) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 0;
  char *format = "%f kfgl %12.8f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf16_float) {
  char str1[128];
  char str2[128];
  float x = 99999.9;
  float y = 0;
  char *format = "%f kfgl %12.8f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf17_float) {
  char str1[128];
  char str2[128];
  float x = 9999.9;
  float y = 99999132.13;
  char *format = "%f kfgl %12.8f";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 0.001;
  char *format = "%e kfgl %e";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_eE) {
  char str1[128];
  char str2[128];
  float x = 18234556787653.9990;
  float y = 0.00441;
  char *format = "%+12.3e kfgl %#.1e";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_eE) {
  char str1[128];
  char str2[128];
  float x = 1.23;
  float y = 0.300101;
  char *format = "%e kfgl %E";
  ck_assert_int_eq(s21_sprintf(str1, format, 12, 4, x, y),
                   sprintf(str2, format, 12, 4, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 123.234;
  char *format = "% +-#0*.*e kfgl %3E";
  ck_assert_int_eq(s21_sprintf(str1, format, 12, 4, x, y),
                   sprintf(str2, format, 12, 4, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9;
  float y = 123.234;
  char *format = "% +-#0*.*e kfgl %3E";
  ck_assert_int_eq(s21_sprintf(str1, format, 0, 4, x, y),
                   sprintf(str2, format, 0, 4, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 0.001;
  char *format = "% 0#12e kfgl %.0e";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 0.0001;
  char *format = "%+- 12e kfgl %-12e";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8_eE) {
  char str1[128];
  char str2[128];
  float x = 182452564323.99490;
  float y = 0.001;
  char *format = "%+-12.0e kfgl %-#12e";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = -359248379.24;
  char *format = "%+- #12.0e kfgl %-12e";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 51302323252.5432;
  char *format = "%+- 12e kfgl %#-12.6e.6";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf11_eE) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  char *format = "% 0#12e ";
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf12_eE) {
  char str1[128];
  char str2[128];
  float y = 183.9990;
  char *format = "%.0e";
  ck_assert_int_eq(s21_sprintf(str1, format, y), sprintf(str2, format, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_Gg) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 14.2445331;
  char *format = "%g %g";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_Gg) {
  char str1[128];
  char str2[128];
  float x = 183.9990;
  float y = 123452.24;
  char *format = "%g %g";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_Gg) {
  char str1[128];
  char str2[128];
  float x = 1835643.9990;
  float y = 0.00001;
  char *format = "%G %g";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_Gg) {
  char str1[128];
  char str2[128];
  float x = 18124553.990;
  float y = 0.01230;
  char *format = "%G %g";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_Gg) {
  char str1[128];
  char str2[128];
  float x = 1280480232.1243;
  float y = 275925.3245;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_Gg) {
  char str1[128];
  char str2[128];
  float x = 0;
  float y = 0;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_Gg) {
  char str1[128];
  char str2[128];
  float x = 100000;
  float y = 0.0000001;
  char *format = "%g %g";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8_Gg) {
  char str1[128];
  char str2[128];
  float x = 99999;
  float y = 999999;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9_Gg) {
  char str1[128];
  char str2[128];
  float x = 99999.99;
  float y = 999999.99;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10_Gg) {
  char str1[128];
  char str2[128];
  float x = 0;
  float y = 0.9;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf11_Gg) {
  char str1[128];
  char str2[128];
  float x = 0.00099;
  float y = 2143254211.1323;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf12_Gg) {
  char str1[128];
  char str2[128];
  float x = 0.009999;
  float y = 0.0000099;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf13_Gg) {
  char str1[128];
  char str2[128];
  float x = 0;
  float y = 14685972402.3442;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf14_Gg) {
  char str1[128];
  char str2[128];
  float x = 100;
  float y = 100000;
  char *format = "%12.3G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf15_Gg) {
  char str1[128];
  char str2[128];
  float x = 0;
  float y = 14685972402.3442;
  char *format = "%12G %.3G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf16_Gg) {
  char str1[128];
  char str2[128];
  float x = 12.213334;
  float y = 14685972402.3442;
  char *format = "%12G %13G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf17_Gg) {
  char str1[128];
  char str2[128];
  float x = 73193.14;
  float y = 185972402.3442;
  char *format = "%12G %23G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf18_Gg) {
  char str1[128];
  char str2[128];
  float x = 7393.14;
  float y = 185972402.3442;
  char *format = "%12.4G %23.3G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf19_Gg) {
  char str1[128];
  char str2[128];
  float x = 73193.14;
  float y = 185972402.3442;
  char *format = "%24.8G %.1G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf20_Gg) {
  char str1[128];
  char str2[128];
  float x = 73.0122;
  float y = 12402.3442;
  char *format = "%.7G %.7G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf21_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 12402453343.3442;
  char *format = "%.7G %.7G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf22_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 1243.3442;
  char *format = "% G % G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf23_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 124023.3442;
  char *format = "%+G %+-G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf24_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 124023.3442;
  char *format = "%-+ 12G % -+30G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf25_Gg) {
  char str1[128];
  char str2[128];
  float x = 0;
  float y = 0;
  char *format = "%-+ 12G % G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf26_Gg) {
  char str1[128];
  char str2[128];
  float x = 34543.0122;
  float y = -1245377.422;
  char *format = "% 12.6G % -G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf27_Gg) {
  char str1[128];
  char str2[128];
  float x = -73343234543.0122;
  float y = -124023.34;
  char *format = "%- 12G % -34G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf28_Gg) {
  char str1[128];
  char str2[128];
  float x = 99999.99;
  float y = 9999.99;
  char *format = "%- 12G % -34G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf29_Gg) {
  char str1[128];
  char str2[128];
  float x = 99999.99;
  float y = 9999999.9;
  char *format = "%G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf30_Gg) {
  char str1[128];
  char str2[128];
  float x = 9999.999;
  float y = 0.00001;
  char *format = "%- 10G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf31_Gg) {
  char str1[128];
  char str2[128];
  float x = 73.01221;
  float y = 12402.3442;
  char *format = "%#0.7G %0.7G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf32_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 12402453343.3442;
  char *format = "%#G %0G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf33_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 1243.3442;
  char *format = "%014G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf34_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 124023.3442;
  char *format = "%#13G %015G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf35_Gg) {
  char str1[128];
  char str2[128];
  float x = 73343234543.0122;
  float y = 124023.3442;
  char *format = "%#12G %030G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf36_Gg) {
  char str1[128];
  char str2[128];
  float x = 120;
  float y = 0;
  char *format = "%12G %012G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf37_Gg) {
  char str1[128];
  char str2[128];
  float x = 34543.0122;
  float y = -1245377.422;
  char *format = "%#12.6G % -0G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf38_Gg) {
  char str1[128];
  char str2[128];
  float x = -73343234543.0122;
  float y = -124023.34;
  char *format = "%#12G % #0-34G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf39_Gg) {
  char str1[128];
  char str2[128];
  float x = 1234;
  float y = 9999.99;
  char *format = "%-+#012G % -34G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf40_Gg) {
  char str1[128];
  char str2[128];
  float x = 99999.99;
  float y = 9999999.9;
  char *format = "%#G %#G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf41_Gg) {
  char str1[128];
  char str2[128];
  float x = 13;
  float y = 0.0001;
  char *format = "%-0#12G %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf42_Gg) {
  char str1[128];
  char str2[128];
  float x = 0.00001;
  float y = 0.0001;
  char *format = "%g %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf43_Gg) {
  char str1[128];
  char str2[128];
  float x = 100000;
  float y = 10000;
  char *format = "%g %G";
  ck_assert_int_eq(s21_sprintf(str1, format, x, y),
                   sprintf(str2, format, x, y));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_len) {
  char str1[128];
  char str2[128];

  char *format = "%ld kfgl %hd";
  ck_assert_int_eq(s21_sprintf(str1, format, 123, 1),
                   sprintf(str2, format, 123, 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_len) {
  char str1[128];
  char str2[128];
  char *format = "%Lg kfgl %LG";
  ck_assert_int_eq(
      s21_sprintf(str1, format, 1232245434232431.421L, 1134244.34321L),
      sprintf(str2, format, 1232245434232431.421L, 1134244.34321L));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_len) {
  char str1[128];
  char str2[128];

  char *format = "%hd kfgl %hu";
  ck_assert_int_eq(s21_sprintf(str1, format, 1, 12),
                   sprintf(str2, format, 1, 12));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4_len) {
  char str1[128];
  char str2[128];

  char *format = "%ld kfgl %hx";
  ck_assert_int_eq(s21_sprintf(str1, format, 1233111, 1),
                   sprintf(str2, format, 1233111, 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5_len) {
  char str1[128];
  char str2[128];

  char *format = "%lo kfgl %lx";
  ck_assert_int_eq(s21_sprintf(str1, format, 1234567, 111112234),
                   sprintf(str2, format, 1234567, 111112234));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6_len) {
  char str1[128];
  char str2[128];

  char *format = "%c kfgl %c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'd', 's'),
                   sprintf(str2, format, 'd', 's'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7_len) {
  char str1[128];
  char str2[128];

  char *format = "%Le kfgl %LG";
  ck_assert_int_eq(s21_sprintf(str1, format, 1324343.2434L, 1234.1324354L),
                   sprintf(str2, format, 1324343.2434L, 1234.1324354L));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8_len) {
  char str1[128];
  char str2[128];

  char *format = "%Lg kfgl %LE";
  ck_assert_int_eq(s21_sprintf(str1, format, 1324343.2434L, 1234.1324354L),
                   sprintf(str2, format, 1324343.2434L, 1234.1324354L));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf1_last) {
  char str1[128];
  char str2[128];
  int x;
  char *format = "%12.19p kfgl %LE";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, 1234.1324354L),
                   sprintf(str2, format, &x, 1234.1324354L));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2_last) {
  char str1[128];
  char str2[128];
  int x;
  char *format = "%20p kfgl %LE";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, 1234.1324354L),
                   sprintf(str2, format, &x, 1234.1324354L));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3_last) {
  char str1[128];
  char str2[128];
  int x;
  char *format = "%020p kfgl %Lf";
  ck_assert_int_eq(s21_sprintf(str1, format, &x, 1234.1324354L),
                   sprintf(str2, format, &x, 1234.1324354L));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(wide_string) {
//   char str1[256];
//   char str2[256];

//   char *format = "This is a simple wide char %ls";
//   wchar_t w[] = L"увапримсыв";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string1) {
//   char str1[256];
//   char str2[256];

//   char *format = "This is a simple wide char %5.12ls";
//   wchar_t w[] = L"парапапааапа";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string2) {
//   char str1[256];
//   char str2[256];

//   char *format = "This is a simple wide char %120ls ABOBA";
//   wchar_t w[] = L"йцыы";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string3) {
//   char str1[256];
//   char str2[256];

//   char *format = "This is a simple wide char %-43ls";
//   wchar_t w[] = L"ааааацйц";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

Suite *test_sprintf(void) {
  Suite *s = suite_create("\033[45m-=s21_sprintf=-\033[0m");
  TCase *tc = tcase_create("sprintf_test");
  tcase_add_test(tc, sprintf1_c);
  tcase_add_test(tc, sprintf2_c);
  tcase_add_test(tc, sprintf3_c);
  tcase_add_test(tc, sprintf4_c);
  tcase_add_test(tc, sprintf5_c);
  tcase_add_test(tc, sprintf1_s);
  tcase_add_test(tc, sprintf2_s);
  tcase_add_test(tc, sprintf3_s);
  tcase_add_test(tc, sprintf4_s);
  tcase_add_test(tc, sprintf5_s);
  tcase_add_test(tc, sprintf1_d);
  tcase_add_test(tc, sprintf2_d);
  tcase_add_test(tc, sprintf3_d);
  tcase_add_test(tc, sprintf4_d);
  tcase_add_test(tc, sprintf5_d);
  tcase_add_test(tc, sprintf6_d);
  tcase_add_test(tc, sprintf1_csd);
  tcase_add_test(tc, sprintf2_csd);
  tcase_add_test(tc, sprintf3_csd);
  tcase_add_test(tc, sprintf4_csd);
  tcase_add_test(tc, sprintf5_csd);
  tcase_add_test(tc, sprintf6_csd);
  tcase_add_test(tc, sprintf7_csd);
  tcase_add_test(tc, sprintf1_u);
  tcase_add_test(tc, sprintf2_u);
  tcase_add_test(tc, sprintf3_u);
  tcase_add_test(tc, sprintf4_u);
  tcase_add_test(tc, sprintf5_u);
  tcase_add_test(tc, sprintf6_u);
  tcase_add_test(tc, sprintf1_o);
  tcase_add_test(tc, sprintf2_o);
  tcase_add_test(tc, sprintf3_o);
  tcase_add_test(tc, sprintf4_o);
  tcase_add_test(tc, sprintf5_o);
  tcase_add_test(tc, sprintf6_o);
  tcase_add_test(tc, sprintf1_x);
  tcase_add_test(tc, sprintf2_x);
  tcase_add_test(tc, sprintf3_x);
  tcase_add_test(tc, sprintf4_x);
  tcase_add_test(tc, sprintf5_x);
  tcase_add_test(tc, sprintf6_x);
  tcase_add_test(tc, sprintf1_X);
  tcase_add_test(tc, sprintf2_X);
  tcase_add_test(tc, sprintf3_X);
  tcase_add_test(tc, sprintf4_X);
  tcase_add_test(tc, sprintf5_X);
  tcase_add_test(tc, sprintf6_X);
  tcase_add_test(tc, sprintf1_sharp);
  tcase_add_test(tc, sprintf2_sharp);
  tcase_add_test(tc, sprintf3_sharp);
  tcase_add_test(tc, sprintf4_sharp);
  tcase_add_test(tc, sprintf5_sharp);
  tcase_add_test(tc, sprintf6_sharp);
  tcase_add_test(tc, sprintf7_sharp);
  tcase_add_test(tc, sprintf8_sharp);
  tcase_add_test(tc, sprintf9_sharp);
  tcase_add_test(tc, sprintf10_sharp);
  tcase_add_test(tc, sprintf1_zero);
  tcase_add_test(tc, sprintf2_zero);
  tcase_add_test(tc, sprintf3_zero);
  tcase_add_test(tc, sprintf4_zero);
  tcase_add_test(tc, sprintf5_zero);
  tcase_add_test(tc, sprintf6_zero);
  tcase_add_test(tc, sprintf7_zero);
  tcase_add_test(tc, sprintf8_zero);
  tcase_add_test(tc, sprintf10_zero);
  tcase_add_test(tc, sprintf1_zerou);
  tcase_add_test(tc, sprintf2_zerou);
  tcase_add_test(tc, sprintf3_zerou);
  tcase_add_test(tc, sprintf4_zerou);
  tcase_add_test(tc, sprintf5_zerou);
  tcase_add_test(tc, sprintf6_zerou);
  tcase_add_test(tc, sprintf1_zeroo);
  tcase_add_test(tc, sprintf2_zeroo);
  tcase_add_test(tc, sprintf3_zeroo);
  tcase_add_test(tc, sprintf4_zeroo);
  tcase_add_test(tc, sprintf5_zeroo);
  tcase_add_test(tc, sprintf6_zeroo);
  tcase_add_test(tc, sprintf1_zerox);
  tcase_add_test(tc, sprintf2_zerox);
  tcase_add_test(tc, sprintf3_zerox);
  tcase_add_test(tc, sprintf4_zerox);
  tcase_add_test(tc, sprintf5_zerox);
  tcase_add_test(tc, sprintf6_zerox);
  tcase_add_test(tc, sprintf1_zeroX);
  tcase_add_test(tc, sprintf2_zeroX);
  tcase_add_test(tc, sprintf3_zeroX);
  tcase_add_test(tc, sprintf4_zeroX);
  tcase_add_test(tc, sprintf5_zeroX);
  tcase_add_test(tc, sprintf6_zeroX);
  tcase_add_test(tc, sprintf1_star);
  tcase_add_test(tc, sprintf2_star);
  tcase_add_test(tc, sprintf3_star);
  tcase_add_test(tc, sprintf4_star);
  tcase_add_test(tc, sprintf5_star);
  tcase_add_test(tc, sprintf6_star);
  tcase_add_test(tc, sprintf7_star);
  tcase_add_test(tc, sprintf8_star);
  tcase_add_test(tc, sprintf9_star);
  tcase_add_test(tc, sprintf10_star);
  tcase_add_test(tc, sprintf11_star);
  tcase_add_test(tc, sprintf2_pointer);
  tcase_add_test(tc, sprintf3_pointer);
  tcase_add_test(tc, sprintf4_pointer);
  tcase_add_test(tc, sprintf5_pointer);
  tcase_add_test(tc, sprintf1_space);
  tcase_add_test(tc, sprintf1_float);
  tcase_add_test(tc, sprintf2_float);
  tcase_add_test(tc, sprintf3_float);
  tcase_add_test(tc, sprintf4_float);
  tcase_add_test(tc, sprintf5_float);
  tcase_add_test(tc, sprintf6_float);
  tcase_add_test(tc, sprintf7_float);
  tcase_add_test(tc, sprintf8_float);
  tcase_add_test(tc, sprintf9_float);
  tcase_add_test(tc, sprintf11_float);
  tcase_add_test(tc, sprintf12_float);
  tcase_add_test(tc, sprintf13_float);
  tcase_add_test(tc, sprintf14_float);
  tcase_add_test(tc, sprintf15_float);
  tcase_add_test(tc, sprintf16_float);
  tcase_add_test(tc, sprintf17_float);
  tcase_add_test(tc, sprintf1_eE);
  tcase_add_test(tc, sprintf2_eE);
  tcase_add_test(tc, sprintf3_eE);
  tcase_add_test(tc, sprintf4_eE);
  tcase_add_test(tc, sprintf5_eE);
  tcase_add_test(tc, sprintf6_eE);
  tcase_add_test(tc, sprintf7_eE);
  tcase_add_test(tc, sprintf8_eE);
  tcase_add_test(tc, sprintf9_eE);
  tcase_add_test(tc, sprintf10_eE);
  tcase_add_test(tc, sprintf11_eE);
  tcase_add_test(tc, sprintf12_eE);
  tcase_add_test(tc, sprintf1_Gg);
  tcase_add_test(tc, sprintf2_Gg);
  tcase_add_test(tc, sprintf3_Gg);
  tcase_add_test(tc, sprintf4_Gg);
  tcase_add_test(tc, sprintf5_Gg);
  tcase_add_test(tc, sprintf6_Gg);
  tcase_add_test(tc, sprintf7_Gg);
  tcase_add_test(tc, sprintf8_Gg);
  tcase_add_test(tc, sprintf9_Gg);
  tcase_add_test(tc, sprintf10_Gg);
  tcase_add_test(tc, sprintf11_Gg);
  tcase_add_test(tc, sprintf12_Gg);
  tcase_add_test(tc, sprintf13_Gg);
  tcase_add_test(tc, sprintf14_Gg);
  tcase_add_test(tc, sprintf15_Gg);
  tcase_add_test(tc, sprintf16_Gg);
  tcase_add_test(tc, sprintf17_Gg);
  tcase_add_test(tc, sprintf18_Gg);
  tcase_add_test(tc, sprintf19_Gg);
  tcase_add_test(tc, sprintf20_Gg);
  tcase_add_test(tc, sprintf21_Gg);
  tcase_add_test(tc, sprintf22_Gg);
  tcase_add_test(tc, sprintf23_Gg);
  tcase_add_test(tc, sprintf24_Gg);
  tcase_add_test(tc, sprintf25_Gg);
  tcase_add_test(tc, sprintf26_Gg);
  tcase_add_test(tc, sprintf27_Gg);
  tcase_add_test(tc, sprintf28_Gg);
  tcase_add_test(tc, sprintf29_Gg);
  tcase_add_test(tc, sprintf30_Gg);
  tcase_add_test(tc, sprintf31_Gg);
  tcase_add_test(tc, sprintf32_Gg);
  tcase_add_test(tc, sprintf33_Gg);
  tcase_add_test(tc, sprintf34_Gg);
  tcase_add_test(tc, sprintf35_Gg);
  tcase_add_test(tc, sprintf36_Gg);
  tcase_add_test(tc, sprintf37_Gg);
  tcase_add_test(tc, sprintf38_Gg);
  tcase_add_test(tc, sprintf39_Gg);
  tcase_add_test(tc, sprintf40_Gg);
  tcase_add_test(tc, sprintf41_Gg);
  tcase_add_test(tc, sprintf42_Gg);
  tcase_add_test(tc, sprintf43_Gg);
  tcase_add_test(tc, sprintf1_len);
  tcase_add_test(tc, sprintf2_len);
  tcase_add_test(tc, sprintf3_len);
  tcase_add_test(tc, sprintf4_len);
  tcase_add_test(tc, sprintf5_len);
  tcase_add_test(tc, sprintf6_len);
  tcase_add_test(tc, sprintf7_len);
  tcase_add_test(tc, sprintf8_len);
  tcase_add_test(tc, sprintf1_last);
  tcase_add_test(tc, sprintf2_last);
  tcase_add_test(tc, sprintf3_last);
  // tcase_add_test(tc, wide_string);
  // tcase_add_test(tc, wide_string1);
  // tcase_add_test(tc, wide_string2);
  // tcase_add_test(tc, wide_string3);
  suite_add_tcase(s, tc);
  return s;
}