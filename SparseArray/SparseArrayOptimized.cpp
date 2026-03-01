#include "SparseArrayOptimized.h"

SparseArrayOptimized::SparseArrayOptimized() {
    head = nullptr;
}

SparseArrayOptimized::~SparseArrayOptimized() {
    while (head) {
        Item* tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

SparseArrayOptimized::SparseArrayWrapper
SparseArrayOptimized::operator[](int idx) {
    return SparseArrayOptimized::SparseArrayWrapper(this, idx);
}

int SparseArrayOptimized::operator[](int idx) const {
    Item* foundItem;

    for (foundItem = head; foundItem; foundItem = foundItem->next) {
        if (foundItem->pos == idx)
            return foundItem->value;
    }

    return defaultValue;
}

int& SparseArrayOptimized::SparseArrayWrapper::Provide() {
    Item* foundItem = data->head;

    while (foundItem) {
        if (foundItem->pos == idx)
            return foundItem->value;
        foundItem = foundItem->next;
    }

    Item* insertedItem = new SparseArrayOptimized::Item;
    insertedItem->pos = idx;
    insertedItem->value = defaultValue;
    insertedItem->next = data->head;
    data->head = insertedItem;

    return insertedItem->value;
}

void SparseArrayOptimized::SparseArrayWrapper::Remove() {
    Item** foundItemPtr = &data->head;

    while (*foundItemPtr) {
        if ((*foundItemPtr)->pos == idx)
            break;
        foundItemPtr = &(*foundItemPtr)->next;
    }

    Item* tmp = *foundItemPtr;
    *foundItemPtr = (*foundItemPtr)->next;
    delete tmp;
}

int SparseArrayOptimized::SparseArrayWrapper::operator=(int x) {
    if (x == defaultValue)
        Remove();
    else
        Provide() = x;

    return x;
}

int SparseArrayOptimized::SparseArrayWrapper::operator+=(int x) {
    int& val = Provide();
    val += x;
    int res = val;

    if (res == defaultValue)
        Remove();

    return res;
}

int SparseArrayOptimized::SparseArrayWrapper::operator++() {
    int& val = Provide();
    val++;
    int res = val;

    if (res == defaultValue)
        Remove();

    return res;
}

int SparseArrayOptimized::SparseArrayWrapper::operator++(int) {
    int& val = Provide();
    int res = val;
    val++;

    if (val == defaultValue)
        Remove();

    return res;
}

SparseArrayOptimized::SparseArrayWrapper::operator int() {
    for (Item* tmp = data->head; tmp; tmp = tmp->next) {
        if (tmp->pos == idx)
            return tmp->value;
    }

    return defaultValue;
}
