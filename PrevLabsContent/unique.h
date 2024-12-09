#pragma once
#include <stdexcept>

template<typename T>
class UnqPtr {
    private: 
        T* ptr;

    public:
        UnqPtr(T* ptr) : ptr(ptr) {}

        // same as move() in unique_ptr
        UnqPtr(UnqPtr&& otherPtr) {
            ptr = otherPtr.ptr;
            otherPtr.ptr = nullptr;
        }

        UnqPtr& operator=(UnqPtr&& otherPtr) noexcept {
            if (this != &otherPtr) { 
                delete ptr;          
                ptr = otherPtr.ptr;
                otherPtr.ptr = nullptr;
            }
            return *this;
        }

        // copy ban
        UnqPtr(const UnqPtr& otherPtr) = delete;
        UnqPtr& operator=(const UnqPtr& otherPtr) = delete;

        ~UnqPtr() {delete ptr;}

        T* operator->() {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return ptr;
        }

        const T* operator->() const {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return ptr;
        }

        T& operator*() {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return *ptr;
        }

        const T& operator*() const {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return *ptr;
        }

        void swap(T*& otherPtr) {
            T* tmpPtr = ptr;
            ptr = otherPtr;
            otherPtr = tmpPtr;
        }

        void reset(T* newPtr = nullptr) {
            if (ptr) {
                delete ptr;
                ptr = nullptr;
            }
            ptr = newPtr;
        }

        T* release() {
            T* tmpPtr = ptr;
            ptr = nullptr;
            return tmpPtr;
        }
        
        T* get() {
            return ptr;
        }

        const T* get() const {
            return ptr;
        }

};

template<typename T>
class UnqPtr<T[]> {
    private:
        T* ptr;

    public:
        UnqPtr(T* ptr = nullptr) : ptr(ptr) {}

        UnqPtr(UnqPtr&& otherPtr) noexcept : ptr(otherPtr.ptr) {
            otherPtr.ptr = nullptr;
        }

        UnqPtr& operator=(UnqPtr&& otherPtr) noexcept {
            if (this != &otherPtr) {
                delete[] ptr;
                ptr = otherPtr.ptr;
                otherPtr.ptr = nullptr;
            }
            return *this;
        }

        UnqPtr(const UnqPtr& otherPtr) = delete;
        UnqPtr& operator=(const UnqPtr& otherPtr) = delete;

        ~UnqPtr() {
            delete[] ptr;
        }

        T& operator[](std::size_t index) {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return ptr[index];
        }

        const T& operator[](std::size_t index) const {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return ptr[index];
        }

        void reset(T* newPtr = nullptr) {
            if (ptr) {
                delete[] ptr;
            }
            ptr = newPtr;
        }

        T* release() {
            T* tmpPtr = ptr;
            ptr = nullptr;
            return tmpPtr;
        }

        T* get() {
            return ptr;
        }

        const T* get() const {
            return ptr;
        }

        void swap(UnqPtr& other) noexcept {
            std::swap(ptr, other.ptr);
        }

        std::size_t size() const {
            throw std::runtime_error("Size calculation not implemented");
        }
};