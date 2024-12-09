#pragma once

#include "Sequence.h"
#include "DynamicArray.h"

template <typename T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence() : array() {}

    ArraySequence(const T* items, int count) : array(items, count) {}

    explicit ArraySequence(int size) : array(size) {}

    ArraySequence(const DynamicArray<T>& dynamicArray) : array(dynamicArray) {}

    const T& getFirst() const override {
        return array.Get(0);
    }

    const T& getLast() const override {
        return array.Get(array.GetSize() - 1);
    }

    T& get(int index) {
        return array.Get(index);
    }

    const T& get(int index) const override {
        return array.Get(index);
    }

    UnqPtr<Sequence<T>> getSubSequence(int startIndex, int endIndex) override {
        int length = endIndex - startIndex + 1;
        DynamicArray<T> subArray(length);
        for (int i = 0; i < length; ++i) {
            subArray.Set(i, array.Get(startIndex + i));
        }
        return UnqPtr<Sequence<T>>(new ArraySequence<T>(subArray));
    }

    int getLength() const override {
        return array.GetSize();
    }

    void append(const T& item) override {
        insertAt(array.GetSize(), item);
    }

    void prepend(const T& item) override {
        insertAt(0, item);
    }

    void insertAt(int index, const T& item) override {
        if (index < 0 || index > array.GetSize()) {
            throw std::out_of_range("Error: Index is out of range for insertion.");
        }

        int newSize = array.GetSize() + 1;
        array.Resize(newSize);

        for (int i = newSize - 1; i > index; --i) {
            array.Set(i, array.Get(i - 1));
        }

        array.Set(index, item);
    }

    void concat(UnqPtr<Sequence<T>> sequence) override {
        int newSize = array.GetSize() + sequence->getLength();
        array.Resize(newSize);
        for (int i = 0; i < sequence->getLength(); ++i) {
            array.Set(array.GetSize() - sequence->getLength() + i, sequence->get(i));
        }
    }

    Sequence<T>& remove(int index) override {
        CheckIndex(array.GetSize(), index);
        int newSize = array.GetSize() - 1;
        DynamicArray<T> newArray(newSize);
        for (int i = 0; i < index; ++i) {
            newArray.Set(i, array.Get(i));
        }
        for (int i = index + 1; i < array.GetSize(); ++i) {
            newArray.Set(i - 1, array.Get(i));
        }
        array = std::move(newArray);
        return *this;
    }

private:
    DynamicArray<T> array;
};
