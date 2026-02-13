#ifndef DENSITY_ARRAY_H
#define DENSITY_ARRAY_H

class DensityArray {
    struct Item {
        int pos;
        int value;
        struct Item *next;
    };

    static const int defaultValue = 0;

    struct Item *head;
    struct Item **lastModifiedItemPtr;

    // forbid copy and assignment
    DensityArray(const DensityArray& other);
    void operator=(const DensityArray& other);

    void optimizeLastModifiedItemIfDefault();

public:
    DensityArray();
    ~DensityArray();
    int& operator[](int idx);
    int operator[](int idx) const;
};

#endif
