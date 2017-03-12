#ifndef _TEST_SUITES_H_
#define _TEST_SUITES_H_

#include <check.h>

TCase *tcase_brie(void);
TCase *tcase_backstage(void);
TCase *tcase_normal(void);
TCase *tcase_sulfuras(void);

Suite *suite_characterization(void);

#endif
