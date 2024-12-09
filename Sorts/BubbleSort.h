#pragma once

#include "ISorter.h"
#include <functional>

template <typename T>
class BubbleSorter : public ISorter<T> {
public:
    void Sort(UnqPtr<ArraySequence<T>>& seq, std::function<bool(const T&, const T&)> comp) const override {

        int length = seq->getLength();

        for (int i = 0; i < length - 1; ++i) {
            for (int j = 0; j < length - i - 1; ++j) {
                if (comp(seq->get(j + 1), seq->get(j))) {
                    std::swap(seq->get(j), seq->get(j + 1));
                }
            }
        }
    }
};
