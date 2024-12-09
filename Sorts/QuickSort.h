#pragma once

#include <functional>
#include "ISorter.h"

template<typename T>
class QuickSorter : public ISorter<T> {
public:
    void Sort(UnqPtr<ArraySequence<T>>& seq, std::function<bool(const T&, const T&)> cmp) const override {
        QuickSortRecursive(seq, 0, seq->getLength() - 1, cmp);
    }

private:
    void QuickSortRecursive(UnqPtr<ArraySequence<T>>& seq, int low, int high, std::function<bool(const T&, const T&)> cmp) const {
        if (low < high) {
            int pivotIndex = Partition(seq, low, high, cmp);
            QuickSortRecursive(seq, low, pivotIndex - 1, cmp);
            QuickSortRecursive(seq, pivotIndex + 1, high, cmp);
        }
    }

    int Partition(UnqPtr<ArraySequence<T>>& seq, int low, int high, std::function<bool(const T&, const T&)> cmp) const {
        T pivot = seq->get(high);
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (cmp(seq->get(j), pivot)) {
                ++i;
                std::swap(seq->get(i), seq->get(j));
            }
        }
        std::swap(seq->get(i + 1), seq->get(high));
        return i + 1;
    }
};
