#include <check.h>
#include "GildedRose.h"

#define SULFURAS "Sulfuras, Hand of Ragnaros"

START_TEST(sulfuras_at10days_doesNotDecrease)
{
    Item items[1];
    init_item(items, SULFURAS, 10, 80);
    update_quality(items, 1);

    ck_assert_int_eq(80, items[0].quality);
}
END_TEST

START_TEST(sufuras_at10Days_willNotChangeFromStartingValue)
{
  Item items[1];
  init_item(items, SULFURAS, 10, 60);
  update_quality(items, 1);

  ck_assert_int_eq(60, items[0].quality);
}
END_TEST

START_TEST(sufuras_atNegativeDays_willNotChangeFromStartingValue)
{
  Item items[1];
  init_item(items, SULFURAS, -1, 60);
  update_quality(items, 1);

  ck_assert_int_eq(60, items[0].quality);
}
END_TEST

START_TEST(sulfuras_byDefault_doesNotDecreasesSellInByOneEachDay)
{
  Item items[1];
  init_item(items, SULFURAS, 5, 60);
  update_quality(items, 1);

  ck_assert_int_eq(5, items[0].sellIn);
}
END_TEST

TCase *tcase_sulfuras(void)
{
  TCase *tc = tcase_create("sulfuras");

  tcase_add_test(tc, sulfuras_at10days_doesNotDecrease);
  tcase_add_test(tc, sufuras_at10Days_willNotChangeFromStartingValue);
  tcase_add_test(tc, sufuras_atNegativeDays_willNotChangeFromStartingValue);
  tcase_add_test(tc, sulfuras_byDefault_doesNotDecreasesSellInByOneEachDay);

  return tc;
}
