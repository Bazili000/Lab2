#pragma once

#include "../PrevLabsContent/ArraySequence.h"
#include "../PrevLabsContent/unique.h"
#include <functional>

template <typename T>
class ISorter {
    public:
        virtual ~ISorter() = default;

        virtual void Sort(UnqPtr<ArraySequence<T>>& seq, std::function<bool(const T&, const T&)> comp) const = 0;
};
