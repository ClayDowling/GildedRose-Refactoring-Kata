#include "gilded_item.h"

void normal_sellIn(Item* item)
{
    item->sellIn -= 1;
}

void sulfuras_sellIn(Item *item)
{
    // NOOP
}

void normal_quality(Item* item)
{
    if (item->sellIn > 0) {
        item->quality -= 1;
    } else {
        item->quality -= 2;
    }
}

void agedBrie_quality(Item* item)
{
    if (item->quality < 50) {
        item->quality++;
    }
}

void backstagePass_quality(Item *item)
{
    if (item->sellIn <= 0) {
        item->quality = 0;
    } else if (item->sellIn <= 5) {
        item->quality += 3;
    } else if (item->sellIn <= 10) {
        item->quality += 2;
    }else {
        item->quality++;
    }
}

