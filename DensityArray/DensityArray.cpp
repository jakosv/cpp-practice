#include "DensityArray.h"

DensityArray::DensityArray() {
    head = nullptr;
    lastModifiedItemPtr = &head;
}

DensityArray::~DensityArray() {
    while (head) {
        DensityArray::Item* tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
    lastModifiedItemPtr = &head;
}

void DensityArray::optimizeLastModifiedItemIfDefault() {
    if (!*lastModifiedItemPtr || (*lastModifiedItemPtr)->value != defaultValue)
        return;

    DensityArray::Item* tmp = *lastModifiedItemPtr;
    *lastModifiedItemPtr = (*lastModifiedItemPtr)->next;

    delete tmp;
}

int& DensityArray::operator[](int idx) {
    if (*lastModifiedItemPtr && (*lastModifiedItemPtr)->pos != idx)
        optimizeLastModifiedItemIfDefault();

    DensityArray::Item** foundItemPtr = &head;

    while (*foundItemPtr && (*foundItemPtr)->pos < idx) {
        foundItemPtr = &(*foundItemPtr)->next;
    }

    lastModifiedItemPtr = foundItemPtr;

    if (*foundItemPtr && (*foundItemPtr)->pos == idx)
        return (*foundItemPtr)->value;

    DensityArray::Item* insertedItem = new Item;
    insertedItem->pos = idx;
    insertedItem->value = defaultValue;
    insertedItem->next = *foundItemPtr ? *foundItemPtr : nullptr;
    *foundItemPtr = insertedItem;

    return insertedItem->value;
}

int DensityArray::operator[](int idx) const {
    DensityArray::Item* foundItem = head;

    while (foundItem && foundItem->pos < idx)
        foundItem = foundItem->next; 

    return (foundItem && foundItem->pos == idx)
            ? foundItem->value
            : defaultValue;
}
