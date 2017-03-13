#ifndef _GILDED_ITEM_H_
#define _GILDED_ITEM_H_

#include "GildedRose.h"

typedef struct {
  Item *item;

  void (*sellInFunction)(Item*);
  void (*qualityFunction)(Item*);
} ItemWrapper;

void normal_sellIn(Item*);
void normal_quality(Item*);

void agedBrie_quality(Item*);

void backstagePass_quality(Item*);

void sulfuras_sellIn(Item*);

#endif
