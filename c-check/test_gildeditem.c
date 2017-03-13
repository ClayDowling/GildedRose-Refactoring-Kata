#include <check.h>
#include "gilded_item.h"

Item testItem;

START_TEST(normalSellIn_byDefault_decreasesQualityByOne)
{
    testItem.quality = 10;
    testItem.sellIn = 7;

    normal_sellIn(&testItem);

    ck_assert_int_eq(testItem.sellIn, 6);
}
END_TEST

START_TEST(normalQuality_byDefault_decreasesQualityByOne)
{
    testItem.quality = 10;
    testItem.sellIn = 7;

    normal_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 9);
}
END_TEST

START_TEST(normalQuality_whenSellInZero_decreasesQualityByTwo)
{
    testItem.quality = 10;
    testItem.sellIn = -1;

    normal_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 8);
}
END_TEST

START_TEST(agedBrieQuality_byDefault_addsOne)
{
    testItem.quality = 10;
    testItem.sellIn = 5;

    agedBrie_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 11);
}
END_TEST

START_TEST(agedBrieQuality_whenFifty_doesNotIncreaseOverFifty)
{
    testItem.quality = 50;
    testItem.sellIn = 7;

    agedBrie_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 50);
}
END_TEST

START_TEST(backStagePass_whenFifteenDays_increasesByOne)
{
    testItem.quality = 10;
    testItem.sellIn = 15;

    backstagePass_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 11);
}
END_TEST

START_TEST(backStagePass_whenTenDays_increasesByTwo)
{
    testItem.quality = 6;
    testItem.sellIn = 10;

    backstagePass_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 8);
}
END_TEST

START_TEST(backStagePass_whenFiveDays_increasesByThree)
{
    testItem.quality = 7;
    testItem.sellIn = 5;

    backstagePass_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 10);
}
END_TEST

START_TEST(backStagePass_whenZeroDays_hasQualityZero)
{
    testItem.quality = 50;
    testItem.sellIn = 0;

    backstagePass_quality(&testItem);

    ck_assert_int_eq(testItem.quality, 0);
}
END_TEST

START_TEST(sulfuras_byDefault_doesNotDecreaseSellIn)
{
    testItem.quality = 80;
    testItem.sellIn = 10;

    sulfuras_sellIn(&testItem);

    ck_assert_int_eq(testItem.sellIn, 10);
}
END_TEST

TCase *tcase_gildeditem(void)
{
    TCase *tc;

    tc = tcase_create("gilded-item");
    tcase_add_test(tc, normalSellIn_byDefault_decreasesQualityByOne);
    tcase_add_test(tc, normalQuality_byDefault_decreasesQualityByOne);
    tcase_add_test(tc, normalQuality_whenSellInZero_decreasesQualityByTwo);
    tcase_add_test(tc, agedBrieQuality_byDefault_addsOne);
    tcase_add_test(tc, agedBrieQuality_whenFifty_doesNotIncreaseOverFifty);
    tcase_add_test(tc, backStagePass_whenFifteenDays_increasesByOne);
    tcase_add_test(tc, backStagePass_whenTenDays_increasesByTwo);
    tcase_add_test(tc, backStagePass_whenFiveDays_increasesByThree);
    tcase_add_test(tc, backStagePass_whenZeroDays_hasQualityZero);
    tcase_add_test(tc, sulfuras_byDefault_doesNotDecreaseSellIn);

    return tc;
}
