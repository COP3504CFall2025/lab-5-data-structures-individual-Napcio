#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLS() = default;

    // Insertion
    void push(const T& item) override
    {
        list.addTail(item);
    }

    // Deletion
    T pop() override
    {
        return list.popTail();
    }

    // Access
    T peek() const override
    {
        return list.getTail()->data;
    }

    //Getters
    std::size_t getSize() const noexcept override
    {
        return list.getSize();
    }
};