
#include "test_suites.h"

Suite *suite_characterization(void)
{
  Suite *s;

  s = suite_create("characterization-tests");
  suite_add_tcase(s, tcase_normal());
  suite_add_tcase(s, tcase_brie());
  suite_add_tcase(s, tcase_backstage());
  suite_add_tcase(s, tcase_sulfuras());

  return s;
}
