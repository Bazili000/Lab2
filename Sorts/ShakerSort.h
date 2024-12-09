#pragma once

#include "ISorter.h"
#include <functional>

template <typename T>
class ShakerSorter : public ISorter<T> {
public:
    void Sort(UnqPtr<ArraySequence<T>>& seq, std::function<bool(const T&, const T&)> comp) const override {

        int left = 0;
        int right = seq->getLength() - 1;

        while (left < right) {
            for (int i = left; i < right; ++i) {
                if (comp(seq->get(i + 1), seq->get(i))) {
                    std::swap(seq->get(i), seq->get(i + 1));
                }
            }
            --right;

            for (int i = right; i > left; --i) {
                if (comp(seq->get(i), seq->get(i - 1))) {
                    std::swap(seq->get(i), seq->get(i - 1));
                }
            }
            ++left;
        }
    }
};
