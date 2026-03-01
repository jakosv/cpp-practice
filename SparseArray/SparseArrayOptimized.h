#ifndef SPARSE_ARRAY_H
#define SPARSE_ARRAY_H

class SparseArrayOptimized {
    struct Item {
        int pos;
        int value;
        struct Item *next;
    };

    static const int defaultValue = 0;

    struct Item *head;

    // forbid copy and assignment
    SparseArrayOptimized(const SparseArrayOptimized& other);
    void operator=(const SparseArrayOptimized& other);

    void optimizeLastModifiedItemIfDefault();

    class SparseArrayWrapper {
        SparseArrayOptimized *data;
        int idx;

        int& Provide();
        void Remove();

    public:
        SparseArrayWrapper(SparseArrayOptimized *a_data, int a_idx)
            : data(a_data), idx(a_idx) {}
        operator int();
        int operator=(int x); 
        int operator+=(int x);
        int operator++();
        int operator++(int);
    };

public:
    SparseArrayOptimized();
    ~SparseArrayOptimized();
    SparseArrayWrapper operator[](int idx);
    int operator[](int idx) const;
};

#endif
