#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "ABDQ.hpp"

template<typename T>
class ABQ : public QueueInterface<T>{

    ABDQ<T> deque_;

public:
    // Constructors + Big 5
    // No big 5 needed as ABDQ manages its own memory
    ABQ() : deque_() {}
    explicit ABQ(const size_t capacity) : deque_(capacity) {}

    // Getters
    [[nodiscard]] size_t getSize() const noexcept override
    {
        return deque_.getSize();
    }

    // Insertion
    void enqueue(const T& data) override
    {
        deque_.pushBack(data);
    }

    // Access
    T peek() const override
    {
        return deque_.front();
    }

    // Deletion
    T dequeue() override
    {
        return deque_.popFront();
    }
};
