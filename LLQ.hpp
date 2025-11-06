#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cassert>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLQ() = default;

    // Insertion
    void enqueue(const T& item) override
    {
        list.addTail(item);
    }

    // Deletion
    T dequeue() override
    {
        return list.popHead();
    }

    // Access
    T peek() const override
    {
        if (list.getSize() < 1)
        {
            throw std::runtime_error("Container is empty");
        }
        assert(((list.getHead() == nullptr) == (list.getSize() == 0)));
        return list.getHead()->data;
    }

    // Getter
    [[nodiscard]] std::size_t getSize() const noexcept override
    {
        return list.getSize();
    }

};