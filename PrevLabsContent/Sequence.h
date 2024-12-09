#pragma once

#include "unique.h"

template<typename T>
class Sequence {
    public:
        virtual const T &get(int index) const = 0;

        virtual const T &getFirst() const = 0;

        virtual const T &getLast() const = 0;

        virtual UnqPtr<Sequence<T>> getSubSequence(int startIndex, int endIndex) = 0;

        virtual int getLength() const = 0;

        virtual void append(const T &item) = 0;

        virtual void prepend(const T &item) = 0;

        virtual void insertAt(int index, const T &item) = 0;

        virtual void concat(UnqPtr<Sequence<T>> sequence) = 0;

        virtual Sequence<T> &remove(int index) = 0;
};