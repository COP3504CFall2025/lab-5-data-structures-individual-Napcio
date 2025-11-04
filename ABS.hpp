#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "ABDQ.hpp"


template<typename T>
class ABS : public StackInterface<T> {
    ABDQ<T> deque_;
public:
    // Big 5 + Parameterized Constructor
    ABS() : deque_() {}
    explicit ABS(const size_t capacity) : deque_(capacity) {}


    // Get the number of items in the ABS
    [[nodiscard]] size_t getSize() const noexcept override
    {
        return deque_.getSize();
    }

    // Push item onto the stack
    void push(const T& data) override
    {
        deque_.pushBack(data);
    }

    T peek() const override
    {
        return deque_.back();
    }

    T pop() override
    {
        return deque_.popBack();
    }
};

