#pragma once

#include <iostream>
#include "../Randomizer.h"
#include "../Sorts/QuickSort.h"
#include "../Sorts/ShakerSort.h"
#include "../Sorts/BubbleSort.h"
#include "../GUI.h"
#include "../PrevLabsContent/ArraySequence.h"
#include "../PrevLabsContent/unique.h"
#include "OutputManager.h"

template <typename T>
bool isSorted(const UnqPtr<ArraySequence<T>>& arr, const std::function<bool(const T&, const T&)>& comp) {
    for (int i = 1; i < arr->getLength(); i++) {
        if (comp(arr->get(i), arr->get(i - 1))) {
            return false;
        }
    }
    return true;
}

template <typename T>
void RunTest(
    ISorter<T>& sorter,
    const std::string& sorterName,
    int dataSize,
    TestOutput& output,
    const std::function<bool(const T&, const T&)>& comp,
    void (*generate)(T*, int)
){
    std::vector<T> arr(dataSize);
    generate(arr.data(), dataSize);
    UnqPtr<ArraySequence<T>> seq(new ArraySequence<T>(arr.data(), dataSize));

    sorter.Sort(seq, comp);

    output << (isSorted(seq, comp) ? "[PASS] " : "[FAIL] ") << sorterName << "";
}

void RunFuncTests(TestOutput& output);
