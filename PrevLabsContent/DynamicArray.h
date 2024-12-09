#pragma once

#include <algorithm>
#include "IndexChecker.h"
#include "unique.h"

template <typename T>
class DynamicArray {
public:
    DynamicArray() : size(0) {}

    DynamicArray(const T* items, int count) 
        : size(count), data(new T[count]) {
        std::copy(items, items + count, data.get());
    }

    explicit DynamicArray(int size) 
        : size(size), data(new T[size]) {}

    DynamicArray(const DynamicArray<T>& dynamicArray)
        : size(dynamicArray.size), data(new T[dynamicArray.size]) {
        std::copy(dynamicArray.data.get(), dynamicArray.data.get() + size, data.get());
    }

    DynamicArray<T>& operator=(const DynamicArray<T>& dynamicArray) {
        if (this != &dynamicArray) {
            size = dynamicArray.size;
            data = UnqPtr<T[]>(new T[size]);
            std::copy(dynamicArray.data.get(), dynamicArray.data.get() + size, data.get());
        }
        return *this;
    }
    
    T& Get(int index) {
        CheckIndex(size, index);
        return data[index];
    }
    const T& Get(int index) const {
        CheckIndex(size, index);
        return data[index];
    }

    int GetSize() const { return size; }

    void Set(int index, const T& value) {
        CheckIndex(size, index);
        data[index] = value;
    }

    void Resize(int newSize) {
        UnqPtr<T[]> newData(new T[newSize]);
        int elemSize = std::min(size, newSize);
        std::copy(data.get(), data.get() + elemSize, newData.get());
        data = std::move(newData);
        size = newSize;
    }

private:
    UnqPtr<T[]> data;
    int size;
};
