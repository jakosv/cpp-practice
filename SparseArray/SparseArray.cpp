#include "SparseArray.h"

SparseArray::SparseArray() {
    head = nullptr;
    lastModifiedItemPtr = &head;
}

SparseArray::~SparseArray() {
    while (head) {
        SparseArray::Item* tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
    lastModifiedItemPtr = &head;
}

void SparseArray::optimizeLastModifiedItemIfDefault() {
    if (!*lastModifiedItemPtr || (*lastModifiedItemPtr)->value != defaultValue)
        return;

    SparseArray::Item* tmp = *lastModifiedItemPtr;
    *lastModifiedItemPtr = (*lastModifiedItemPtr)->next;

    delete tmp;
}

int& SparseArray::operator[](int idx) {
    if (*lastModifiedItemPtr && (*lastModifiedItemPtr)->pos != idx)
        optimizeLastModifiedItemIfDefault();

    SparseArray::Item** foundItemPtr = &head;

    while (*foundItemPtr && (*foundItemPtr)->pos < idx) {
        foundItemPtr = &(*foundItemPtr)->next;
    }

    lastModifiedItemPtr = foundItemPtr;

    if (*foundItemPtr && (*foundItemPtr)->pos == idx)
        return (*foundItemPtr)->value;

    SparseArray::Item* insertedItem = new Item;
    insertedItem->pos = idx;
    insertedItem->value = defaultValue;
    insertedItem->next = *foundItemPtr ? *foundItemPtr : nullptr;
    *foundItemPtr = insertedItem;

    return insertedItem->value;
}

int SparseArray::operator[](int idx) const {
    SparseArray::Item* foundItem;

    for (foundItem = head; foundItem; foundItem = foundItem->next) {
        if (foundItem->pos == idx)
            return foundItem->value;
    }

    return defaultValue;
}
