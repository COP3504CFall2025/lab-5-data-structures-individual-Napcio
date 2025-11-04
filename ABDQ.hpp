#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "Interfaces.hpp"
#include <utility>

template <typename T>
class ABDQ : public DequeInterface<T> {
private:
    T* data_ = nullptr;         // underlying dynamic array
    std::size_t capacity_ = 0;  // total allocated capacity
    std::size_t size_ = 0;      // number of stored elements
    std::size_t front_ = 0;     // index of front element
    std::size_t back_ = 0;      // index after the last element (circular)

    static constexpr std::size_t SCALE_FACTOR = 2;

    // Passing a negative index gets the element before front
    size_t toRawIndex(int index)
    {
        int wrappedIndex = (static_cast<int>(front_) + index) % static_cast<int>(capacity_);
        return wrappedIndex < 0 ? capacity_ + wrappedIndex : wrappedIndex;
    }

    // Sets the size of the array, adjusting capacity and reallocating data_ as necessary
    void adjustSize(std::size_t newSize)
    {
        if (newSize > capacity_)
        { // Resize data_
            std::size_t newCapacity = std::max<std::size_t>(1, capacity_);
            while (newCapacity < newSize)
            {
                newCapacity *= 2;
            }
            T* newData = new T[newCapacity];
            for (std::size_t i = 0; i < size_; i++) // size_ still has the size of the old data_
            {
                size_t rawIndex = toRawIndex(i); // on a separate line for debugging purposes
                newData[i] = std::move(data_[rawIndex]);
            }

            delete[] data_;
            data_ = newData;

            // Set after transfer so that we can still index the old data_ correctly when transferring data
            capacity_ = newCapacity;
            front_ = 0;
            back_ = size_ - 1;
        }
        size_ = newSize;
    }

    // MAKE SURE someone else is managing data_'s memory
    void nullSelf()
    {
        data_ = nullptr;
        capacity_ = 0;
        size_ = 0;
        front_ = 0;
        back_ = 0;
    }

public:
    // Big 5
    ABDQ()
    {
        ABDQ(1);
    }
    explicit ABDQ(std::size_t capacity) : capacity_(capacity)
    {
        data_ = new T[capacity];
    }
    ABDQ(const ABDQ& other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        front_ = other.front_;
        back_ = other.back_;

        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++)
        {
            data_[toRawIndex(i)] = other.data_[toRawIndex(i)];
        }
    }
    ABDQ(ABDQ&& other) noexcept
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        front_ = other.front_;
        back_ = other.back_;

        data_ = other.data_;
        other.nullSelf();
    }
    ABDQ& operator=(const ABDQ& other)
    {
        if (this == &other)
            return *this;
        size_ = other.size_;
        capacity_ = other.capacity_;
        front_ = other.front_;
        back_ = other.back_;

        T* tempData = new T[capacity_];
        delete[] data_;
        data_ = tempData;
        for (size_t i = 0; i < size_; i++)
        {
            data_[toRawIndex(i)] = other.data_[toRawIndex(i)];
        }

        return *this;
    }
    ABDQ& operator=(ABDQ&& other) noexcept
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        front_ = other.front_;
        back_ = other.back_;

        delete[] data_;
        data_ = other.data_;
        other.nullSelf();

        return *this;
    }
    ~ABDQ() override
    {
        delete[] data_;
        data_ = nullptr;
    }

    // Insertion
    void pushFront(const T& item) override
    {
        bool isFirstPush = (size_ == 0);
        adjustSize(size_ + 1);
        front_ = isFirstPush ? 0 : toRawIndex(front_ - 1);
        data_[front_] = item;
    }
    void pushBack(const T& item) override
    {
        bool isFirstPush = (size_ == 0);
        adjustSize(size_ + 1);
        // If we have allocated the array for the first time, we ignore the current value of back
        back_ = isFirstPush ? 0 : toRawIndex(back_ + 1);
        data_[back_] = item;
    };

    // Deletion
    T popFront() override
    {
        if (size_ < 1)
        {
            throw std::runtime_error("Container is empty");
        }
        T temp = data_[front_];
        front_ = toRawIndex(1); // Evaluates to the next element forward
        adjustSize(size_ - 1);
        return temp;
    }
    T popBack() override
    {
        if (size_ < 1)
        {
            throw std::runtime_error("Container is empty");
        }
        T temp = data_[back_];
        back_ = toRawIndex(back_ - 1 - front_); // Evaluates to back - 1 but wrapped correctly
        adjustSize(size_ - 1);
        return temp;
    }

    // Access
    const T& front() const override
    {
        if (size_ < 1)
        {
            throw std::runtime_error("Container is empty");
        }
        return data_[front_];
    }
    const T& back() const override
    {
        if (size_ < 1)
        {
            throw std::runtime_error("Container is empty");
        }
        return data_[back_];
    }

    // Getters
    [[nodiscard]] std::size_t getSize() const noexcept override
    {
        return size_;
    }
    [[nodiscard]] std::size_t getMaxCapacity() const noexcept
    {
        return capacity_;
    }

    // Debugging function
    void printData()
    {
        std::cout << "-----" << "\n"
            << "front: " << front_ << "\n"
            << "back: " << back_ << "\n";
        for (size_t i = 0; i < capacity_; i++)
        {
            std::cout << data_[i] << "  ";
        }
        std::cout << std::endl;
    }
};
