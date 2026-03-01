#ifndef SPARSE_ARRAY_H
#define SPARSE_ARRAY_H

class SparseArray {
    struct Item {
        int pos;
        int value;
        struct Item *next;
    };

    static const int defaultValue = 0;

    struct Item *head;
    struct Item **lastModifiedItemPtr;

    // forbid copy and assignment
    SparseArray(const SparseArray& other);
    void operator=(const SparseArray& other);

    void optimizeLastModifiedItemIfDefault();

public:
    SparseArray();
    ~SparseArray();
    int& operator[](int idx);
    int operator[](int idx) const;
};

#endif
